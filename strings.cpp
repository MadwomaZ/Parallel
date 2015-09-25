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
 
     int main() 
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
			std::cout << "Empty string in " << num << std::endl;
		}
	}
      //   std::thread t[num_threads];
 
        //for (int i = 0; i < num_threads; ++i) 
//	{
  //           t[i] = std::thread(call_from_thread, i);
    //     }

//        std::cout << "Launched from the main\n";
 
 //       for (int i = 0; i < num_threads; ++i) 
//	{
  //           t[i].join();
    //     }
 
         return 0;
     }
