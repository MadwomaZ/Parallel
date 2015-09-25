/*Autor: Alginina Evgeniya 
 *Программа ищет пустые строки в файле и печатает номер строки, которые пустые.
 */
#include <iostream>
#include <fstream>
#include <thread>
#include <string>
#include <vector>
 
void readFile(std::vector<std::string> *strings)
{
    std::string str;
    std::ifstream ios("mass_tr.cpp", std::ios::in);
    while (getline(ios, str))
    {
        strings->push_back(str);
//        std::cout << str << '\n';
    }
}

void empty_string(std::vector<std::string> *strings, int tid, int numtr)
{
    for(int i = 0; i < strings->size(); i++)
        if(i % numtr == tid)
            if (strings->at(i).length() == 0)
                std::cout << "In thread of " << tid <<  " empty string " << i + 1 << std::endl;
//    int num = 0;
//    std::string str;
//    std::ifstream ios("mass_tr.cpp");
//    while(ios.good())
//    {
//        num++;
//        std::getline(ios, str);
//        if (str.length() == 0)
//        {
//            std::cout << "In thread of" << tid <<  " empty string " << num << std::endl;
//        }
//    }
}
	
int main()
{
    int numtr = 0;
    std::cout << "Enter the number of threads: ";
    std::cin >> numtr;
    std::vector<std::string> strings;

    std::thread t[numtr];

    readFile(&strings);

    for (int i = 0; i < numtr; ++i)
        t[i] = std::thread(empty_string, &strings, i, numtr);

    std::cout << "Launched from the main\n";

    for (int i = 0; i < numtr; ++i)
        t[i].join();
 
    return 0;
}
