#include <bits/stdc++.h>
#include "Trie.h"
#include <locale.h>
using namespace std;

Trie *trie = new Trie();
TrieNode* root = trie->getNode();

int main() {
	setlocale(LC_ALL, "spanish");
	string text = "WarPeace.txt";
	trie->abrirArchivo(text, root);
	trie->searchLine(root, "Prince");
	return 0;
}