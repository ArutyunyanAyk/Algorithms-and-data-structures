#include <iostream>
using namespace std;


template <class Type> class TPair;
template <class Type> std::ostream& operator <<(std::ostream& out, const TPair<Type>& pair);

template <class Type>
class TPair {
	Type first;
	Type second;
public:
	TPair() : first(0), second(0) {}

	void veryImportantFunc();

	TPair operator +<Type>(const TPair& right)
	{
		TPair coord;

		coord.first = this->firstx + right.first
		coord.second = this->second + right.second;

		return coord;
	}

	TPair <Type> operator =(const TPair& right)
		{
			if (this == &right) 
			{
				return *this;
			}
	
			first = right.first;
			second = right.second;
	
			return *this;
		}

	friend std::ostream& operator<< <Type>(std::ostream& out, const TPair& pair);
};



template <class Type>
void TPair<Type>::veryImportantFunc() {
	std::cout << "Very important information: type of this class field have size " << sizeof(Type) << std::endl;
}

template <class Type>
std::ostream& operator <<(std::ostream& out, const TPair<Type>& pair) {
	out << "(" << pair.first << ", " << pair.second << ")" << std::endl;
	return out;
}

int main() {
	TPair<int> coords;

	coords.veryImportantFunc();
	std::cout << coords << std::endl;

	return 0;
}


//class Coordinates
//{
//public:
//	int x;
//	int y;
//
//	Coordinates()
//	{
//		x = 0;
//		y = 0;
//	}
//	
//	Coordinates(int x1,int y1)
//	{
//		x = x1;
//		y = y1;
//	}
//
//	Coordinates operator +(const Coordinates& right)
//	{
//		Coordinates coord;
//
//		coord.x = this->x + right.x;
//		coord.y = this->y + right.y;
//
//		return coord;
//	}
//
//	Coordinates operator =(const Coordinates& right)
//	{
//		if (this == &right) 
//		{
//			return *this;
//		}
//
//		x = right.x;
//		y = right.y;
//
//		return *this;
//	}
//
//	friend ostream& operator<<(ostream& os, const Coordinates& dt);
//};
//
//ostream& operator <<(ostream& os, const Coordinates& dt)
//{
//	os << dt.x << '/' << dt.y;
//
//	return os;
//}
//
//int main()
//{
//	Coordinates b(5, 6), c(4, 6);
//
//	b = b + c;
//
//	cout << b;
//
//	return 0;
//}