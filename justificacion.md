# Justificación de órdenes — Obligatorio 1

> **Instrucciones** (borrar esta sección antes de entregar): para cada ejercicio cuya
> letra plantea restricciones de órdenes (tiempo o espacio), justificar brevemente por
> qué la solución cumple, indicando qué estructuras de datos o algoritmos se utilizaron.
> Ejemplo: "La letra exige inserción en O(log n); usamos un min-heap sobre arreglo,
> donde flotar/hundir recorren a lo sumo la altura del árbol". Si un ejercicio no tiene
> restricciones de órdenes, indicarlo.

## Ejercicio 1

- Sin restricciones de órdenes. / Justificación:

## Ejercicio 2

- Sin restricciones de órdenes. / Justificación: ...

## Ejercicio 3

- O(Nlog(N)) / Justificación: tenemos un for de N iteraciones, a cada iteración realiza la operacion insertar(), que es log(N) porque usa flotar() a lo sumo log(N) veces, puesto que flotar() divide a la mitad el array sucesivamente. El bloque que contiene el while es análogo, el while hace N iteraciones y en cada una ejecuta fusionar(), cuyo orden es log(N) porque usa insertar(). El orden total del algoritmo es la suma de esos dos bloques: 2(Nlog(N)), que se reduce a O(Nlog(N)).

## Ejercicio 4

- Sin restricciones de órdenes. / Justificación: ...

## Ejercicio 5

- Sin restricciones de órdenes. / Justificación: ...
