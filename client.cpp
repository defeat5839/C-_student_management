#include <iostream>
#include <fstream>
#include <string.h>
#include <conio.h>
#include "hzy.h"
#include "helios.h"

control::control()
{
	head = new student;
	head->next = new student;
	end = head->next;
	in.open("sort.txt");
	if (!in)
		cout << "这是一个新系统，请先输入学生信息！" << endl;
	else
	{
		while (!in.eof())
		{
			end->ReadFile(in);
			if (end->name[0] == '\0')
				break;
			end->next = new student;
			end = end->next;
		}
		in.close();
		cout << "读取学生信息成功！" << endl;
	}
}

control::~control()
{
	save();
	for (student *temp ;head->next != end; )
	{
		temp = head->next;
		head->next = head->next->next;
		delete temp;
	}
	delete head, end;
}

void control::showmenu()
{
	cout << "*******************************************" << endl;
	cout << "            学生成绩管理系统               " << endl;
	cout << "*******************************************" << endl;
	cout << "*             1.增加学生成绩              *" << endl;
	cout << "*             2.显示学生成绩              *" << endl;
	cout << "*             3.排序统计成绩              *" << endl;
	cout << "*             4.查找学生成绩              *" << endl;
	cout << "*             5.删除学生成绩              *" << endl;
	cout << "*             6.修改学生成绩              *" << endl;
	cout << "*             7.列出及格人数              *" << endl;
	cout << "*             8.管理系统密码              *" << endl;
	cout << "*             0.安全退出系统              *" << endl;
	cout << "*******************************************" << endl;
	cout << "\n\t请选择功能：";
}

void control::find()
{
	char name[20], id[10];
	int x;
	student *p = NULL;
	cout << "************************" << endl;
	cout << "   1.按学生的姓名查找     "
		 << "   2.按学生的学号查找     " << endl;
	cout << "************************" << endl;
	cout << "\n\t请选择：";
	cin >> x;
	switch (x)
	{
	case 1:{
		cout << "\t请输入要查找的学生的姓名：";
		cin >> name;
	if (p = Finditem(name))
		{
			p->next->show();
			cout << "输入任意字符，继续……";
			_getch();
		}
		else
		{
			cout << "没有找到该姓名的学生！" << endl;
			cout << "输入任意字符，继续……";
			_getch();
		}
	}break;
	case 2:
	{
		cout << "\t请输入要查找的学生的学号：";
		cin >> id;
		if (p = FindID(id))
		{
			p->show();
			cout << "输入任意字符，继续……";
			_getch();
		}
		else
		{
			cout << "没有找到该学号的学生！" << endl;
			cout << "输入任意字符，继续……";
			_getch();
		}
	}
	}
}
void control::change()
{
	char name[20];
	student *p = NULL;
	cout << "请输入要修改的学生的姓名：";
	cin >> name;
	if (p = Finditem(name))
	{
		cout << "已找到该学生信息，请输入新的信息" << endl;
		p->next->input();
		cout << "修改成功！" << endl;
		cout << "输入任意字符，继续……";
		_getch();
	}
	else
	{
		cout << "没有找到该姓名的学生！" << endl;
		cout << "输入任意字符，继续……";
		_getch();
	}
}

void control::remove()
{
	char name[20];
	student *p = NULL, *temp = NULL;
	cout << "请输入要删除的学生的姓名：";
	cin >> name;
	if (p = Finditem(name))
	{
		temp = p->next;
		p->next = p->next->next;
		delete temp;
		cout << "删除成功！" << endl;
		cout << "输入任意字符，继续……";
		_getch();
	}
	else
	{
		cout << "没有找到该学生！" << endl;
		cout << "输入任意字符，继续……";
		_getch();
	}
}

void control::swap(student *p1, student *p2)
{
	student *temp = new student;
	strcpy_s(temp->name, p1->name);
	strcpy_s(temp->id, p1->id);
	temp->chinese = p1->chinese;
	temp->english = p1->english;
	temp->math = p1->math;
	temp->sum = p1->sum;

	strcpy_s(p1->name, p2->name);
	strcpy_s(p1->id, p2->id);
	p1->chinese = p2->chinese;
	p1->english = p2->english;
	p1->math = p2->math;
	p1->sum = p2->sum;

	strcpy_s(p2->name, temp->name);
	strcpy_s(p2->name, temp->name);
	p2->chinese = temp->chinese;
	p2->english = temp->english;
	p2->math = temp->math;
	p2->sum = temp->sum;
}

int control::listcount()
{
	if (!head)
		return 0;
	int n = 0;
	for (student *p = head->next; p != end; p = p->next)
	{
		n++;
	}
	return n;
}

void control::sort()
{
	cout << "排序中……" << endl;
	student *p = NULL, *p1 = NULL, *k = NULL;
	int n = control::listcount();
	for (p = head->next; p != end; p = p->next)
		for (k = p->next; k != end; k = k->next)
	{
		if (p->sum > k->sum)
		{
			control::swap(p, k);
		}
	}
	cout << "排序完成！" << endl;
	cout << "输入任意字符，继续……";
	_getch();
	return;
}

void control::save()
{
	out.open("sort.txt");
	for (student *p = head->next; p != end; p = p->next)
		out << p->name << "\t" << p->id << "\t" << p->sum << "\n";
	out.close();
}

void control::check(char m[10])
{
	char buffer[10];
	in.open("mima.txt");
	if (!in)
	{
		cout << "这是一个新系统，请先设置管理员密码！" << endl;
		cout << "请设置管理员密码：";
		cin >> buffer;
		out.open("mima.txt");
		out << buffer << "\n";
		out.close();
	}
	else
	{
			in.getline(buffer, '\n');
			if (!strcmp(buffer, m))
			{
				cout << "验证成功！" << endl;
			}
			else
			{
				cout << "密码错误，请退出系统！" << endl;
				while (1);
			}
			in.close();
		}
	}

void control::deletemima()
{
	string  c1;
	c1 = "mima.txt";
	DeleteFile(c1.c_str());
	cout << "删除成功！" << endl;
	_getch();
}

int main()
{
	int x, i = 0;
	char y[10];
	bool quit = false;
	cout << "请输入你的管理员密码：";
	cin >> y;
	control hzy;
	hzy.check(y);
	cout << "\t\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆" << endl;
	cout << "\t\t\t\t欢迎进入学生成绩管理系统！" << endl;
	cout << "\t\t\t\t☆☆☆☆☆☆☆☆☆☆☆☆☆" << endl;
	cout << "\n按任意键开始……";
	_getch();
	while (!quit)
	{
		system("cls");
		hzy.showmenu();
		cin >> x;
		switch (x)
		{
		case 0:quit = true; break;
		case 1:hzy.Additem(); break;
		case 2:hzy.display(); break;
		case 3:hzy.sort(); break;
		case 4:hzy.find(); break;
		case 5:hzy.remove(); break;
		case 6:hzy.change(); break;
		case 8:hzy.deletemima(); break;
		}
	}
	return 0;
}
