#include<iostream>
using namespace std;
//重载运算符意义：提升代码的简洁性
//1.通过成员函数重载运算符
class person
{
public:
	person operator+(person& p)//加上&的作用：避免拷贝出一份新的数据，提升效率
	{
		person temp;
		temp.m_a = p.m_a + this->m_a;
		temp.m_b = p.m_b + this->m_b;
		return temp;
	}
	person()//默认构造函数
	{

	}
	person(int a, int b)//参数构造函数，给person类对象赋值
	{
		m_a = a;
		m_b = b;
	}
public:
	int m_a = 0;
	int m_b = 0;
};
void test01()
{
	person p1(10, 10);
	person p2(20, 20);
	person p3;
	p3 = p1 + p2;//p3 = p1 + p2;属于简化版本。成员函数原版：p3 = p2.operator+(p1);
	cout << p3.m_a << " " << p3.m_b << endl;
}
//2.通过全局函数重载运算符
class people
{
public:
	int m_a = 0;
	int m_b = 0;
};
people operator+(people &p1, people &p2)
{
	people temp;
	temp.m_a = p1.m_a + p2.m_a;
	temp.m_b = p1.m_b + p2.m_b;
	return temp;
}
void test02()
{
	people p1, p2,p3;
	p1.m_a = 10;
	p1.m_b = 10;
	p2.m_a = 20;
	p2.m_b = 20;
	p3 = p1 + p2;   //全局函数原版：p3 = operator+(p1,p2);
	cout << p3.m_a << " " << p3.m_b << endl;
}
//3.运算符重载发生函数重载：person数据类型 + int数据类型
people operator+(people& p, int &num)
{
	people temp;
		temp.m_a = p.m_a + num;
		temp.m_b = p.m_b + num;

		return temp;
}
void test03()
{
	people p1, p2;
	p1.m_a = 10;
	p1.m_b = 10;
	int num = 100;
	p2 = p1 + num;
	cout << p2.m_a << " " << p2.m_b << endl;
}
int main()
{
	test01();
	test02();
	test03();
	return 0;
}