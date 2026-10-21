# Bitácora — Obligatorio 1

**Integrantes:** Bruno Alfaro (349617), Juan Muinelo (350499)

## 2026-09-12 — JM
- Comencé tratando de pensar la estructura del primer ejercicio, me tranqué pensando en crear una funcion ALTA genérica que reciba un tipo T (con template), consulté con CGPT y decidí hacer una función más rústica que chequeé el tipo con ifs.
- Tomamos la decisión de usar la clase AVL vista en clase, modificando unicamente el tipo int para que sea genérica usando template. Revisé que insertar() no agregara elementos duplicados como pide el ejercicio.
-Finalmente entendí que la función BUSCAR iba a precisar un método para buscar en el AVL, así que ya lo agregué al TAD.

## 2026-09-18 - JM, BA
- Tuvimos problemas con hacer el trabajo dentro de Ubuntu (sobretodo el repositorio), asi que decidimos migrar el proyecto a windows.
- Terminamos la funcion BUSCAR y RANGO; consultamos con chatgpt y nos recordó que teniamos que pasar los AVL por referencia y no por copia, corregimos eso. Creamos el método rango() del AVL para poder hacer RANGO, el algoritmo no fue complicado, ya se habia visto en EDA1. Falta Probar que todo este correcto.

## 2026-10-02 - JM, BA
- Comenzamos el Ej 2, implementamos el hash. Tuvimos problemas para pensar la función de hash y entender el enunciado que resultaba un poco confuso por el uso de la palabra "clave" que coincide con la clave del hash.
- Terminamos el Ejercicio, tuvimos que consultar con IA sobre el factor de carga, pero se solucionó facil.

## 2026-10-09 - JM, BA
- Ej 3:
- Tomamos la estructura del minHeap que usamos en clase, la modificamos ligeramente para que soporte datos de tipo long long en lugar de int. También creamos dos funciones nuevas, getCantidad() y fusionar() (fusionar toma los dos elementos de arriba del heap, los suma, vuelve a meter la suma al heap y tmb la retorna).
- La lógica del ejercicio fue simple, cargamos el heap con los datos dados y luego ejecutamos fusionar() dentro de un while para fusionar todos y guardar la suma en una variable para luego mostrarla.

## 2026-10-14 - JM
- Adelanté la creación del TAD heap y grafo para el ejercicio 4, no conseguí terminar todo pero quedó encaminado.
- Tuve problemas a la hora de pensar la implementación de este ejercicio, me mezclé pensando en nodoGrafo o si almacenar structs de tipo Modulo que contuvieran el número y la prioridad, fnalmente me decanté por simplificar todo hasta llegar a la estructura final que estamos entregando.

## 2026-10-16 - JM, BA
- Terminamos juntos el algoritmo de Kahn, y pensamos la estructura del main.
- A la hora de compilar tuvimos problemas con el archivo heap.h, con esa vinculación nos asistió Claude.
- Nos dimos cuenta de que nuestro codigo no cumplía la restriccion O((V+A)logV) por la funcion obtenerVecinos()(antes devolvía un array), así que la cambiamos y con ello la logica de kahn


## 2026-10-21 - JM, BA
- Implementamos MFSet con ayuda de claude para las optimizaciones.
- Modificamos nuevamente el minHeap para que soportara aristas (usar un template no habria funcionado porque habia que cambiar la funcion menor().)
- Implementamos Kruskal, el resto del main era sencillo.
- Terminamos los detalles de justifiación y autoría.
