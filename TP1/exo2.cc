#include <iostream>
#include <cstring>
using namespace std;


void echange( int &a, int &b)
{
	int temp;
	temp=a;
	a=b;
	b=temp;
}
int main()
{
	int a =5;
	int b=7;
	echange(a,b);
	cout<<a<<" "<<b;
}
