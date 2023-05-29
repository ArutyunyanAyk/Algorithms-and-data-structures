#include <iostream>
#include <ostream>
#include <string>
#include <stack>
#include <math.h>
class Tree_exp;

class CNode
{

	std::string data;
	CNode* left;
	CNode* right;

public:
	CNode()
	{
		data = "";
		left = nullptr;
		right = nullptr;
	}


	CNode(std::string val)
	{
		data = val;
		left = nullptr;
		right = nullptr;
	}

	friend class Tree_exp;

	std::string get_data()
	{
		return data;
	}

};

class Tree_exp 
{

	CNode* root;
public:
	Tree_exp()
	{
		root = nullptr;
	}

	bool isOperator(std::string c) {
		return (c == "+" || c == "-" || c == "*" || c == "/" || c == "^");
	}

	void parser(std::string postfix)
	{
		if (postfix.length() == 0) {
			throw std::logic_error("Empty");
		}

		std::stack <CNode*> s;

		std::string b = "";

		for (int i = 0; i < postfix.length(); i++)
		{
			if (postfix[i] == ' ' || i == postfix.length() - 1)
			{
				if (i == postfix.length() - 1)
				{
					b += postfix[i];
				}
				if (isOperator(b)) {
					CNode* x = s.top();
					s.pop();
					CNode* y = s.top();
					s.pop();
					CNode* node = new CNode();
					node->data = b;
					node->right = x;
					node->left = y;
					s.push(node);
				}
				else
				{
					CNode* node = new CNode(b);
					s.push(node);
				}
				b = "";
			}
			else
			{				
				b += postfix[i];
			}			
		}
		root = s.top();
	}

	CNode* calculate(CNode* node)
	{		
		CNode* right_res = node->right;
		CNode* left_res = node->left;
		CNode* res = new CNode;

		if (isOperator(node->left->data))
		{
			left_res = calculate(node->left);
		}

		if (isOperator(node->right->data))
		{
			right_res = calculate(node->right);
		}

		switch (node->data[0])
		{
		 
		case  '+': 
		{
			res->data = std::to_string(std::stoi(left_res->data) + std::stoi(right_res->data));
			break;
		}
		case  '-':
		{
			res->data = std::to_string(std::stoi(left_res->data) - std::stoi(right_res->data));
			break;
		}
		case  '*':
		{
			res->data = std::to_string(std::stoi(left_res->data) * std::stoi(right_res->data));
			break;
		}
		case  '/':
		{
			res->data = std::to_string(std::stoi(left_res->data) / std::stoi(right_res->data));
			break;
		}
		case  '^':
		{
			res->data = std::to_string(pow(std::stoi(left_res->data), std::stoi(right_res->data)));
			break;
		}
		default: 
		{
			throw std::logic_error("Wrong character!");
		}
			break;
		}
		return res;
	}

	std::string result() 
	{
		return calculate(root)->data;
	}
};

int main()
{
	Tree_exp t;

	t.parser("34 16 + 14 -");
	std::cout << t.result();

	return 0;
}
