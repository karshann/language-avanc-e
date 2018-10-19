#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

class Point{
	
	private:
		double abs;
		double ord;
	
	public:
		double get_abs() const
		{
		return this->abs;
		}
	
		double get_ord()const
		{
			return this->ord;
		}
		void set_abs(double x)
		{
			abs=x;
		}
		void set_ord(double y)
		{
			ord=y;
		}
		void cloner(const Point &P)
		{
			abs=P.abs;
			ord=P.ord;
		}
		void afficher()
		{
			cout<< abs <<" "<<ord << std::endl;
		}
		void destructeur()
		{
			cout << "appel au destructeur";
		}
		Point()
		{
			abs=0;
			ord=0;
		}
		Point(double x , double y)
		{
			abs=x;
			ord=y;
		}
		Point(const Point &P)
		{
			abs=P.abs;
			ord=P.ord;
		}
		

	

	
};
class Segment{
	
	private :
	
	Point P1;
	Point P2;
	 
	public :
	
	bool estVertical()
	{
		if (P1.get_abs() == P2.get_abs())return true;
		else return false;
	}
	bool estHorizontale()
	{
		return P1.get_ord()==P2.get_ord();
	}
	bool estDiagonal()
	{
		return (P1.get_abs()!=P2.get_abs() & P1.get_ord()!=P2.get_ord()) ;
	}
	
	double longueur()
	{
		if (estVertical()) return abs(P1.get_ord() - P2.get_ord());
		if (estHorizontale()) return abs(P1.get_abs() - P2.get_abs());
		else return sqrt(((P1.get_ord()- P2.get_ord())*(P1.get_ord()- P2.get_ord()))+((P1.get_abs() - P2.get_abs())*(P1.get_abs() - P2.get_abs())));
	}
	Segement(Point p,Point p1)
	{
		P1=p;
		P2=p1;
	}
	
	
};

int main()
{
	Segment S;
	double a;
}
