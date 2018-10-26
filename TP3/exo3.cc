



class Node{
	
	friend class
// Variable membre	
	private ::
	int integer;
	Node *nextNode;

//Methodes 
public:
	//Constructeur
	Node(int i=0)
	{
		integer=i;
		nextNode=NULL;
		
	}
	~Node();
	{
		//Ce destruvteur fonctionne recursivement ( avalanche de destruction ).
		// La destruction entraine la destruction du noeud suivant etc .
		if(nextNode)delete nextNode;
	}
	int GetInt() {return integer;}
	Node =GetNextNode(){return nextNode;}
	
	
};
class CList
{
	protected:
		Node *head;
		int length;
	public :
		CList()
		{
			head=NULL;
			length=0;
		}
		//Si on veut un destructeur virtuel , il faut laisser sa definition pour les classes derivées
		//Dans cet exemple , on laisse le soin de la destruction à la classe de base car 
		//cette destrution est la meme pour les piles et les files.
		~CListe()
		{
			delete head;
			head=NULL;
			length=0;
		}
		friend ostream& operator <<(ostream&, CList&);
		virtual CList & operator <(int)=0;
		CList & operator >(int &i)
		{
			if(!head)
			{
				cout<<" la pile est vide \n";
				return *this;
			}
			//retire la tete de la pile et mettre sa valeur dans la variable passée en argument
			i=head->integer;
			Node *tmp=head;
			head=head->nextNode;
			tmp->nextNode=NULL; // Pour eviter l'effacement recursif
			delete tmp;
			return *this;
		}
};

ostream& operator <<(ostream &out,CList& clist)
{
	Node *curNode=CList.head;
	for(int i=0;i<list.length;i++)
	{
		out<<curNode->GetInt()<<" ";
		curNode=curNide->GetNextNode();
	}
	return out;
	
}
class CPile : public CList
{
	public:
	CPile():CList(){}
	virtual CList & operator <(int i)
	{
		Node *newNode=new Node[i];
		newNode->nextNode=head;
		head=newNode;
		length++;
		return *this;
	}

}


class CFile : public CList
{
	public :
		CFile():CList(){}
		
		//Empile un entier a la fin de la file
		virtual CList & operator <(int i )
		{
			Node *newNode=new Node(i)
			if(!head)
				head=newNode;
			else
			{
				Node *n=head;
				while(n->nextNode)
					n=n->nextNode;
				n->nextNode=newNode;
			}
			length++; 
			return *this;
		}
};
void main(){
	CPile pile;
	CFile file;

	CList* ptList = &file;
	* ptList < 0 < 1; //empiler deux valeurs dans la file
	cout << * ptList;
	int i;
	* ptList > i; //récupérer une valeur de la file dans i
	cout << * ptList << " i=" << i;

	ptList = &pile;
	* ptList < 0 < 1; //empiler deux valeurs dans la pile
	cout << *ptPile;
	* ptList > i; //récupérer une valeur de la pile dans i
	cout << * ptList << " i=" << i;
} 
