#include<iostream>
#include<string>
#define max 1000
using namespace std;
struct student//学生结构体
{
	string m_name;
	string m_ID;
	int m_age;
};
struct student_list//存放学生信息的清单
{
	int m_size;
	student student_array[max];
};
//添加学生功能的实现
void add_student(student_list* list)
{
	if (list->m_size == max)
	{
		cout << "学生人数已满！\n";
	}
	cout << "请输入学生姓名：\n";
	string name;
	cin >> name;
	list->student_array[list->m_size].m_name = name;
	cout << "请输入学生学号：\n";
	string ID;
	cin >> ID;
	list->student_array[list->m_size].m_ID = ID;
	cout << "请输入学生年龄：\n";
	int age;
	cin >> age;
	list->student_array[list->m_size].m_age = age;
	list->m_size++;
}
//查找学生功能的实现
void search_student(student_list* list)
{
	string name;
	if (list->m_size == 0)
	{
		cout << "当前未录入学生信息！\n";
		system("pause");
	}
	else
	{
		cout << "请输入学生姓名：\n";
		cin >> name;
	}
	for (int i = 0; i < list->m_size; ++i)
	{
		if (list->student_array[i].m_name == name)
		{
			cout << "学生姓名：" << list->student_array[i].m_name << endl;
			cout << "学生学号：" << list->student_array[i].m_ID << endl;
			cout << "学生年龄：" << list->student_array[i].m_age << endl;
			break;
		}
		else
		{
			cout << "未查找到该学生信息，请确认信息无误！\n";
		}
	}
}
//删除学生功能实现
//先做一个判断学生是否存在的函数
int is_exist(student_list* list,string name)
{
	int student_exist = -1,i= 0;
	for (i = 0; i < list->m_size; ++i)
	{
		if (list->student_array[i].m_name == name)
		{
			return i;
			break;
		}
	}
	return -1;
}
void delete_student(student_list* list)
{
	string name;
	if (list->m_size == 0)
	{
		cout << "当前未录入学生信息，无法删除！\n";
	}
	cout << "请输入学生姓名：";
	cin >> name;
		int ret = is_exist(list, name);
		if (ret == -1)
		{
			cout << "未查找到该学生信息，请确认信息无误！\n";
		}
		else
		{
			for (int i = ret; i < list->m_size; ++i)
			{
				list->student_array[i] = list->student_array[i + 1];
				cout << "该生信息已被删除！";
				list->m_size--;
			}
		}
}
int main()
{
	student_list list;
	list.m_size = 0;
	int select = 0;
	while(true)
	{
	cout << "欢迎来到学生管理系统！\n";
	cout << "1.添加学生。\n";
	cout << "2.查找学生。\n";
	cout << "3.删除学生。\n";
	cout << "4.退出系统。\n";
	//控制功能选择
		cin >> select;
		switch(select)
		{
		case 1:
			add_student(&list);//添加学生功能
			cout << "保存成功！" << endl;
			system("pause");
			system("cls");
			break;
		case 2:
			search_student(&list);//查找学生功能
			system("pause");
			system("cls");
			break;
		case 3:
			delete_student(&list);//删除学生功能
			system("pause");
			system("cls");
			break;
		case 4:
			cout << "感谢使用！";
			return 0;
			break;
		default:
			break;
		}
			
	}
	return 0;
}