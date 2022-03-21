#ifndef TRIE_H
#define TRIE_H
#include<string>
#include<list>
using namespace std;
class Trie{

public:
	Trie();
    struct TrieNode* getNode(void);
	void insert(struct TrieNode* root, string key, int line);
	bool search(struct TrieNode* root, string key);
	void showlist(list<int> g);
	void searchLine(struct TrieNode* root, string key);
	bool isEmpty(TrieNode* root);
	void readWords(string line, int linea, TrieNode* root);
	void abrirArchivo(string archivo, TrieNode* root);
};

#endif // TRIE_H
