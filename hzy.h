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
			cout << "请输入学生姓名：";
			cin >> name;
			cout << "请输入学生学号：";
			cin >> id;
			cout << "请输入语文成绩：";
			cin >> chinese;
			cout << "请输入数学成绩：";
			cin >> math;
			cout << "请输入英语成绩：";
			cin >> english;
			sum = chinese + math + english;
		}
		void ReadFile(istream & in)
		{
			in >> name >> id >> chinese >> math >> english >> sum;
		}
		void show()
		{
			cout << "姓名：" << name << endl << "学号：" << id << endl << "语文成绩：" << chinese << endl << "数学成绩：" << math << endl << "英语成绩：" << english << endl << "总分：" << sum << endl;
		}
};