#include <iostream>
#include <stack>


template <class  Type>


class CNode
{
	Type data;

	CNode<Type>* next;
public:
	CNode(Type a)
	{
		data = a;
		next = nullptr;
	}

	void set_next(CNode<Type>* n)
	{
		next = n;
	}

	CNode<Type>*get_next()
	{
		return next;
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


class CList
{
	CNode<Type>* head;

	CNode<Type>* tail;
public:
	CList()
	{
		head = nullptr;

		tail = nullptr;
	}

	void push_back(Type b)
	{
		CNode<Type>* a = new CNode<Type>(b);

		if (is_empty())
		{
			head = a;
			tail = a;
		}
		else
		{

		tail->set_next(a);

		tail = a;
		}
	}

	void push_front(Type f)
	{
		CNode<Type>* a = new CNode<Type>(f);

		if (is_empty())
		{
			head = a;
			tail = a;
		}
		else
		{
			a->set_next(head);

			head = a;
		}
	}

	void pop_back()
	{
		if (head == tail)
		{
			head = nullptr;
			tail = nullptr;
		}
		else 
		{

		CNode<Type>* tail_copy = head;

		while (tail_copy->get_next()!= tail)
		{
			tail_copy = tail_copy->get_next();
		}

		tail = tail_copy;

		tail_copy = tail_copy->get_next;

		delete tail_copy;
		}
	}

	void pop_front()
	{
		if (head == tail)
		{
			head = nullptr;
			tail = nullptr;
		}
		else
		{
			CNode<Type>* head_copy = head;

			head = head->get_next();

			delete head_copy;
		}
	}

	void insert(Type i, int pos_)
	{
		CNode<Type>* h = head;
		int pos = 2;
		CNode<Type>* a = new CNode<Type>(i);

		if (pos_ == 1)
		{
			pop_front(i);
		}

		while (pos != pos_)
		{
			h = h->get_next();
			pos++;
		}
		
		a->set_next(h->get_next());

		h->set_next(a);
	}

	size_t size()
	{
		CNode<Type>* a = head;
		int size = 0;

		while (a == tail)
		{
			a = a->get_next();

			size++;
		}

		size++;

		return size;
	}

	bool is_empty()
	{
		if (head == nullptr)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void list_reverse()
	{
		std::stack<Type> s1;
		while (!is_empty())
		{
			s1.push(head->get_data());
			this->pop_front();
		}
		while (!s1.empty())
		{
			this->push_back(s1.top());
			s1.pop();
		}
	}

	Type get_last_data()
	{
		return tail->get_data();
	}

	Type get_first_data()
	{
		return head->get_data();
	}

	void printl()
	{
		CNode<Type>* h = head;

		while (h != tail)
		{
			h->print();
			h = h->get_next();
		}
		tail->print();

	}

	void clear()
	{	
		while (!is_empty())
		{
			this->pop_front();			
		}
	}

	~CList()
	{
		clear();
	}
};

template <class Type>

class Queue
{
	CList <Type> l1;
	size_t size;

public:
	Queue()
	{		
		size = 0;
	}

	Type Top()
	{
		if (is_empty())
		{
			throw std::logic_error("is_empty");
		}

		return l1.get_first_data();
	}

	void pop()
	{
		if (is_empty())
		{
			throw std::logic_error("is_empty");
		}

		l1.pop_front();
	}

	void push(int a)
	{
		l1.push_back(a);
	}

	bool is_empty()
	{
		return l1.is_empty();
	}

	void print()
	{
		l1.printl();
	}

	~Queue()
	{
		l1.clear();
	}

};

template <class Type>

class Stack
{
	CList <Type> l2;
	size_t size;
public:
	Stack()
	{
		size = 0;
	}

	Type Top()
	{
		if (is_empty())
		{
			throw std::logic_error("is_empty");
		}

		return l2.get_last_data();
	}

	void pop()
	{
		if (is_empty())
		{
			throw std::logic_error("is_empty");
		}

		l2.pop_back();
	}

	
	void push(int a)
	{
		l2.push_back(a);
	}

	bool is_empty()
	{
		return l2.is_empty();
	}


	void print()
	{
		l2.printl();
	}

	~Stack()
	{
		l2.clear();
	}

};

int main()
{
	CList<int> l1;

	l1.push_front(1);
	l1.push_front(2);
	l1.push_front(3);
	l1.push_front(4);
	l1.printl();
	std::cout << "\n";
	l1.list_reverse();
	l1.printl();

}