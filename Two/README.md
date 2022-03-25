Instrucciones del programa:
Se debe compilar con el comando Make.

El procesador de texto solo funciona con textos en ingles, no contempla textos en español ni caracteres especiales, si se intentan introducir dara una violacion de segmento. 

Si se quiere probar con otro archivo de texto se debe copiar el archivo en la carpeta Two, y en el Main.cpp en la linea 68 se debe cambiar el nombre del archivo de texto con su extension y despues se debe recompilar todo el proyecto. 

Si se quieren ver los pares ordenados de la linea y el espacio donde se encuentran las palabras que encontro el FreeText debe ir al archivo Trie.cpp descomentar la linea 105.



Experimientos.
QuickSort Random:
En este experimiento se insertan al QuickSort 30 diferentes arreglos desordenados en los cuales se pone a prueba el algortimo con diferentes pivotes 10 arreglos por cada pivote y cada arreglo incrementa su tamaño en 1000. Con el O(n) teorico del algoritmo se mide la tasa de crecimiento del tiempo de ejecucion del algoritmo y la tasa teorica y se compara para ver la diferencia.

Resultados:
El quicksort con arreglos desordenados tiene una tasa de crecimiento similar a la tasa de crecimiento teorica de n log(n) y esto se ve reflejado en el experimento. Tambien se puede concluir que la tasa de crecimiento al usar el primer elemento o el ultimo elemento es similar pero la tasa de crecimiento del Quicksort con pivote random es aleatoria y puede varias mucho con la tasa de crecimiento teorica.

QuickSort ordenado:
En este experimiento se insertan al QuickSort 10 diferentes arreglos ordenados en los cuales se pone a prueba el algortimo con un pivote fijo y cada arreglo incrementa su tamaño en 1000. Con el O(n) teorico del algoritmo se mide la tasa de crecimiento del tiempo de ejecucion del algoritmo y la tasa teorica y se compara para ver la diferencia.

Resultados:
En base en el experimiento se puede concluir que la tasa de crecimiento del QuickSort con arreglos ordenados crece de manera cuadratica.

FreeText:
En el experimiento de FreeText se carga un archivo el cual es el libro de WarPeace en un arbol Trie, en el proceso de carga se hace una indexacion y conteo de las veces que se pasa por encima del nodo que contiene la letra y se guarda la posicion de la linea en el texto y que posicion esta dentro de esta liena esa palabra en un struc pair(linea, posicion en la linea). Para este experimiento se utilizaron palabras con diferentes largos y se buscan dentro del texto y se toma el tiempo para verificar su tasa de crecimiento y se compara con la tasa de crecimiento teorica en este caso O(n) siendo n el tamaño de la palabra a buscar. 

Resultados:
Se comprueba por medio del experimiento que el algoritmo de busqueda se comporta de manera Lineal segun el tamaño de la palabra que se quiera buscar en el texto. 

InsertionSort ordenado:
En este experimiento se insertan al insertionsort 10 diferentes arreglos ordenados, cada arreglo incrementa su tamaño en 1000. Con el O(n) teorico del algoritmo se mide la tasa de crecimiento del tiempo de ejecucion del algoritmo y la tasa teorica y se compara para ver la diferencia.

Resultados:
Se comprueba por medio del experimiento que el agoritmo con arreglos ordenados tiene un comportamiento lienal y su tiempo crece de manera lineal. 

InsertionSort ordeando descendente:
En este experimiento se insertan al insertionsort 10 diferentes arreglos ordenados de maneta descendente, cada arreglo incrementa su tamaño en 1000. Con el O(n) teorico del algoritmo se mide la tasa de crecimiento del tiempo de ejecucion del algoritmo y la tasa teorica y se compara para ver la diferencia.

Resultados:
Se comprueba por medio del experimiento que el agoritmo con arreglos ordenados de manera descendente tiene un comportamiento cuadratico y su tiempo crece de manera cuadratica. 