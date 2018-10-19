using namespace std;
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "exo2.h"

#ifdef TAB_DYNAMIQUE

//Partie 1. Implementation par tableau dynamique

//Initialisation un vecteur a d'entier tous nuls

Vector::Vector(int d)
{
	if(d<=1)
	{
		count<<"Dimension <=1.Un seul entier(0) sera alloué\n";
		vect=new int[1];
		vect[0]=0;
		dim=1;
		return;
	}
	vect=new int[d];
	dim=d;
	for(int i=0;i<dim;i++)
	{
		vect[i]=0;
	}
}
//Constructeur de copie
Vector::Vector(const Vector &v)
{
	dim=v.dim;
	vect=new int[dim];
	for ( int i=0;i<dim;i++)
	{
		vect[i]=v.vect[i];
	}
}

//Destructeur
Vector::~Vector()
{
	delete []vect;
	vect=NULL;
}

//Operateur d'affectation .Le vecteur appelant sers une copi du vecteur passe en parametre

Vector &Vector::operator =(const Vector &v)
{
	if (this ==&v)
	{
		return *this;
	}
	//Sinon , liberer l'objet appelant et le construire comme
	//étant une copie de v.
	if(vect)
	{
		delete []vect;
	}
	Vector(v);
	return *this;
}
//retourne une reference vers l'ième entier du vecteur 
// Le retour de reference rend possible la modification des elements du vecteur.
int & Vector::operator [](int i)
{
	if(i<dim && i>=0)
	{
		return vect[i];
	}
	count<<"indice hors limite .Derniere composante renvoyée \n";
	return vect[dim-1];
	
}

//Ajout un entier au vecteur
Vector &Vector::operator +=(const int i)
{
	int *newVect=new int[dim];
	for(int k=0;k<dim;k++)
	{
		newVect[k]=vect[k];
	} 
	newVect[dim++]=i;
	if(vect)
	{
		delete []vect;
	}
	vect=newVect;
	return *this;
}
// Opérateur affichage 

ostream &operator <<(ostream &o,Vector &v)
{
	for(int i =0 ; i<v.dim;i++)
	{
		o<<v.vect[i]<<" "
	}
	cout<<endl;
	return o;
}

istream &operator >>(istream &is,Vector &v)
{
	int k=0;
	o=cout<< "entrer"<<v.dim<<"entiers : ";
	for(int i =0 ; i<v.dim;i++)
	{
		is>>v[k];
	}
	return is;
}

