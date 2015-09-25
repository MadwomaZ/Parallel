/*Autor: Alginina Evgeniya 
 *Программа ищет пустые строки в файле и печатает номер строки, которые пустые.
 */
#include <iostream>
#include <fstream>
#include <thread>
#include <string>
 
//static const int num_threads = 10;
 
     //void call_from_thread(int tid) 
//	{
  //      std::cout << "Launched by thread " << tid << std::endl;
    // }
 
     void empty_string(int tid) 
	{
	int num = 0;
	std::string str;
	std::ifstream ios("mass_tr.cpp");
	while(ios.good())
	{
		num++;
		std::getline(ios, str);
		if (str.length() == 0)
		{
			std::cout << "In thread of" << tid <<  " empty string " << num << std::endl;
		}
	}
	}
	
	int main()
	{
	int numtr = 0;
	std::cout << "Enter the number of threads: ";
	std::cin >> numtr;

         std::thread t[numtr];
 
        for (int i = 0; i < numtr; ++i) 
	{
             t[i] = std::thread(empty_string, i);
         }

        std::cout << "Launched from the main\n";
 
        for (int i = 0; i < numtr; ++i) 
	{
             t[i].join();
         }
 
         return 0;
     }
