#include <iostream>
#include <stdio.h>

using namespace std;

void create_random_file(FILE* f)
{
    const char* name = "f.txt";
    int* a, n;
    cout << "Введите количество элементов, которые хотите записать в файл: ";
    cin >> n;

    a = new int[n];
    f = fopen(name, "wt");

    if (f == NULL)
    {
        cout << "Проблемы при открытии файла!\n";
    }
    else
        for (int i = 0; i < n; i++)
        {
            a[i] = rand() % 10;
            fprintf(f, "%d ", a[i]);
        }
    fclose(f);
}

int main()
{
    FILE* f, * f1, * f2, * f3;
    const char* name1, * name2, * name3;
    create_random_file(f);

    return 0;
}