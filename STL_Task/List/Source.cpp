#include <iostream>
#include <algorithm>
#include <list>

int main()
{

	std::list<int> Mylist;
	srand(time(0));
	

	int f = 0;
	while (f != 5) 
	{
		int n = 0 + rand() % 100;
		Mylist.push_back(n);
		++f;
	}

	auto iter = Mylist.begin();
	
	for (iter = Mylist.begin(); iter != Mylist.end(); ++iter)
	{
		std::cout << *iter << std::endl;
	}
	std::cout << "\n\n";
	std::cout << "---------------------\n";

	auto iterb = Mylist.begin();

	std::cout << *iterb << std::endl;
	std::cout << "\n\n";
	std::cout << "---------------------\n";



	Mylist.push_front(15);
	Mylist.push_front(36);

	for (iter = Mylist.begin(); iter != Mylist.end(); ++iter)
	{
		std::cout << *iter << std::endl;
	}
	std::cout << "\n\n";
	std::cout << "---------------------\n";



	std::list<int>::iterator itr_del = Mylist.begin();

	for (int i = 0; i < 3; i++)
	{

		++itr_del;
	}


	Mylist.erase(itr_del);
	

	for (iter = Mylist.begin(); iter != Mylist.end(); ++iter)
	{
		std::cout << *iter << std::endl;
	}
	std::cout << "\n\n";
	std::cout << "---------------------\n";


	auto ietr_rand = 0 + rand() % Mylist.size();
	for (int i = 0; i < 3; i++)
	{
		std::list<int>::iterator itr_rand = Mylist.begin();
		int rundpos = rand() % (Mylist.size() + 1);
		advance(itr_rand, rundpos);
		Mylist.insert(itr_rand, 5);
	}

	for (iter = Mylist.begin(); iter != Mylist.end(); ++iter)
	{
		std::cout << *iter << std::endl;
	}
	std::cout << "\n\n";
	std::cout << "---------------------\n";

	
	Mylist.pop_back();
	for (iter = Mylist.begin(); iter != Mylist.end(); ++iter)
	{
		std::cout << *iter << std::endl;
	}
	std::cout << "\n\n";
	std::cout << "---------------------\n";


	std::list<int>::iterator itr_middle = Mylist.begin();
	int pos = Mylist.size() / 2;
	advance(itr_middle, pos);
	Mylist.insert(itr_middle, { 8, 6 });

	for (iter = Mylist.begin(); iter != Mylist.end(); ++iter)
	{
		std::cout << *iter << std::endl;
	}
	std::cout << "\n\n";
	std::cout << "---------------------\n";

	Mylist.sort();

	Mylist.unique();
	
	for (iter = Mylist.begin(); iter != Mylist.end(); ++iter)
	{
		std::cout << *iter << std::endl;
	}
	std::cout << "\n\n";
	std::cout << "---------------------\n";

	Mylist.clear();

	
	if (Mylist.empty())
		std::cout << "The list is empty" << std::endl;
	else
		std::cout << "The list is not empty" << std::endl;


}