#include <iostream>
template <class  Type>


class CNode
{
	Type data;
	CNode* Left;
	CNode* Right;

	
public:
	CNode(Type a)
	{
		data = a;
		Left = nullptr;
		Right = nullptr;
	}

	void set_left(CNode<Type>* n)
	{
		Left = n;
	}

	void set_right(CNode<Type>* n)
	{
		Right = n;
	}

	CNode<Type>* get_left()
	{
		return Left;
	}

	Type get_right()
	{
		return Right;
	}

	Type get_data()
	{
		return data;
	}

	void print()
	{
		std::cout << data << "->";
	}

};

template <class  Type>

class Tree
{

	CNode <Type>* Root;
public:

	Tree()
	{
		Root = nullptr;
	}

	void insertCNode(Type cnode)
	{

		CNode<Type>* root_copy = new CNode<Type>(Root);


		if (Root == nullptr)
		{
			Root = cnode;
		}
		else
		{
			int f = 0;
			while (f != 1) 
			{
				if (cnode < root_copy)
				{
					if (root_copy->get_left() == nullptr)
					{
						root_copy->set_left(cnode);

						f = 1;
					}
					else
					{
						if (root_copy->get_right() == nullptr)
						{
							root_copy->set_right(cnode)

								f = 1;
						}
						else
						{
							root_copy->set_right(root_copy->get_right());
						}
					}

				}
			}
		}

	}

	bool findNode(Type cnode)
	{
		CNode<Type>* root_copy = new CNode<Type>(Root);


		if (cnode == Root)
		{
			return true;
		}
		else
		{
			if (cnode == root_copy->get_right() || cnode == root_copy->get_left())
			{
				return true;
			}
			else
			{
				root_copy->set_right(root_copy->get_right());
			}
			
		}
	}

	DestroyCNode(CNode* cnode)
	{
		if(cnode)
		{

		}
	}

	void printl()
	{
		

	}

private:

};
int main()
{
	Tree<int> a;

	a.insertCNode(1);

	
    
}
