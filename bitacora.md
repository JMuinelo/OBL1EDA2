# Bitácora — Obligatorio 1

**Integrantes:** Nombre Apellido (Nº estudiante), Nombre Apellido (Nº estudiante)

> **Instrucciones** (borrar esta sección antes de entregar): agregar una entrada por
> cada día trabajado, indicando la fecha y quién trabajó (un integrante o "En conjunto").
> Registrar el proceso real: ideas exploradas, decisiones y su justificación, partes de
> implementaciones, bugs encontrados y cómo se corrigieron, resultados de pruebas y dudas
> abiertas. Si se usó IA ese día, indicar herramienta, consulta y qué se hizo con la
> respuesta. Una bitácora escrita íntegramente el día de la entrega implica pérdida de puntos.

## AAAA-MM-DD — Nombre
- Ejemplo: Leí la letra del ejercicio 1. Primera idea: ... pero la restricción de
  complejidad pide ..., así que ...

## AAAA-MM-DD — En conjunto
- Ejemplo: Implementamos ... Bug: ... Lo corregimos ...
- Pasan los casos de prueba 1 a 4 del ejercicio 1.

## 2026-09-12 — JM
- Comencé tratando de pensar la estructura del primer ejercicio, me tranqué pensando en crear una funcion ALTA genérica que reciba un tipo T (con template), consulté con CGPT y decidí hacer una función más rústica que chequeé el tipo con ifs.
- Tomamos la decisión de usar la clase AVL vista en clase, modificando unicamente el tipo int para que sea genérica usando template. Revisé que insertar() no agregara elementos duplicados como pide el ejercicio.
-Finalmente entendí que la función BUSCAR iba a precisar un método para buscar en el AVL, así que ya lo agregué al TAD.

## 2026-09-18 - JM, BA
- Tuvimos problemas con hacer el trabajo dentro de Ubuntu (sobretodo el repositorio), asi que decidimos migrar el proyecto a windows.
- Terminamos la funcion BUSCAR y RANGO; consultamos con chatgpt y nos recordó que teniamos que pasar los AVL por referencia y no por copia, corregimos eso. Creamos el método rango() del AVL para poder hacer RANGO, el algoritmo no fue complicado, ya se habia visto en EDA1. Falta Probar que todo este correcto.