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


class Media {
protected:
	string extension;
	string nombre = "Desconocido";
	string fecha = "Desconocido";
	string autor = "Desconocido";
	string url;

public:
	Media(string extension, string nombre, string fecha, string autor, string url) {
		this->extension = extension;
		this->nombre = nombre;
		this->fecha = fecha;
		this->autor = autor;
		this->url = url;
	};
	string getInfo() {
		string stringFinal = "Tipo: ";
		if (extension == "jpg") {
			stringFinal+="Imagen \n";
		}else {if (extension == "mp4") {
			stringFinal+="Video \n";
		}else {if (extension == "mp3") {
			stringFinal+= "Audio \n";			
				}	
			}	
		}
		stringFinal+="Nombre: "+nombre+"\n"+"Fecha: "+fecha+"\n"+"Autor: "+autor+"\n"+"URL: "+url+"\n\n";
		return stringFinal;
	}
	~Media(){};
};


class NoticiaDigital: public Noticia {
protected:
	vector<Media*> lista;
public:
	NoticiaDigital(string titulo, string fecha, string reportero, vector<Media*> lista){
		this->titulo = titulo;
		this->fecha = fecha;
		this->reportero = reportero;
		this->lista = lista;
	}

	~NoticiaDigital(){};

	string getInfo() {
		string finalString = "";
		finalString+="Título: "+titulo+"\n"+"Fecha: "+fecha+"\n"+"Reportero: "+reportero+"\n"+"\nMedia: "+"\n";
		for (Media* element: lista) {
			finalString+= element->getInfo();
			delete element;
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
	vector<Media*> lista;

	lista.push_back(new Media("jpg","L","12/3/2021","Kira","https://sm.ign.com/t/ign_latam/screenshot/default/dnl_qxar.1280.jpg"));
	lista.push_back(new Media("mp4","The World","12/3/2020","meena","https://youtu.be/wOKmqDwdvIw"));
	lista.push_back(new Media("mp3","Death Note OTS","2006","TBG22","https://soundcloud.com/thebadguy22/sets/death-note-ost?utm_source=clipboard&utm_medium=text&utm_campaign=social_sharing"));


	noticias.push_back(new NoticiaPaper("Guerra", "12/12/2021", "Juan Perez", "C:\\usr\\branrch\\desktop\\image.png"));
	noticias.push_back(new NoticiaDigital("L ataca de nuevo", "13/5/2022", "Light Yagami", lista));
	noticias.push_back(new NoticiaRadio("Avistamiento de Spiderman", "28/2/2022", "Peter Parker", "https://soundcloud.com/fjuka-900414841/filmusic1?utm_source=clipboard&utm_medium=text&utm_campaign=social_sharing"));

	for (Noticia* element: noticias) {
		cout<<element->getInfo()<<endl<<endl;
		delete element;
	}
	
return 0;
}