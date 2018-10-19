#ifndef DICO_H
#define DICO_H

#include "CString.h"
#include <iostream>
using namespace std;


class Definition
{
	//attributs
	private:
		CString clef;
		CString defnition;
	
	
	
	public:
		Definition(char *, char*);
		CString Getclef() const;
		CString GetDef() const;
		~Definition();
	
		
};

class Node
{
	friend class Nico;
	//variable membre
	private:
		Definition *def;
		/*
		 * Pointeur vers la definition.Ceci permet la separation entre la structure 
		 * de chaine et les donnees manipulées.Cela permettre ce qu'on appelle
		 *  le "stockage externe" voir l'explication au début de la classe Dico ci dessous.
		*/
		Node *nextNode;
	public:
		Node(Definition *);
		~Node();
		Definition *GetDef(){return def;}
		Node * GetNextNode(){return nextNode;}
};

/*
 * Dico implemente une liste chainée de definition
 * Elle contient une champ special : IsOwner
 * Pour comprendre ce champ , expliquons d'abord les deux notions suivantes:
 * Stockage interne et stockage externe
 * 
 * En effet, les données d'une liste chainée sont comminément stockées dans les noeuds
 * de la liste , comme c'était le cas avec la classe vector de l'exo2 du td2
 * C'est le cas d'un stockage interne.
 * Cependant , en stockage externe, le noeud contient uniquement un pointeur vers les d
 * Cela facilitera la construction de plusieur listes utilisant les mem données.
 * En plus , cela permettra une implementation generique de la maniplation d'une liste
 * indépendemment de la ,ature des données utilisées.
 * 
 * Dans la liste Dico , on utilise bien le stockage externe  puisque la classe node
 * contient un pointeur vers la definition .Lavariable booleenne isOwner precise
 * si le dictionnaire controle les definitions .Si c'est le cas tout effacement 
 * de noeud devraen meme temps effacer la definition pointées
 * Dans le cas contaire , les donnes seront toujours intactes independemment 
 * des noeud de la liste 
 */
 
 class Dico 
 {
	 private:
		Node *head;
		int lenght;
		bool isOwner;
		void Destroy(Node *); // méthode récursive privée qui sera appelée par le Destructeur
	 public:
		Dico(bool=true);//parametre optionnel lors d'un appel , par defaut true
		~Dico();
		void AddDef(Definition *);//ajout d'un definition
		int GetLenght(){return lenght;};
		
		CString GetDef(CString &);//Recherche une définition 
		Definition* GetRandDef();//Retourne une definition aleatoire
		void Display();
		friend ostream & operator <<(ostream &, Dico &);//doit etre un friend sinon le compilateur ne fais pas la difference.
		
	
		
	
	
}
