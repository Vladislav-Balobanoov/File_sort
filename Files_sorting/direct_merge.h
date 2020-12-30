#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void split(ifstream& origin, ofstream& file1, ofstream& file2)
{
    string buffer;

    try
    {
        if (!origin.is_open() || !file1.is_open() || !file2.is_open())
            throw "Ошибка. Файл не был открыт!";
    }
    catch (string error)
    {
        cout << error << endl;
    }

    getline(origin, buffer);

    for (int i = 0; i < buffer.size(); i ++)
    {
        switch (i%2)
        {
        case 0:
            file1 << buffer.substr(i, 1);
            break;           
        default:
            file2 << buffer.substr(i, 1);
            break;
        }
    }
}

