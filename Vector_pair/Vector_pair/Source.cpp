#include <vector>
#include <iostream>
#include <iterator>
#include <utility>
#include <algorithm>

using namespace std;

void menu()
{
    std::cout << "\n------------------------------------------\n";
    std::cout << "1 - Enter the pair \n2 - Show all pars \n3 - Change pairs to private \n4 - Exit";
    std::cout << "\n------------------------------------------\n";
}

int main()
{
    int mode;
    enum access {
        Private,
        Public,
        Protected
    };
    
    std::vector <std::pair< access, float> > p{ {access::Private, 5.5}, {access::Public, 7.35}, {access::Protected, 8.63} };
    
    auto iter = p.begin();
    do
    {
        menu();
        std::cin >> mode;
        switch (mode)
        {
            case 1:
            {          
                    int a;
                    std::cout << "Enter the access:\n0 - Private\n1 - Public\n2 - Protected\n ";
                    std::cin >> a;
                    switch (a)
                    {       
                    case 0: 
                    {                 
                        float v = 0;
                        std::cout << "Enter the value: ";
                        std::cin >> v;
                        p.push_back(make_pair(access::Private, v));
                    }
                    break;

                    case 1:
                    {
                        float v = 0;
                        std::cout << "Enter the value: ";
                        std::cin >> v;
                        p.push_back(make_pair(access::Public, v));
                    }
                    break;

                    case 2:
                    {
                        float v = 0;
                        std::cout << "Enter the value: ";
                        std::cin >> v;
                        p.push_back(make_pair(access::Protected, v));
                    }
                    break;

                    default:
                    {
                        std::cout << "Wrong access!!!";
                    }
                        break;
                    }           
                    break;
            }

            case 2:
            {
                for (auto &i : p)
                {
                    std::cout << " [" << i.first << " " << i.second << "]";
                }
                break;
            }

            case 3:
            {
                std::for_each(p.begin(), p.end(), [&](pair <access, float>)
                    {
                        for (auto& i : p)
                        {
                            if (i.first == access::Public)
                            {
                                i.first = access::Private;
                            }
                            else
                            {
                                if (i.first == access::Protected)
                                {
                                    i.first = access::Private;
                                }
                            }
                        }

                    });              
                break;
            }
            default:
            {
                std::cout << "ERROR: you imput wrong mode number please imput from 1 to 4!!!";
            }
                break;
            }
    } while (mode != 4);

    return 0;
	
		
    
}