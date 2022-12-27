#include <stack>
#include <iostream>



int main()
{
	std::stack <int> steck;
	int mode;

	do
	{
		std::cin >> mode;
		switch (mode)
		{
			case 1:
			{
				int f = 0;
				
				do
				{
					int c = 0;
					std::cout << "Press <1> to enter the number: ";
					std::cin >> c;
					if (c == 1)
					{
						int a = 0;

						std::cout << "Enter the number: ";
						std::cin >> a;

						steck.push(a);	
					}
					else
					{
						f = 1;
					}
					
				} while (f != 1);
			break;
			}
				
			case 2:
			{
				std::cout << "You delite: " << steck.top();
				steck.pop();
				break;
			}
			
			case 3:
			{
				int b;
				std::stack <int> steck_extra = steck;
				for (int i = 0; i < steck.size(); i++)
				{
					std::cout << steck_extra.top() << "\n";
					steck_extra.pop();		
				}
				
				break;
			}

			case 4:
			{
				while (!steck.empty())
				{
					steck.pop();
				}
				break;
			}
		
		default:
		{
			std::cout << "ERROR: you imput wrong mode number please imput from 1 to 5!!!";

			break;
		}
			break;
		}
	} while (mode !=5);

	return 0;

}