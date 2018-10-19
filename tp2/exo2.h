//Pour evier des declaration multiples ou recursives
#ifndef _exo2_H
#edfine _exo2_H


#include <iostream>
using namespace std;

//Constante macro qui permet de choisir l'implementation a compiler
//Si cette définition est faite  , c'est l'implementation par tableau 
// Pour l'implementation par liste chainée , il suffit de mettre en commentaire 
// la definition de TAB_DYNAMIQUE
#define TAB_DYNAMIQUE

#ifdef TAB_DYNAMIQUE

class Vector
{
	//Attributs 
	private :
		int *vect;
		int dim; // taille du vecteur = nombre de composantes (ou entiers)
	// Methodes
	public :
		//Constructeur
		Vector(int d);
		Vector(const Vector &v);//de copie
		//Destructeur 
		~Vector();
		
		Vector &operator =(const Vector &);
		int &operator [](int i); //Retourne le ième élément 
		Vector &operator+=(const int);
		friend ostream &operator <<(ostream &o , Vector &v);//Surchage de l'operateur d'affichage.
		friend istream &operator >>(istream &is , Vector &v);//Operateur de saisie.
};
#else

//Node est une class qui represente un element de la liste chaine

class Node
{
	friend class Vector; // le vecteur sera une classe amis de Node
						 // pour accéder facilement aux atributs.
// Variables membres
privates :
	int integer;
	Node *nextNode;
//Methodes 
public:
	Node(int);//Constructeur
	~Node();//Destructeur
	int GetInt(){return integer;}
	Node * GetNextNode(){return nextNode;}
	//Nous voyons que nous pouvons definir une partie des méthodes
	//dans ka class elle-meme et laisser les autres pour l'implementation
	
};



class Vector
{
//variables membres
public:
		Node *head;
		int lenght;

// Methodes
public :
	//Constructeur
	Vector(int d);
		Vector(const Vector &v);//de copie
	//Destructeur 
	~Vector();
	//Fonction de gestion de la liste chainée
		Vector &operator =(const Vector &);
		int &operator [](int i); 
		Vector &operator+=(const int);//Ajout d'un element de la liste .
		friend ostream &operator <<(ostream &o , Vector &v);//Surchage de l'operateur d'affichage.
		friend istream &operator >>(istream &is , Vector &v);//Operateur de saisie.
};
#endif
#endif
