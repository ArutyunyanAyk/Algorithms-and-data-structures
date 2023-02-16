#include <iostream>


template <class Type>

class CNode
{
	std::pair <Type, int> data;

	CNode<Type>* next;
public:
	CNode(Type a, int priority)
	{
		std::pair<Type, int> data_{a, priority}

		data = data_;

		next = nullptr;
	}

	void set_next(CNode<Type>* n)
	{
		next = n;
	}

	CNode<Type>* get_next()
	{
		return next;
	}

	Type get_data_first()
	{
		return data.first;
	}

	Type get_data_second()
	{
		return data.second;
	}

	void print()
	{
		std::cout << data.first << ":" << data.second << "->";
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

	void push_back_priority(Type num, int priority)
	{
		CNode<Type>* a = new CNode<Type>(num,priority);
		CNode<Type>* b = head;

		if (is_empty)
		{
			head = a;
			tail = a;
		}
		else
		{
			if (a->get_data_second() > head->get_data_second())
			{
				a->set_next(head);
				head = a;
			}
			else
			{
				while (a->get_data_second() <= b->get_next()->get_data_second() && b->get_next() != tail)
				{
					b = b->get_next();
				}
				if (b->get_next() == tail && a->get_data_second() < tail->get_data_second())
				{
					tail->set_next(a);
					tail = a;
				}
				else
				{
					a->set_next(b->get_next());
					b->set_next(a);
				}
			}
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

	void pop_front_priority()
	{
		if (is_empty())
		{
			throw std::logic_error("is empty")
		}
        
		CNode<Type>* a = head;
		CNode<Type>* b = head;

		if (tail == head)
		{
			tail = nullptr;
			head = nullptr;
		}
		else
		{
			while (a->get_next() != tail)
			{
				if (b->get_data_second() <	 a->get_data_second())
				{
					b = a;
				}

				a = a->get_next();

				if (a->get_next() == tail && b->get_data_second() < a->get_data_second())
				{
					b = a;
				}
			}
			if (b->get_data_second() < tail->get_data_second())
			{
				b = tail;
				tail = a;
				delete b;
			}
			else
			{
				if (b == head)
				{
					head = b->get_next();
					delete b;
				}
				else
				{
					a = head;
					while (a->get_next() != b)
					{
						a = a->get_next();
					}
					a->set_next(b->get_next());
					delete b;
				}
			}
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
class PriorityQueue
{
protected:
	CList<Type> Qdata;
	int size;

public:
	PriorityQueue() {
		size = 0;
	}

	void Push(const int pr, const Type val) {
		Qdata.push_back(pr, val);
		size++;
	}

	void Pop() {
		if (isEmpty())
		{
			throw std::logic_error("Empty!");
		}
		Qdata.pop_front();
		size--;
	}

	Type Top() {
		if (isEmpty())
		{
			throw std::logic_error("Empty!");
		}
		return Qdata.GetFirstValue();
	}

	int Size() {
		return size;
	}

	bool isEmpty() {
		if (size == 0) return true;
		else return false;
	}

	void Print() {
		Qdata.print();
	}

	~PriorityQueue()
	{
		Qdata.clear();
	}
};





template <class Type>
class PriorityQueueMode1 : public PriorityQueue <Type>
{

public:
	void Push(const int pr, const Type val) / override /
	{
		Qdata.push_back_priority(pr, val);
		size++;
	}

};




template <class Type>
class PriorityQueueMode2 : public PriorityQueue <Type>
{

public:

	void Pop()
	{
		if (isEmpty())
		{
			throw std::logic_error("Empty!");
		}
		Qdata.pop_front_priority();
		size--;
	}

	Type Top()
	{
		if (isEmpty())
		{
			throw std::logic_error("Empty!");
		}
		return Qdata.GetFirstValuePriority();
	}
};