#include <bits/stdc++.h>
#include "Trie.h"
using namespace std;

struct TrieNode* root = getNode();


void readWords(string line, int linea){
	string word;
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

void abrirArchivo(string archivo){
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
                readWords(text, contador);
                }
				contador++;
            }
        }
    }



int main() {
	setlocale(LC_ALL, "spanish");
	string text = "WarPeace.txt";
	abrirArchivo(text);
	searchLine(root, "dependence");
	return 0;
}