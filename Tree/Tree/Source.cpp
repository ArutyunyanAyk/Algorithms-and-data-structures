#include <iostream>
#include <ostream>
template <class Type> 
class Tree;

template <class Type>
class CNode
{

	Type data;
	CNode<Type>* left;
	CNode<Type>* right;

public:
	CNode() 
	{
		data = NULL;
		left = nullptr;
		right = nullptr;
	}
    

	CNode(Type val)
	{
		data = val;
		left = nullptr;
		right = nullptr;
	}

	friend class Tree<Type>;

	Type get_data() 
	{
		return data;
	}

};

template <class Type>
class Tree 
{
	CNode <Type>* root;


public:

	Tree() 
	{
		root = nullptr;
	}

	void add(CNode<Type>* node) 
	{
		if (root == nullptr)
		{
			root = node;
		}
		else
		{
			CNode<Type>* cur = root;
			while (cur->left != node && cur->right != node)
			{
				if (node->data > cur->data && cur->right == nullptr)
				{
					cur->right = node;
				}
				else
				{
					if (node->data < cur->data && cur->left == nullptr)
					{
						cur->left = node;
					}
					else
					{
						if (node->data > cur->data)
						{
							cur = cur->right;
						}
						else
						{
							cur = cur->left;
						}
					}
				}

			}
		}
	}

	void add(Type value)
	{
		CNode<Type>* node = new CNode<Type>(value);

		add(node);
	}

	CNode<Type>* find(Type value) 
	{
		CNode<Type>* cur = root;
	    
		if (root->data == value)
		{
			return root;
		}

		while (cur->left != nullptr || cur->right != nullptr)
		{
			if (cur->right->data == value)
			{
				return cur->right;
			}
			else
			{
				if (cur->left->data == value)
				{
					return cur->left;
				}
				else
				{
					if (value > cur->data)
					{
						cur = cur->right;
					}
					else
					{
						cur = cur->left;
					}
				}
			}

		}
		return nullptr;
	}

	void destroy(Type value)
	{
		CNode<Type>* cur = root;
		CNode<Type>* delnode = find(value);

		while (cur->right != delnode && cur->left != delnode)
		{
			if (value > cur->data)
			{
				cur = cur->right;
			}
			else
			{
				cur = cur->left;
			}
		}



		if (cur->right == delnode)
		{
			if (delnode->right == nullptr)
			{
				cur->right = delnode->left;
				return;
			}
			else
			{
				cur->right = delnode->right;
				if (delnode->left != nullptr)
				{
					add(delnode->left);
				}				
			}			
		}
		else
		{
			if (delnode->right == nullptr)
			{
				cur->left = delnode->left;
				return;
			}
			else
			{
				cur->left = delnode->right;
				if (delnode->left != nullptr)
				{
					add(delnode->left);
				}
			}
		}


	}

};

//int main() 
//{
//
//	Tree<int> T;
//
//	T.add(5);
//	T.add(2);
//	T.add(4);
//	T.add(6);
//	T.add(8);
//	T.destroy(6);
//
//	std::cout << T.find(4)->get_data();
//
//	return 0;
//}