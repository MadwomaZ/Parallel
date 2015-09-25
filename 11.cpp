#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

void Vernam_encry()
{
   int len = 0; //Определяем необходимые переменные

   string plTxt; // = new string[len]; //объявляем динамический массив указанной длины для открытого текста
   string key; // = new string[len];  //точно такой же массив объявляем для ключа
   string shStr; // = new string[len];  //массив-приемник для зашифрованного текста

   cout << "Enter you plainext: ";
   //while(plTxt.get() != '\n')
   //{
      // ++len;
       getline(std::cin, plTxt);
   len = plTxt.length();// определяем длину строки открытого текста
   key.reserve(len+1);
   shStr.reserve(len+1);
   //}
   //plTxt="Holo word!";   //помещаем в массив открытый текст
// определяем ключ случайным образом
   for(int i = 0; i < len; i++) {
      key[i]=(char)(rand()%52 + 'A');
      std::cout << "written:" << i << key[i] << std::endl;
   }
   cout << "\nKey: " << key << endl;
//собственно само шифрование
   for(int i = 0; i < len; i++)
      shStr[i]=plTxt[i]^key[i]; //побитовое XOR
//для наглядности выведем на экран результат работы
   cout << "\nOtkrytyi text: " << plTxt << endl;
   cout << "\nKey: " << key << endl;
   cout << "\nZashifrovanyi text: " << shStr << endl;
}

int main()
{
    Vernam_encry();
    return 0;
}


