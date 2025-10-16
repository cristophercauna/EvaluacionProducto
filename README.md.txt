# Evaluación de Proyecto — Benchmark de Algoritmos de Ordenamiento

##  Objetivo
El objetivo de este proyecto es comparar el rendimiento de distintos algoritmos de ordenamiento (QuickSort y HeapSort), midiendo el número de comparaciones, intercambios y el tiempo de ejecución.  
Se busca analizar su eficiencia empírica con diferentes tamaños de entrada.

---

##  Descripción General
El código implementa dos algoritmos:
- **QuickSort**: versión optimizada con control de recursión por tamaño de subarreglo.
- **HeapSort**: versión clásica basada en estructura de montículo.

Ambos registran métricas como:
- Número de comparaciones
- Número de intercambios
- Tiempo total de ejecución (en microsegundos)

---
**Como compilar
en Bash
 g++ -std=c++11 main.cpp heapsort.cpp quickSort.cpp -o evaluacion.exe
