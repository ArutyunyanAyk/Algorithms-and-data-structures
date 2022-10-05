#include <vector>
#include <algorithm>
#include <iostream>

 
int main()
{
	int max = 100;
	int min = -100;
	srand(time(0));
	std::vector <int> myVector(20);

	for (int i = 0; i < myVector.size(); i++);

		
	for (int i = 0; i < myVector.size(); i++)
	{
		myVector[i] = -100 + rand() % 201;
		std::cout << " " << myVector[i] << " ";
	}
	std::cout << "\n\n";

	int maxval = *max_element(myVector.begin(), myVector.end());
	int minval = *min_element(myVector.begin(), myVector.end());
	std::cout << "max value:" << maxval <<"\n";
	std::cout << "min value:" << minval;
	std::cout << "\n\n";
	
	sort(myVector.begin(), myVector.end());
	for (int i = 0; i < myVector.size(); i++)
	{
		std::cout << " " << myVector[i] << " ";
	}
	std::cout << "\n\n";

	myVector.insert(myVector.cend(), { 21, 22, 23, 24 });

	for (int i = 0; i < myVector.size(); i++)
	{
		std::cout << " " << myVector[i] << " ";
	}
	std::cout << "\n\n";

	std::replace_if(myVector.begin(), myVector.end(), [](int x) { return x < 10; }, 0);
	for (int i = 0; i < myVector.size(); i++)
	{
		std::cout << " " << myVector[i] << " ";
	}
	std::cout << "\n\n";

	std::for_each(myVector.begin(), myVector.end(), [](int a) 
		{
			if (a > 20)
			{
				std::cout << " " << a << "  ";
			}
		});
	std::cout << "\n\n";
	
	std::for_each(myVector.begin(), myVector.end(), [](int& a)
		{
			if (a % 2 == 0)
			{
				a = a * 3;
				std::cout << " " << a << " ";
			}
			else
			{
				std::cout << " " << a << " ";
			}
		});
	std::cout << "\n\n";

	std::random_shuffle(myVector.begin(), myVector.end());
	for (int i = 0; i < myVector.size(); i++)
	{
		std::cout << " " << myVector[i] << " ";
	}
	std::cout << "\n\n";

	myVector.erase(std::remove_if(myVector.begin(), myVector.end(), [](int x) {return x > 50; }), myVector.end());
	
	for (int i = 0; i < myVector.size(); i++)
	{
		std::cout << " " << myVector[i] << " ";
	}
	std::cout << "\n\n";

	std::cout << " " << "Elem count:" << myVector.size() << "\n\n";
	
	if (myVector.size() % 2 != 0)
	{
		myVector.erase(myVector.end() - 1);
	}
	else
	{
		std::reverse(myVector.begin(), myVector.end());
	}
	for (int i = 0; i < myVector.size(); i++)
	{
		std::cout << " " << myVector[i] << " ";
	}
	std::cout << "\n\n";

	return 0;
}