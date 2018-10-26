	using namespace std;
#include <iostream>
#include <stdlib.h>
#include <math.h>


class Point {
	//variables membres
	public:
		double abs; //abscisse
		double ord; //ordonnee
		
	//fonctions membres
	public:
		Point() { //constructeur par default
			abs = ord = 0;
		}
		
		Point(double abs, double ord) { //constructeur a deux parametres
			this->abs = abs;
			this->ord = ord;
		}
		
		Point(const Point &p) { //constructeur de copie
			this->abs = p.abs;
			this->ord = p.ord;
		}
		
		virtual void afficher() {
			cout<<"Point: x = "<<abs<<", y = "<<ord<<"\n";
		}
		
		void cloner(const Point &p) {
			this->abs = p.abs;
			this->ord = p.ord;
		}
		
		virtual ~Point() { //destructeur
			cout<<"\n";
			cout<<"Destruction du Point : x "<<abs<<", y = "<<ord<<"\n";
		}
};

enum COLOR(BLANC,BLEU,VIOLET);

char *coul[5]={"Blanc", "Bleu", "Violet", "Vert", "Rouge"};


class PointColor ; public Point {
	//variables membre
	private:
		int couleur;
	//methode
	public:
		PointColor(double abs, double ord, inr c) : Point(abs, ord) {//appel du constructeur de la class
			couleur = c;
		}
		
		virtual void afficher(){
			Point::afficher(); //utilise la fonction afficher de la class mere
			cout<<", Couleur : "<<coul[couleur]<<"\n";
		}
		
		~PointColor(){ //destructeur
			cout<<"\n";
			cout<<"Destruction du point colore : x = "<<abs<<", y = "<<ord<<", Couleur : "<<coul[couleur]<<"\n";
		}
};


int main() {
	
	PointColor pc = PointColor(2.3, 9.6,ROUGE);
	Point p = Point(-2.5, 9.0);
	Point *pp = (&pc);
	pc.afficher();
	p.afficher();
	
	pp->afficher();
	
	pp = new PointColor(0.3, 0.6,VERT);
	delete pp;
	
	pp=NULL;
	
	
	
	return 1;
}
