output: Main.o Trie.o QuickSort.o
	g++ Main.o Trie.o QuickSort.o -o main

Main.o:
	g++ -c Main.cpp

Trie.o: Trie.cpp
	g++ -c Trie.cpp

QuickSort.o: QuickSort.cpp
	g++ -c QuickSort.cpp

clean:
	rm *.o main