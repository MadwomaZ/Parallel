#include <iostream>
#include <ctime>
#include <iomanip>
#include <cstdlib>

void bubbleSort(int* arrayPtr, int length_array)
{
 int temp = 0;
 bool exit = false;
 
 while (!exit)
 {
  exit = true;
  for (int int_counter = 0; int_counter < (length_array - 1); int_counter++)
    if (arrayPtr[int_counter] > arrayPtr[int_counter + 1])
    {
     temp = arrayPtr[int_counter];
     arrayPtr[int_counter] = arrayPtr[int_counter + 1];
     arrayPtr[int_counter + 1] = temp;
     exit = false;
    }
 }
}

int main()
{
	int **mass = new int* [6]; // две строки в массиве
	    for (int count = 0; count < 6; count++)
		{
	        	mass[count] = new int [6];
		}
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			mass[i][j] = rand() % 100 + 1;
		}
		std::cout << std::endl;
	}
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			bubbleSort(mass[j], 6);
			std::cout << std::setw(20);
			std::cout << mass[j][i];
		}
		std::cout << std::endl;
	}
        std::cout << "\nruntime = " << clock()/1000.0 << std::endl;
	return 0;
}

