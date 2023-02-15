#include <set>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>

void menu()
{
	std::cout << "\n------------------------------------------\n";
	std::cout << "1 - Set A and set B \n2 -Intersection of A and B  \n3 - Union of A and B \n4 - Difference of A and B \n5 - Complement of set A \n6 - exit";
	std::cout << "\n------------------------------------------\n";
}

void print()
{

}

int main()
{
	int mode;
	std::set <int> sA;
	std::set <int> sB;
	menu();
	
	
	do
	{
		std::cin >> mode;
		switch (mode)
		{
			
			case 1:
			{
				int size;
				std::cout << "Enter size of set A: ";
				std::cin >> size;
				for (int i = 0; i < size; i++)
				{
					int a;
					std::cout << "Enter the numbers: ";
					std::cin >> a;
					sA.insert(a);
				}

				for (std::set<int>::iterator it = sA.begin(); it != sA.end(); ++it)
				{
					std::cout << *it << ' ';
				}
				std::cout << '\n';

				std::cout << "\nEnter size of set B: ";
				std::cin >> size;
				for (int i = 0; i < size; i++)
				{
					int a;
					std::cout << "Enter the numbers: ";
					std::cin >> a;
					sB.insert(a);
				}

				for (std::set<int>::iterator it = sB.begin(); it != sB.end(); ++it)
				{
					std::cout << *it << ' ';
				}
				std::cout << '\n';

				break;
			}

			case 2:
			{
				std::vector <int> sE;
				std::set_intersection(sA.begin(), sA.end(),
					sB.begin(), sB.end(),
					std::back_inserter(sE));
				std::cout << "Intersection of A and B: ";
				for (std::vector<int>::iterator it = sE.begin(); it != sE.end(); ++it)
				{
					std::cout << *it << ' ';
				}
				std::cout << '\n';
		    break;
			}

			case 3:
			{
				std::vector <int> sE;
				std::set_union(sA.begin(), sA.end(),
					sB.begin(), sB.end(),
					std::back_inserter(sE));
				std::cout << "Union of A and B: ";
				for (std::vector<int>::iterator it = sE.begin(); it != sE.end(); ++it)
				{
					std::cout << *it << ' ';
				}
				std::cout << '\n';
				break;
			}

			case 4:
			{
				std::vector <int> sE;
				std::set_difference(sA.begin(), sA.end(),
					sB.begin(), sB.end(),
					std::back_inserter(sE));
				std::cout << "Difference of A and B: ";
				for (std::vector<int>::iterator it = sE.begin(); it != sE.end(); ++it)
				{
					std::cout << *it << ' ';
				}
				std::cout << '\n';
				break;
			}

			case 5:
			{
				std::vector <int> sU;
				int size;
				std::cout << "Enter size of set U: ";
				std::cin >> size;
				for (int i = 0; i < size; i++)
				{
					int a;
					std::cout << "Enter the numbers: ";
					std::cin >> a;
					sA.insert(a);
				}

				std::vector <int> sE;
				std::set_difference(sU.begin(), sU.end(),
					sA.begin(), sA.end(),
					std::back_inserter(sE));
				for (std::vector<int>::iterator it = sE.begin(); it != sE.end(); ++it)
				{
					std::cout << *it << ' ';
				}
				std::cout << '\n';
				break;
			}

			case 6:
			{
				break;
			}

			default:
			{
				std::cout << "ERROR: you imput wrong mode number please imput from 1 to 7!!!";

				break;
			}

	    }
	} while (mode != 6);
}





