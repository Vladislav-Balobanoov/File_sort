#include <iostream>
#include <fstream>
#include <string>
#include "direct_merge.h"

using namespace std;

///Функция отвечающая за инициализацию файла случайными числами
void create_random_file(const char* name) //В качестве аргумента принемает название файла в который будут записаны значения
{
    ofstream f;   //создаётся объект файла ofstream для записи в файл
    f.open(name); //созданный объект связывается в файл, в который нужно вписать значения(Открываем файл на запись)
    int* a, n;    //создаётся массив, который и будет записан в файл
    cout << "Введите количество элементов, которые хотите записать в файл: ";
    cin >> n;     

    a = new int[n];//берём нужное количество памяти для массива

    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 10;
        f << a[i]; //вписываем элементы случайно сгенерированного массива в файл
    }
    f.close(); //закрываем файл
}

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

    split(origin, file1, file2);

    origin.close();
    file1.close();
    file2.close();

    return 0;
}