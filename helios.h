
class control{
public:control();
	   ~control();
	   void showmenu();
	   void save();
	   void find();
	   void remove();
	   void change();
	   void sort();
	   void swap(student *, student *);
	   void safe();
	   int listcount();
	  void check(char m[10]);
	  void deletemima();
	   void display()
	   {
		   student *p;
		   for ( p= head->next; p != end; p = p->next)
		   p->show();
		   cout << "输入任意字符！继续~~~";
		   _getch();
	   }
	   void Additem()
	   {
		   end->input();
		   end->next = new student;
		   end = end->next;
		   cout << "添加完成！" << endl;
		   cout << "输入任意字符！继续~~~" << endl;
		   _getch();
	   }
        student *head, *end;
		ifstream in;
		ofstream out;
private:student *Finditem(char *name)
		{
			student *p;
			for ( p = head; p->next!=end; p = p->next)
			if (!strcmp(p->next->name, name))
				return p;
			  return NULL;
		}
		student *FindID(char *id)
		{
			student *p;
			for (p = head; p->next != end; p = p->next)
			if (strcmp(p->next->id, id))
				return p;
			return NULL;
		}
};