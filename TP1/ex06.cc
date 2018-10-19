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


int main() {
	
	CString::init(); //si on veut initialiser la variable static a une valeur de 0;
	//sinon, la variable est initialisee (1) à la premiere creation
	//d'un objet de la classe
	cout << "Nombre de chaine = " << CString::nbrChaines() << endl;
	
	CString s1("toto"),
		s2('q'),
		s3 = s1.plus('w');
	
	cout << "nbrChaines" << CString::nbrChaines() << endl ;
	//afficher le nombre de chaines créées
	
	cout << "s3=" << s3.getString() << endl ;
	
	if(s1.plusGrandQue(s2)) // si s1 > s2 au sens alphabétique
		cout << "plus grand" << endl ;
		
	if(s1.infOuEgale(s2)) // si s1 <= s2 au sens alphabétique
		cout << "plus petit" << endl ;
		
	else cout <<"plus petit"<<endl;
	s3 = s1.plusGrand(s2) ;// retourner s1 si s1>s2, s2 sinon
	cout<<"nbrChaines : "<<CString::nbrChaines()<<endl;
	CString S;
	CString SR;
	cout<<"Nombre de chaines = "<<CString::nbrChaines()<<endl;
	CString S1("exemple1");
	CString S2("exemple2");
	S1.afficher();
	S2.afficher();
	cout<<"nombre de chaine = "<<CString::nbrChaines()<<endl;
	SR = S1.plus(S2);
	SR.afficher();
	
	cout<<endl; 
	
	return 1;
}
