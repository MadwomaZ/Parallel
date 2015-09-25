#include <iostream>
#include <ctime>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <thread>
#include <mutex>

using namespace std;

void *massive(int i);

int **mass = new int* [6]; // две строки в массиве

std::mutex barrier;

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
	std::vector<std::thread> t;

	for (int i = 0; i < 6; i++)
	{
		t.push_back(thread(&massive, i));
	}
	for (auto& thread : t)
	{
		thread.join();
	}
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			std::cout << std::setw(10);
			std::cout << mass[j][i];
		}
		std::cout << std::endl;
	}
	std::cout << "\nruntime = " << clock()/1000.0 << std::endl;

	return 0;
}

void *massive(int i)
{
	barrier.lock();
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			bubbleSort(mass[j], 6);
		}
	}
	barrier.unlock();
        	
}
