#include <iostream>
#include <cstring>
using namespace std;

void tableauEcriture(int *tab,int taille)
{
	for (int i=0;i<taille;i++)
	{
		tab[i]=i;
	}
}

void tableauLecture(const int *tab , int taille)
{
	for (int i=0;i<taille;i++)
	{
		cout<<tab[i]<<std::endl;
	}
	
}

int main()
{
	int tab[10];
	tableauEcriture(tab,10);
	tableauLecture(tab,10);
}
