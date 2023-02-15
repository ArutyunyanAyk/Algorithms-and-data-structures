#include <vector>
#include <algorithm>
#include <iostream>

void menu()
{
    std::cout << "\n------------------------------------------\n";
    std::cout << "1 - Set the matrix \n2 - Sum \n3 - Subtraction \n4 - Multiplication on vector multiplication on other matrix \n5 - Transpose \n6 - exit";
    std::cout << "\n------------------------------------------\n";
}

int main()
{
    int w = 0;
    int max = 9;
    srand(time(0));
    std::vector<std::vector<int>> Matrix_1;
    std::vector<std::vector<int>> Matrix_2;
    std::vector<std::vector<int>> Matrix_buff;
    int size;

    std::cout << " Input size for matrix: ";
    std::cin >> size;
    for (int i = 0; i < size; i++)
    {
        std::vector<int> myvector(size, 0);
        for (int j = 0; j < size; j++)
            Matrix_buff.push_back(myvector);
    }

    for (int i = 0; i < size; i++)
    {
        std::vector<int> myvector(size, 0);
        for (int j = 0; j < size; j++)
            Matrix_1.push_back(myvector);
    }

    for (int i = 0; i < size; i++)
    {
        std::vector<int> myvector(size, 0);
        for (int j = 0; j < size; j++)
            Matrix_2.push_back(myvector);
    }

    int mode;
    
    do
    {
        menu();
        std::cout << "Enter mode: ";
        std::cin >> mode;

        switch (mode)
        {
        case 1:
        {       do
        {
            int t;
            std::cout << " If you wonna random Matrix type <1>, If you wonna enter values manually type <2>:";
            std::cin >> t;
            if (t == 1)
            {
                for (int i = 0; i < size; i++)
                {
                    for (int j = 0; j < size; j++)
                    {
                        if (i <= j) { Matrix_buff[i][j] = rand() % 9; }
                    }
                }

            }
            else
            {
                std::cout << "Imput volues : " << std::endl;
                for (int i = 0; i < size; i++)
                {
                    for (int j = 0; j < size; j++)
                    {
                        if (i <= j) { std::cin >> Matrix_buff[i][j]; }
                    };
                }
            }
            if (w == 0)
            {
                for (int i = 0; i < size; i++)
                {
                    for (int j = 0; j < size; j++)
                        Matrix_1[i][j] = Matrix_buff[i][j];
                }
                for (int i = 0; i < size; i++) {
                    for (int j = 0; j < size; j++)
                        std::cout << "   " << Matrix_1[i][j];
                    std::cout << std::endl;
                }
            }
            else
            {
                for (int i = 0; i < size; i++)
                {
                    for (int j = 0; j < size; j++)
                        Matrix_2[i][j] = Matrix_buff[i][j];
                }
                for (int i = 0; i < size; i++) {
                    for (int j = 0; j < size; j++)
                        std::cout << "   " << Matrix_2[i][j];
                    std::cout << std::endl;
                }
            }


            w += 1;
        } while (w != 2);
        break;
        }
        case 2:
        {
            for (int i = 0; i < size; i++)
                for (int j = 0; j < size; j++)
                    Matrix_buff[i][j] = Matrix_1[i][j] + Matrix_2[i][j];

            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++)
                    std::cout << "   " << Matrix_buff[i][j];
                std::cout << std::endl;
            }
            break;
        }
        case 3:
        {
            for (int i = 0; i < size; i++)
                for (int j = 0; j < size; j++)
                    Matrix_buff[i][j] = Matrix_1[i][j] - Matrix_2[i][j];

            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++)
                    std::cout << "   " << Matrix_buff[i][j];
                std::cout << std::endl;
            }
            break;
        }
        case 4:
        { 
            int m = 0;
            std::cout << "If you wonna multiply matrix by matrix type <1>, multiply matrix by vector type <2>:";
            std::cin >> m;
            if (m == 1)
            {
                for (int i = 0; i < size; i++)
                {
                    for (int j = 0; j < size; j++)
                        for (int k = 0; k < size; k++)
                            Matrix_buff[i][j] += Matrix_1[i][j] * Matrix_2[k][j];
                }

                for (int i = 0; i < size; i++) {
                    for (int j = 0; j < size; j++)
                        std::cout << "   " << Matrix_buff[i][j];
                    std::cout << std::endl;
                }
            }
            else
            {
                int v = 0;
                int v1 = 0;
                std::vector <int> myVector(size, 0);
                std::cout << "If you wonna random Matrix type <1>, If you wonna enter values manually type <2>:";
                std::cin >> v;
                if (v == 1)
                {
                    for (int i = 0; i < myVector.size(); i++)
                    {
                        myVector[i] = rand() % 9;
                    }

                }
                else
                {
                    std::cout << "Imput volues : " << std::endl;
                    for (int i = 0; i < size; i++)
                    {
                        
                        std::cin >> myVector[i];
                     
                    }
                }
                std::cout << "For multiply vector to matrix 1 type <1>, for multiply vector to matrix 2 type <2>";
                std::cin >> v1;
                    
                if (v1 == 1)
                {
                    for (int i = 0; i < size; i++)
                    {
                        for (int j = 0; j < size; j++)
                        {
                            Matrix_buff[i][j] = Matrix_1[i][j] * myVector[i];
                        }
                    }
                    for (int i = 0; i < size; i++) {
                        for (int j = 0; j < size; j++)
                            std::cout << "   " << Matrix_buff[i][j];
                        std::cout << std::endl;
                    }
                }
                else
                {
                    for (int i = 0; i < size; i++)
                    {
                        for (int j = 0; j < size; j++)
                        {
                            Matrix_buff[i][j] = Matrix_2[i][j] * myVector[i];
                        }
                    }
                    for (int i = 0; i < size; i++) {
                        for (int j = 0; j < size; j++)
                            std::cout << "   " << Matrix_buff[i][j];
                        std::cout << std::endl;
                    }
                }
                

            }
            break;
            
        }
        case 5:
        {
            int t1 = 0;
            std::cout << "Transpose matrix 1 type <1>, tr matrix 2 type <2>";
            std::cin >> t1;
            if (t1 == 1)
            {
                for (int i = 0; i < size; i++)
                {
                    for (int j = 0; j < size; j++) {
                        Matrix_buff[j][i] = Matrix_1[i][j];
                    }
                }
                for (int i = 0; i < size; i++) {
                    for (int j = 0; j < size; j++)
                        std::cout << "   " << Matrix_buff[i][j];
                    std::cout << std::endl;
                }
            }
            else
            {
                for (int i = 0; i < size; i++)
                {
                    for (int j = 0; j < size; j++) {
                        Matrix_buff[j][i] = Matrix_2[i][j];
                    }
                }
                for (int i = 0; i < size; i++) {
                    for (int j = 0; j < size; j++)
                        std::cout << "   " << Matrix_buff[i][j];
                    std::cout << std::endl;
                }
            }
            
            break;
        };
        case 6:
        {
            break;
        }
        default:
        {
            std::cout << "ERROR: you imput wrong mode number please imput from 1 to 6!!!";

            break;
        }
            break;
        }
        } while (mode != 6);

       return 0;
    }