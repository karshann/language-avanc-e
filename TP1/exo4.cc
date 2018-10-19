#include <iostream>
#include <cstring>
using namespace std;

class Point{
	
	private:
		double abs;
		double ord;
	
	public:
		double get_abs() const
		{
		return abs;
		}
	
		double get_ord()const
		{
			return ord;
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

int main()
{
	Point P(5,4);
	P.afficher();
	Point P1;
	P1.afficher();
	Point P2(P);
	P2.afficher();
	Point P3;
	P3.cloner(P);
	P3.afficher();
	P3.destructeur();
}
