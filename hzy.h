#include <iostream>
#include <fstream>
#include <string.h>
#include <conio.h>
#include <stdio.h>
#include<windows.h>
using namespace std;
class student{
public: char name[20];
		char id[20];
		int chinese;
		int math;
		int english;
		int sum;
		student* next;
		void input()
		{
			cout << "������ѧ��������";
			cin >> name;
			cout << "������ѧ��ѧ�ţ�";
			cin >> id;
			cout << "���������ĳɼ���";
			cin >> chinese;
			cout << "��������ѧ�ɼ���";
			cin >> math;
			cout << "������Ӣ��ɼ���";
			cin >> english;
			sum = chinese + math + english;
		}
		void ReadFile(istream & in)
		{
			in >> name >> id >> chinese >> math >> english >> sum;
		}
		void show()
		{
			cout << "������" << name << endl << "ѧ�ţ�" << id << endl << "���ĳɼ���" << chinese << endl << "��ѧ�ɼ���" << math << endl << "Ӣ��ɼ���" << english << endl << "�ܷ֣�" << sum << endl;
		}
};