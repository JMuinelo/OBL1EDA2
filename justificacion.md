# Justificación de órdenes — Obligatorio 1


## Ejercicio 1

- ALTA y BUSCAR en O(logK)/ Justificación: Bajo por una sola rama, puedo bajar a lo sumo logK veces. A lo sumo logK rotaciones, que son O(1). En total queda O(logK).
- RANGO en O(logK+R)/ Justificacion: bajo por una rama , a lo sumo logK, para llegar al comienzo del rango. Luego recorro R elementos. En total es O(logK) + O(R) = O(logK + R).

## Ejercicio 2

- Ultima Linea en O(1) peor caso. / Justificación: maxEnCajon y cajonesDistintos tienen gets que devuelven sus valores en O(1), porque los vamos actualizando segun insertamos elementos.
- Registrar y consultar en O(L) promedio: Justificacion: La clave se crea en O(L), se hashea en O(L) porque recorre todas sus letras y luego se compara una vez (aproximadamente, en caso ideal) con otros elementos en el bucket. El total es O(L).

## Ejercicio 3

- O(Nlog(N)) / Justificación: tenemos un for de N iteraciones, a cada iteración realiza la operacion insertar(), que es log(N) porque usa flotar() a lo sumo log(N) veces, puesto que flotar() divide a la mitad el array sucesivamente. El bloque que contiene el while es análogo, el while hace N iteraciones y en cada una ejecuta fusionar(), cuyo orden es log(N) porque usa insertar(). El orden total del algoritmo es la suma de esos dos bloques: 2(Nlog(N)), que se reduce a O(Nlog(N)).

## Ejercicio 4

- O((V+A)logV) Temporal/ Justificación: El orden del main es la suma de 2 for (que realizan V y A iteraciones respectivamente) más el orden de Kahn(). El orden de Kahn está determinado por tres partes: 
    - calcular los grados de entrada, que recorre los V listos y sus A nodos en total en O(V + A); 
    - las operaciones del heap, donde cada vértice se inserta y se elimina a lo sumo una vez O(V log V); 
    - el recorrido de las listas de adyacencia, donde cada arista se examina una sola vez, O(A) en total
    
Entonces Kahn es O(V + A + V log V), y como el main suma O(V + A) de lecturas y creación de estructuras, el total es O(V + A + V log V), que resulta en O(A + VlogV).

- O(V+A) Espacial/ Justificación: prioridades, dependencias, ordenTopologico, grados y el heap son O(V). La lista de adyacencia que representa al grafo es O(A), hay un nodo por arista. En total es O(V+A).

## Ejercicio 5

- O(ElogE). / Justificación: Las operaciones del MFSET son aproximadamente (no exacto) O(1) gracias a las optimizaciones. Por ello el orden total de Kruskal termina siendo el orden de insertar E aristas en el heap, cada una cuesta O(logE) (costo de inserción en heap), El total es O(2*ElogE). 2 veces entre insertar y extraer del heap. En total es O(ElogE).
- O(V+A) Espacial/ Justificación: El minHeap es O(V) y el MFSet es O(A), en total O(V+A).
