# split_metrics.ps1
# Separa metricas.csv (delimitado por ;) en CSVs por escenario dentro de .\results\

$ErrorActionPreference = "Stop"

# Verifica que exista metricas.csv en la carpeta actual
if (-not (Test-Path ".\metricas.csv")) {
  Write-Host "No se encontró 'metricas.csv' en la carpeta actual." -ForegroundColor Yellow
  Write-Host "Ejecuta antes tu benchmark (benchmark.ps1) para generarlo."
  exit 1
}

# Asegura carpeta results
New-Item -ItemType Directory -Force -Path ".\results" | Out-Null

# Carga filas (omite encabezado)
$rows = Import-Csv ".\metricas.csv" -Delimiter ';'

# Inicializa archivos destino con encabezado igual al original
$destFiles = @(
  "benchmark_random.csv",
  "benchmark_ascending.csv",
  "benchmark_descending.csv",
  "benchmark_nearly.csv",
  "benchmark_duplicates.csv"
)
foreach ($f in $destFiles) {
  "escenario;algoritmo;ms;us;ns;comparaciones;intercambios;n;semilla" |
    Set-Content -Encoding UTF8 ".\results\$f"
}

# Función para escribir una fila en un archivo
function Add-Row {
  param($file, $r)
  $line = "{0};{1};{2};{3};{4};{5};{6};{7};{8}" -f `
          $r.escenario, $r.algoritmo, $r.ms, $r.us, $r.ns, `
          $r.comparaciones, $r.intercambios, $r.n, $r.semilla
  Add-Content -Encoding UTF8 -Path ".\results\$file" -Value $line
}

# Mapeo por escenario (acepta variantes de "Casi ordenado")
[int]$count = 0
foreach ($r in $rows) {
  $esc = $r.escenario
  if ($esc -eq "Aleatorio")                { Add-Row "benchmark_random.csv"     $r; $count++ ; continue }
  if ($esc -eq "Ascendente")               { Add-Row "benchmark_ascending.csv"  $r; $count++ ; continue }
  if ($esc -eq "Descendente")              { Add-Row "benchmark_descending.csv" $r; $count++ ; continue }
  if ($esc -match "^Casi ordenado")        { Add-Row "benchmark_nearly.csv"     $r; $count++ ; continue } # "Casi ordenado" o "Casi ordenado (5%)"
  if ($esc -eq "Duplicados")               { Add-Row "benchmark_duplicates.csv" $r; $count++ ; continue }
  # Si llega aquí, el escenario no coincide:
  Write-Host ("[Aviso] Escenario no reconocido: '{0}'" -f $esc) -ForegroundColor Yellow
}

Write-Host ("Listo. {0} filas distribuidas en '.\results\'." -f $count) -ForegroundColor Green