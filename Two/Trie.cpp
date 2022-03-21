#include <bits/stdc++.h>
#include<list>
#include<string>
#include "Trie.h"
#include <locale.h>
using namespace std;

const int ALPHABET_SIZE = 26;

Trie::Trie(){
    setlocale(LC_ALL, "spanish");
}
// trie node
struct TrieNode {
	struct TrieNode* children[ALPHABET_SIZE];
    list<int> positions;
	// isEndOfWord is true if the node represents
	// end of a word
	bool isEndOfWord;
};

// Returns new trie node (initialized to NULLs)
struct TrieNode* Trie::getNode(void)
{
	struct TrieNode* pNode = new TrieNode;

	pNode->isEndOfWord = false;

	for (int i = 0; i < ALPHABET_SIZE; i++)
		pNode->children[i] = NULL;

	return pNode;
}

// If not present, inserts key into trie
// If the key is prefix of trie node, just
// marks leaf node
void Trie::insert(struct TrieNode* root, string key, int line)
{
	struct TrieNode* pCrawl = root;

	for (int i = 0; i < key.length(); i++) {
		int index = key[i] - 'a';
		if (!pCrawl->children[index])
			pCrawl->children[index] = getNode();

		pCrawl = pCrawl->children[index];
	}

	// mark last node as leaf
	pCrawl->isEndOfWord = true;
    pCrawl->positions.push_back(line);
}

// Returns true if key presents in trie, else
// false
bool Trie::search(struct TrieNode* root, string key)
{
	struct TrieNode* pCrawl = root;

	for (int i = 0; i < key.length(); i++) {
		int index = key[i] - 'a';
		if (!pCrawl->children[index])
			return false;

		pCrawl = pCrawl->children[index];
	}

	return (pCrawl != NULL && pCrawl->isEndOfWord);
}

void Trie::showlist(list<int> g)
{
    list<int>::iterator it;
    for (it = g.begin(); it != g.end(); ++it)
        cout << *it<<", ";
    cout << '\n';
}

void Trie::searchLine(struct TrieNode* root, string key)
{
	struct TrieNode* pCrawl = root;

	for (int i = 0; i < key.length(); i++) {
		int index = key[i] - 'a';
		if (!pCrawl->children[index]){
            cout<<"Word not found! "<<endl;
            return;
        }

		pCrawl = pCrawl->children[index];
	}
    if (pCrawl != NULL && pCrawl->isEndOfWord) {
        showlist(pCrawl->positions);
    }
}

// Returns true if root has no children, else false
bool Trie::isEmpty(TrieNode* root)
{
	for (int i = 0; i < ALPHABET_SIZE; i++)
		if (root->children[i])
			return false;
	return true;
}


void Trie::readWords(string line, int linea, TrieNode* root){
	string word;
    int posInLine = 0;
    for (char character: line) {
            character = tolower(character);
            int ascii = int(character);
            if (!((ascii>=97 && ascii<=122) || character == int('ñ') || character == int('á') || character == int('é') || character == int('í') || character == int('ó') || character == int('ú')|| character == int('ü'))){
                if (!(word == "")){
                    insert(root, word, linea);
                }
                    word = "";
            } else {
                word+=character;
            }
            
        }
    }

void Trie::abrirArchivo(string archivo, TrieNode* root){
    string text;
    ifstream ifs(archivo);
    if(ifs.fail()) {
        throw runtime_error("Falló al abrir el archivo");
        }
    else{
        int contador = 0;
        while (!ifs.eof()){
            getline(ifs, text);
            if(!(text.size()==0)){
                readWords(text, contador, root);
                }
				contador++;
            }
        }
    }