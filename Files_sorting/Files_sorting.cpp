#include <iostream>
#include <fstream>
#include <string>
#include "direct_merge.h"

using namespace std;



int main()
{
    setlocale(LC_ALL, "rus");
    const char* name = "origin.txt"; //исходный файл
    const char* name1 = "temp1.txt";  //
    const char* name2 = "temp2.txt";  //вспомогательные файлы для сортировки
    const char* name3 = "temp3.txt";  //
    create_random_file(name);        //создаём исходный файл со случайными числами

    ifstream origin(name);
    ofstream file1(name1), file2(name2);

    split(origin, file1, file2, 3);

    origin.close();
    file1.close();
    file2.close();

    return 0;
}