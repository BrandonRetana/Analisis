#ifndef TRIE_H
#define TRIE_H

using namespace std;
class Trie{

public:
	Trie();
    struct TrieNode* getNode(void);
	void insert(struct TrieNode* root, string key, struct Pair* p);
	bool search(struct TrieNode* root, string key);
	void showlist(list<Pair*> g);
	void freeText(struct TrieNode* root, string key);
	bool isEmpty(TrieNode* root);
	void readWords(string line, int linea, TrieNode* root);
	void abrirArchivo(string archivo, TrieNode* root);
	struct Pair* getPair(int line, int posInLine);
	string aMinuscula(string cadena);
};

#endif // TRIE_H
