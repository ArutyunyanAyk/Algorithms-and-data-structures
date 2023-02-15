#include <iostream>
using namespace std;


template <class Type> class TCoord;
template <class Type> std::ostream& operator <<(std::ostream& out, const TCoord<Type>& pair);

template <class Type>
class TCoord {
	Type x;
	Type y;
public:
	TCoord()
	{
		x = 0;
		y = 0;
	}

	TCoord(Type x1, Type y1)
	{
		x = x1;
		y = y1;
	}

	TCoord operator +(const TCoord& right)
	{
		TCoord coord;

		coord.x = this->x + right.x;
		coord.y = this->y + right.y;

		return coord;
	}

	TCoord operator =(const TCoord& right)
	{
		if (this == &right)
		{
			return this;
		}

		x = right.x;
		y = right.y;

		return this;
	}

	void veryImportantFunc();

	friend std::ostream& operator<< <Type>(std::ostream& out, const TCoord& coord);
};

template <class Type>
void TCoord<Type>::veryImportantFunc() {
	std::cout << "Very important information: type of this class field have size " << sizeof(Type) << std::endl;
}

template <class Type>
std::ostream& operator <<(std::ostream& out, const TCoord<Type>& pair) {
	out << "(" << pair.x << ", " << pair.y << ")" << std::endl;
	return out;
}

int main() {
	TCoord<int> coords;

	coords.veryImportantFunc();
	std::cout << coords << std::endl;

	return 0;
}