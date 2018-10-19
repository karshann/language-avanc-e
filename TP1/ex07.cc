using namespace std;
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

class CString{
	private:
		char* chaine;
		int taille;
		static int nbChaine;
		//Le membre static doit etre declare dans la classe
		//mais defini en dehors de la classe(voir ci dessous)
		//un membre "static" ne peut etre "void" ou "const void"
	
	public:
		static void init(); //initialisation de la variable static nbChaine
		
		const char * getString() const {
			return chaine;
		}
		
		CString(){ //constructeur a partir d'une chaine vide
			chaine = new char [1];
			chaine[0] = '\0';
			nbChaine ++;
		}
		
		CString(const char c){ //constructeur a partir d'un char
			chaine = new char [2];
			chaine[0] = c;
			nbChaine ++;
		}
	
		CString(const char* s){ //constructeur a partir d'une chaine
			chaine = new char [taille = strlen(s) +1];
			strcpy(chaine, s);
			nbChaine ++;
		}
		
		static int nbrChaines(){ //static est necessaire car cette fonction ne peut etre
			//invoquee sur un objet de la classe
			return CString::nbChaine;
		}
		
		void afficher(){
			cout<<"chaine : "<< getString()<<"\n"; //ou directement l'atribut chaine
			cout<<endl;
		}
		
		CString plus(const CString& s){ //concatener 2 chaines
			char temp[20];
			strcpy(temp,chaine);
			strcat(temp, s.chaine);
			CString tempS(temp);
			return tempS;
		}
		
		CString plus(const char c){ //concatener 1 chaine avec 1 caractere
			char temp[20];
			strcpy(temp,chaine);
			int len = strlen(temp);
			temp[len] = c;
			temp[len+1] = '\0';
			CString tempS(temp);
			return tempS;
		}
		
		bool plusGrandQue(const CString& s1) const {
			if(strcmp(chaine, s1.chaine)>0) return 1;
			else return 0;
		}
		
		bool infOuEgale(const CString& s1) const {
			if(plusGrandQue(s1)) return 0;
			else return 1;
		}
		
		CString plusGrand(const CString& s1) const {
			if(plusGrandQue(s1)) return *this;
			else return s1;
		}
		
		~CString(){
			delete []chaine;
		}
};

int CString::nbChaine; //le membre static doit etre defini en dehors de la classe

void CString::init () { //si on veut initialiser la variable static a une valeur de 0
	nbChaine = 100;
}

class Definition{
	private:
		CString clef;
		CString def;
		
	public:
		Definition(){
			clef = CString();
			def = CString();
		}
		
		Definition(const char *c,const char *d){
			clef = CString(c);
			def = CString(d);
		}
		
		const char * getClef() const{
			return clef.getString();
		}
	
		const char * getDef() const {
			return def.getString();
		}
		
		~Definition() {
			delete[]clef.getString();
			delete[]def.getString();
		}
};



int main() {

	Definition homer( "Homer", "Buveur de biere" ) ;
	cout<<homer.getClef(); 
//	cout<<"la definition du mot "<< homer.getClef()<<" est "<<
	//homer.getDef() << endl ;

	cout<<endl; 
	
	return 1;
}
