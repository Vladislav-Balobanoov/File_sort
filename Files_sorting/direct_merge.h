#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

///������� ���������� �� ������������� ����� ���������� �������
void create_random_file(const char* name) //� �������� ��������� ��������� �������� ����� � ������� ����� �������� ��������
{
    ofstream f;   //�������� ������ ����� ofstream ��� ������ � ����
    f.open(name); //��������� ������ ����������� � ����, � ������� ����� ������� ��������(��������� ���� �� ������)
    int* a, n;    //�������� ������, ������� � ����� ������� � ����
    cout << "������� ���������� ���������, ������� ������ �������� � ����: ";
    cin >> n;

    a = new int[n];//���� ������ ���������� ������ ��� �������

    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 10;
        f << a[i]; //��������� �������� �������� ���������������� ������� � ����
    }
    f.close(); //��������� ����
}

///������� ����������� ���� ���� �� ��� ������ �� ��������� ���������� ���������
void split(ifstream& origin, ofstream& file1, ofstream& file2, int count) //��������� �� ���� ������ �� �������� ���� � �� �� ������� �� ����� ������
{
    string buffer; //������ � ������� ����� �������� �������� ������ �� ��������� �����

    getline(origin, buffer); //���������� ���������� ��������� ����� �� ��������� ���������

    /*
    * ��������� �� �������, � ������� � i-�� ��������
    * ���������� ������ ���������� ��������� � ������ ����.
    * ���������� j ��������� ���������� ������ � �����,
    * �� ���� ������� �� ���������� ���������� count ��������� � ������ ����,
    * � ����� ����� �� ���������� �� ������ ����, �� ��� � ������� i+count.
    * ����� ������ ������ � ���� ������������� j, ����� ��������� ����� ������
    * ��������� � ������ ����.
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
    * ����� �� ����� ��������� ��� ��������� �����, 
    * ��� ��� ��� ����� ������� � �������, ��� ����� ������� ��� �������.
    */
}

///������� ���������� ������ �������� �� 3-� ������:
void direct_merge()
{
    const char* name1 = "origin.txt", *name2 = "file_a.txt",
        *name3 = "file_b.txt", *name4 = "file_c.txt";

    create_random_file(name1);
    int count = 1;
    string buffer;
    ifstream file_in1(name1), file_in2;
    ofstream file_out1(name2), file_out2;
    try //��������� ���������� -- ������ �� ����
    {
        if (!file_in1.is_open() || !file_out1.is_open())
            throw "������. ���� �� ��� ������!";
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