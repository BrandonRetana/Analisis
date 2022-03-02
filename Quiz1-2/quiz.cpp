#include <iostream>
#include <vector>
using namespace std;

class Noticia {
protected:
	string titulo;
	string fecha;
	string reportero;
public:
	Noticia(){}
	virtual ~Noticia() {}
	virtual string getInfo() = 0;
};

class NoticiaPaper: public Noticia {
protected:
	string rutaImagen;
public:
	NoticiaPaper(string titulo, string fecha, string reportero, string rutaImagen) {
		this->titulo = titulo;
		this->fecha = fecha;
		this->reportero = reportero;
		this->rutaImagen = rutaImagen;
	}

	~NoticiaPaper(){};

	string getInfo() {
		string finalString = "";
		finalString+="Título: "+titulo+"\n"+"Fecha: "+fecha+"\n"+"Reportero: "+reportero+"\n"+"Ruta imagen: "+rutaImagen+"\n";
		return finalString;
	}
};


class NoticiaDigital: public Noticia {
protected:
	vector<string> lista;
public:
	NoticiaDigital(string titulo, string fecha, string reportero, vector<string> lista){
		this->titulo = titulo;
		this->fecha = fecha;
		this->reportero = reportero;
		this->lista = lista;
	}

	~NoticiaDigital(){};

	string getInfo() {
		string finalString = "";
		finalString+="Título: "+titulo+"\n"+"Fecha: "+fecha+"\n"+"Reportero: "+reportero+"\n"+"Media: "+"\n";
		for(string element: lista) {
			finalString+=element+"\n";
		}
		return finalString;
	}
};

class NoticiaRadio: public Noticia {
protected:
	string urlAudioFile;
public:
	NoticiaRadio(string titulo, string fecha, string reportero, string urlAudioFile) {
		this->titulo = titulo;
		this->fecha = fecha;
		this->reportero = reportero;
		this->urlAudioFile = urlAudioFile;
	}

	~NoticiaRadio(){};

	string getInfo() {
		string finalString = "";
		finalString+="Título: "+titulo+"\n"+"Fecha: "+fecha+"\n"+"Reportero: "+reportero+"\n"+"URL: "+urlAudioFile+"\n";
		return finalString;
	}
};

int main() {
	vector<Noticia *> noticias;
	vector<string> lista = {"https://www.cultture.com/pics/2020/10/nota-de-la-muerte-10-cosas-que-debes-saber-sobre-l-2.jpg", "https://youtu.be/wOKmqDwdvIw", "https://soundcloud.com/equimanthornn/death-note-ls-theme?utm_source=clipboard&utm_medium=text&utm_campaign=social_sharing"};

	noticias.push_back(new NoticiaPaper("Guerra", "12/12/2021", "Juan Perez", "C:\\usr\\branrch\\desktop\\image.png"));
	noticias.push_back(new NoticiaDigital("L ataca de nuevo", "13/5/2022", "Light Yagami", lista));
	noticias.push_back(new NoticiaRadio("Avistamiento de Spiderman", "28/2/2022", "Peter Parker", "https://soundcloud.com/fjuka-900414841/filmusic1?utm_source=clipboard&utm_medium=text&utm_campaign=social_sharing"));

	for (Noticia* element: noticias) {
		cout<<element->getInfo()<<endl<<endl;
		delete element;
	}
	
return 0;
}