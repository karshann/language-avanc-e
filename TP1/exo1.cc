#include <iostream>
#include <cstring>
using namespace std;

void tab_entier()
{
	int T[10]={5,8,6,4,9,7,2,10,1,3};
	int *p=T;
	for(int i=0;i<10;i++)
	{
		cout<<p[i]<<" ";
	}
	cout<<std::endl;
	for(;p<T+10;p++)
	{
		cout<<*p<<" ";
	}
	cout<<std::endl;
}
void tab_caractere()
{
	char *tab[3];
	int i=0;
	tab[0]=new char[strlen("truc")+1];
	strcpy(tab[0],"truc");
	tab[1]=new char[strlen("machin")+1];
	strcpy(tab[1],"machin");
	tab[2]=new char[strlen("chose")+1];
	strcpy(tab[2],"chose");
	while (i<3)
	{
		cout<<tab[i++]<<" ";
	}
	
	i=0;
	while(i<3)
	{
		delete [] tab[i++];
	}
}
int main()
{
	tab_entier();
	tab_caractere();
}
