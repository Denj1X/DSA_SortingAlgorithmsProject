# DSA_SortingAlgorithmsProject
Salut! Numele meu este Biciușcă Matei-Alexandru și acesta este proiectul de algoritmi de sortare pentru Structuri de Date.
În cadrul proiectului vom prezenta și compara diverse sortări și timpii lor de rulare pe diferite input-uri.
Au fost implementate următoarele implementări:
  - Sortarea din STL (nu se află în cerința de sortări implementate obligatorii, dar e folosită pe post de suport, pentru a o compara cu sortările cerute)
  - HeapSort
  - MergeSort
  - RadixSort (de tip LSD, în bazele 10, 2^8, 2^10 și 2^16)
  - ShellSort, unde avem 5 gap sequence
    - gap standard (n/2, n/4/, ..., 2, 1, explicat de Donald Shell)
    - gap bazat pe șirul lui Marcin Ciura
    - gap bazat pe șirul lui Hibbard
    - gap bazat pe șirul lui Tokuda
    - gap bazat pe șirul lui Sedgewick, apărut în 1982
  - BubbleSort
  În input.txt avem pe prima linie numărul de teste, N, în cazul nostru 8,iar pe următoarele N linii avem perechi de tipul (n, max), unde n este numărul de elemente pentru vectorul ce urmează a fi sortat, iar max este practic cea mai mare valoare pe care un element din vector îl poate lua.
  În cadrul proiectului m-am folosit de 8 teste care puneau valori randomizate, cu n și max încadrându-se în tipul de date int.
