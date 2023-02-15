#include <iostream>

template <class Type>

class Stack
{
	Type* arr;
	int top;
	size_t size;
public:
	Stack(int size_)
	{
		arr = new Type[size_];
		size = size_;
		top = -1;
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

		top--;

		return b;
	}

	void push_mid(int a)
	{
		if (is_full())
		{
			throw std::logic_error("is full");
		}

		if (is_empty())
		{
			this->push(a);
		}
		else 
		{
			Stack<Type> stack_2((top + 1) / 2);
			int b = (top + 1) / 2;

			while (b != 0)
			{
				stack_2.push(this->pop());
				b--;
			}

			this->push(a);

			while (!stack_2.is_empty())
			{
				this->push(stack_2.pop());
			}
		}
	}

	void push(int a)
	{
		if (is_full())
		{
			throw std::logic_error("is_full");
		}

		arr[top + 1] = a;

		top++;
	}

	bool is_full()
	{
		if (top == size - 1)
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
		if (top == -1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void reverse()
	{
		/*Stack<Type> stack_2(size);

		while (!this->is_empty())
		{
			stack_2.push(this->pop());
		}
		this = stack_2;*/

		Stack<Type> stack_2(size);

		Stack<Type> stack_3(size);

		while (!this->is_empty())
		{
			stack_2.push(this->pop());
		}
		while (!stack_2.is_empty())
		{
			stack_3.push(stack_2.pop());
		}
		while (!stack_3.is_empty())
		{
			this->push(stack_3.pop());
		}
	}

	/*Stack<Type>& operator =(const Stack<Type>& s1)
	{
		this->size = s1.size;
		for (int i = 0; i < size; i++)
		{
			this->arr[i] = s1.arr[i];
		}
		return *this;
	}*/

	void print()
	{
		for (int i = 0; i < size; i++)
		{
			std::cout << "|  " << arr[i] << "  |"<< std::endl;	
		}
		std::cout << " " << std::endl;
	}

	~Stack()
	{
		delete[] arr;
	}

};

int main()
{
	Stack<int> s1(4);
	s1.push(4);
	s1.push(5);
	s1.push(6);
	s1.push(7);
	s1.print();

	s1.reverse();
	s1.print();

	
}