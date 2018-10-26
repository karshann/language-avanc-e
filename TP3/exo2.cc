using namespace std;
#include <iostream>
#include <stdlib.h>
#include "ex01.cc"

class Form{
	public :
		Form() {};
		virtual ~Form(){cout << "Destructeur Form \n";}
		
		virtual void Display()=0;
		virtual void Move ( double dx , double dy)=0;
		
};

class Rect : public Form {

	private :
		Point position;
		double width;
		double height;
	
	public :
		Rect ( double abs =0.0, double ord 0.0, double w=1.0 , double h 1.0)
			:Form(), position(abs,ord) , widht=w , height(h) // une fonçon d'initialiser les variables membres
		{}
		
		virtual ~Rect(){cout<< " destructeur Rect \n";}
		virtual Display()
		{
			cout << "Rectangle.position : ";
			position.afficher();
			cout << " width : "<<width<<" , height : "<< height << endl;
		}
		virutal void Move(double dx , double dy )
		{
			this.position.abs+=dx;
			this.position.ord+=dy;
		}
};

class Triangle : public Form {
	
		private:
			Point s[2];
		
		public:
			Triangle( double abs1 =1.0, double ord1=0.0, double abs2 =0.0, double ord2=0.0, double abs3 =0.0, double ord3=0.0)
				:Form()
			{
				s[0]=Point(abs1,ord1);
				s[1]=Point(abs2,ord2);
				s[2]=Point(abs3,ord3);
			}
			
			virtual ~Triangle(){cout<<"Destructeur Triangle\n";}
			
			virtual void Display ()
			{
				cout << "Triangle, Sommets : ";
				for (int i=0;i<3;i++)
				{
					s[i].afficher();
				}
			}
			virtual void Move(double dx double dy)
			{
				
				for (int i=0;i<3;i++)
				{
					s[i].abs+=dx;
					s[i].ord+=dy;
				}
			}
};
	

int main()
{
	Form *f=new Rect {2.3,-0.7,5.6,9.5};
	f->Display();
	f->Move(7.7,7.7);
	f->Display();
	delete f ;
	
	f=new Triangle{1.0,1.0,-2.3,-5.0,2.3,6.0};
	f->Display();
	f->Move(7.7,7.7);
	f->Display();
	delete f ;
}

