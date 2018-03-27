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
		cout << "����һ����ϵͳ����������ѧ����Ϣ��" << endl;
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
		cout << "��ȡѧ����Ϣ�ɹ���" << endl;
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
	cout << "            ѧ���ɼ�����ϵͳ               " << endl;
	cout << "*******************************************" << endl;
	cout << "*             1.����ѧ���ɼ�              *" << endl;
	cout << "*             2.��ʾѧ���ɼ�              *" << endl;
	cout << "*             3.����ͳ�Ƴɼ�              *" << endl;
	cout << "*             4.����ѧ���ɼ�              *" << endl;
	cout << "*             5.ɾ��ѧ���ɼ�              *" << endl;
	cout << "*             6.�޸�ѧ���ɼ�              *" << endl;
	cout << "*             7.�г���������              *" << endl;
	cout << "*             8.����ϵͳ����              *" << endl;
	cout << "*             0.��ȫ�˳�ϵͳ              *" << endl;
	cout << "*******************************************" << endl;
	cout << "\n\t��ѡ���ܣ�";
}

void control::find()
{
	char name[20], id[10];
	int x;
	student *p = NULL;
	cout << "************************" << endl;
	cout << "   1.��ѧ������������     "
		 << "   2.��ѧ����ѧ�Ų���     " << endl;
	cout << "************************" << endl;
	cout << "\n\t��ѡ��";
	cin >> x;
	switch (x)
	{
	case 1:{
		cout << "\t������Ҫ���ҵ�ѧ����������";
		cin >> name;
	if (p = Finditem(name))
		{
			p->next->show();
			cout << "���������ַ�����������";
			_getch();
		}
		else
		{
			cout << "û���ҵ���������ѧ����" << endl;
			cout << "���������ַ�����������";
			_getch();
		}
	}break;
	case 2:
	{
		cout << "\t������Ҫ���ҵ�ѧ����ѧ�ţ�";
		cin >> id;
		if (p = FindID(id))
		{
			p->show();
			cout << "���������ַ�����������";
			_getch();
		}
		else
		{
			cout << "û���ҵ���ѧ�ŵ�ѧ����" << endl;
			cout << "���������ַ�����������";
			_getch();
		}
	}
	}
}
void control::change()
{
	char name[20];
	student *p = NULL;
	cout << "������Ҫ�޸ĵ�ѧ����������";
	cin >> name;
	if (p = Finditem(name))
	{
		cout << "���ҵ���ѧ����Ϣ���������µ���Ϣ" << endl;
		p->next->input();
		cout << "�޸ĳɹ���" << endl;
		cout << "���������ַ�����������";
		_getch();
	}
	else
	{
		cout << "û���ҵ���������ѧ����" << endl;
		cout << "���������ַ�����������";
		_getch();
	}
}

void control::remove()
{
	char name[20];
	student *p = NULL, *temp = NULL;
	cout << "������Ҫɾ����ѧ����������";
	cin >> name;
	if (p = Finditem(name))
	{
		temp = p->next;
		p->next = p->next->next;
		delete temp;
		cout << "ɾ���ɹ���" << endl;
		cout << "���������ַ�����������";
		_getch();
	}
	else
	{
		cout << "û���ҵ���ѧ����" << endl;
		cout << "���������ַ�����������";
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
	cout << "�����С���" << endl;
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
	cout << "������ɣ�" << endl;
	cout << "���������ַ�����������";
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
		cout << "����һ����ϵͳ���������ù���Ա���룡" << endl;
		cout << "�����ù���Ա���룺";
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
				cout << "��֤�ɹ���" << endl;
			}
			else
			{
				cout << "����������˳�ϵͳ��" << endl;
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
	cout << "ɾ���ɹ���" << endl;
	_getch();
}

int main()
{
	int x, i = 0;
	char y[10];
	bool quit = false;
	cout << "��������Ĺ���Ա���룺";
	cin >> y;
	control hzy;
	hzy.check(y);
	cout << "\t\t\t\t��������������" << endl;
	cout << "\t\t\t\t��ӭ����ѧ���ɼ�����ϵͳ��" << endl;
	cout << "\t\t\t\t��������������" << endl;
	cout << "\n���������ʼ����";
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
