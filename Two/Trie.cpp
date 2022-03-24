#include "Dependencies.h"
using namespace std;

const int ALPHABET_SIZE = 100;

Trie::Trie(){
    setlocale(LC_ALL, "spanish");
}

struct Pair
{
    int line = 0;
    int posInLine = 0;
};
struct TrieNode {
	struct TrieNode* children[ALPHABET_SIZE];
    list<Pair*> positions;
	bool isEndOfWord;
};


struct TrieNode* Trie::getNode(void)
{
	struct TrieNode* pNode = new TrieNode;

	pNode->isEndOfWord = false;

	for (int i = 0; i < ALPHABET_SIZE; i++)
		pNode->children[i] = NULL;

	return pNode;
}

struct Pair* Trie::getPair(int line, int posInLine){
    struct Pair* pPair = new Pair;
    pPair->line = line;
    pPair->posInLine = posInLine;
    return pPair;
}

void Trie::insert(struct TrieNode* root, string key, Pair* p)
{
	struct TrieNode* pCrawl = root;

	for (int i = 0; i < key.length(); i++) {
		int index = key[i] - 'a';
		if (!pCrawl->children[index])
			pCrawl->children[index] = getNode();

		pCrawl = pCrawl->children[index];
	}

	pCrawl->isEndOfWord = true;
    pCrawl->positions.push_back(p);
}

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

void Trie::showlist(list<Pair*> g)
{
    list<Pair*>::iterator it;
    for (it = g.begin(); it != g.end(); ++it){
        Pair* p = *it;
        cout<<"("<<p->line<<", "<<p->posInLine<<")";
    }
    cout << '\n';
}

string Trie::aMinuscula(string cadena) {
  for (int i = 0; i < cadena.length(); i++) cadena[i] = tolower(cadena[i]);
  return cadena;
}

void Trie::searchLine(struct TrieNode* root, string key)
{
    key = aMinuscula(key);
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
                    insert(root, word, getPair(linea, posInLine-word.length()));
                }
                    word = "";
            } else {
                word+=character;
            }
            posInLine++;
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