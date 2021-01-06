#pragma once
#include <iostream>
#include <fstream>
#include <string>

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

///Функция разбивающая один файл на два других по заданному количеству элементов
void split(ifstream& origin, ofstream& file1, ofstream& file2, int count) //Принимает на вход ссылки на исходный файл и те на которые он будет разбит
{
    string buffer; //Строка в которую будут временно записаны данные из исходного файла

    getline(origin, buffer); //Записываем содержимое исходного файла во временное хранилище

    /*
    * Пробешаем по буфферу, и начиная с i-го элемента
    * записываем нужное количество элементов в нужный файл.
    * Переменная j позволяет чередовать записи в файлы,
    * то есть сначала мы записываем количество count элементов в первый файл,
    * а затем такое же количество во второй файл, но уже с позиции i+count.
    * После каждой записи в файл увеличивается j, чтобы следующий кусок данных
    * записался в нужный файл.
    */
    for (int i = 0, j = 0; i < buffer.size(); i += count)
    {
        if (j % 2 != 0)
            file2 << buffer.substr(i, count);
        else
            file1 << buffer.substr(i, count);
        j++;
    }
    /*
    * здесь не нужно открывать или закрывать файлы, 
    * так как это будет сделано в функции, где будет вызвана эта функция.
    */
}

///Функция сортировки прямым слиянием на 3-х файлах:
void direct_merge()
{
    const char* name1 = "origin.txt", *name2 = "file_a.txt",
        *name3 = "file_b.txt", *name4 = "file_c.txt";

    create_random_file(name1);
    int count = 1;
    string buffer;
    ifstream file_in1(name1), file_in2;
    ofstream file_out1(name2), file_out2;
    try //Обработка исключения -- открыт ли файл
    {
        if (!file_in1.is_open() || !file_out1.is_open())
            throw "Ошибка. Файл не был открыт!";
    }
    catch (string error)
    {
        cout << error << endl;
    }
    file_in1 >> buffer;
    file_out1 << buffer;

    file_in1.close();
    file_out1.close();

    for (int count = 1; ; count *= 2)
    {
        file_in1.open(name2);
        file_out1.open(name3);
        file_out2.open(name4);
        split(file_in1, file_out1, file_out2, count);
        file_in1.close();
        file_out1.close();
        file_out2.close();
        file_in1.open(name3);
        file_in2.open(name4);
        file_out1.open(name2);
        for (;;)
        {

        }
    }
}