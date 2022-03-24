output: Main.o Trie.o QuickSort.o InsertionSort.o
	g++ Main.o Trie.o QuickSort.o InsertionSort.o -o main

Main.o:
	g++ -c Main.cpp

Trie.o: Trie.cpp
	g++ -c Trie.cpp

QuickSort.o: QuickSort.cpp
	g++ -c QuickSort.cpp

InsertionSort.o: InsertionSort.cpp
	g++ -c InsertionSort.cpp
clean:
	rm *.o main