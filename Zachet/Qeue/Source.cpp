#include <iostream>
#include <stack>

template <class Type>

class Queue
{
	Type* arr;
	int top;
	size_t size;
	int end;
public:
	Queue(int size_)
	{
		arr = new Type[size_];
		size = size_;
		top = 0;
		end = -1;
	}

	Type Top()
	{
		if (is_empty())
		{
			throw std::logic_error("is_empty");
		}

		return arr[top];
	}

	Type pop()
	{
		if (is_empty())
		{
			throw std::logic_error("is_empty");
		}

		Type b;

		b = arr[top];
		top++;

		return b;
	}

	void push(int a)
	{
		queue_fix();


		if (is_full())
		{
			throw std::logic_error("is_full");
		}
		end++;

		arr[end] = a;
	}

	void push_mid(int a)
	{
		queue_fix();

		if (is_full())
		{
			throw std::logic_error("is full");
		}

		if (is_empty())
		{
			this->push(a);
		}

		Queue<Type> queue_2(end + 1);

		while(!this->is_empty())
		{
			queue_2.push(this->pop());
		}

		int b = (end + 1) / 2;

		while (!queue_2.is_empty())
		{
			if (end == b)
			{
				this->push(a);
			}
			this->push(queue_2.pop());
		}
	}

	bool is_full()
	{
		if (end == size - 1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool is_empty()
	{
		if (end < top)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void queue_reverse()
	{
		std::stack<Type> s1;
		while (!is_empty())
		{
			s1.push(this->pop());
		}
		while (!s1.empty())
		{
			this->push(s1.top());
			s1.pop();
		}
	}

	void print()
	{
		for (int i = 0; i < size; i++)
		{
			std::cout << "|  " << arr[i] << "  |" << std::endl;
		}
		std::cout << " " << std::endl;
	}

	~Queue()
	{
		delete[] arr;
	}

private:
	void queue_fix()
	{
		if (is_full() && top > 0)
		{
			for (int i = top; i  < size; i++)
			{
				arr[i - top] = arr[i];
			}

			end = size - top - 1;

			top = 0;
		}
	}
};

int main()
{
	Queue<int> s1(4);
	
	s1.push(1);
	s1.push(2);
	s1.push(3);
	s1.push(4);
	

}