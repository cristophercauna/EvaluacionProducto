param(
  [string]$Exe = ".\main.exe",
  [int]$Reps = 3,
  [int[]]$Sizes = @(1000,10000,100000)
)

$ErrorActionPreference = "Stop"

# Crear carpeta results y limpiar metricas.csv
New-Item -ItemType Directory -Force -Path ".\results" | Out-Null
if (Test-Path ".\metricas.csv") { Remove-Item ".\metricas.csv" -Force }

Write-Host ("Running {0} with {1} reps for: {2}" -f $Exe, $Reps, ($Sizes -join ", "))

foreach ($n in $Sizes) {
  Write-Host ("=== n = {0} ===" -f $n)
  for ($r = 1; $r -le $Reps; $r++) {
    "$n" | & $Exe | Out-Null
    Write-Host ("  rep {0} OK" -f $r)
  }
}

Write-Host "Finished. Check 'metricas.csv' and folder 'results/'."