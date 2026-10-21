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

- O((V+A)logV) Temporal/ Justificación: El orden del main es la suma de 2 for (que realizan V y A iteraciones respecetivamente) más el orden de khan(). El orden de Kahn está determinado

// O((V+A)logV) Temporal/ Justificación: El orden del main es la suma de 2 for (que realizan V y A iteraciones respectivamente) más el orden de Kahn(). El orden de Kahn está determinado por tres partes: calcular los grados de entrada, que recorre los V listos y sus A nodos en total en O(V + A); las operaciones del heap, donde cada vértice se inserta y se elimina a lo sumo una vez O(V log V); y el recorrido de las listas de adyacencia, donde cada arista se examina una sola vez, O(A) en total. Entonces Kahn es O(V + A + V log V), y como el main suma O(V + A) de lecturas y creación de estructuras, el total es O(V + A + V log V), que resulta en O(A + VlogV) .
- O(V+A) Espacial/ Justificación: ...

## Ejercicio 5

- Sin restricciones de órdenes. / Justificación: ...
