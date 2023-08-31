#include <iostream>
#include "learnref.h"

using namespace std;

// 全局变量
int arr[] = { 1, 2, 3, 4, 5 };

// 函数声明
void swap(int& x, int& y);
int& setArrItem(int idx);

void introRef()
{
	//
	// 引用
	//
	// 引用是变量的一个别名。变量其实是程序可以操作的一块存储区的名称，引用相当于同一块存储区的另一个名称。
	// 
	// 引用和指针主要有 3 点不同：
	//	1. 引用必须在定义的同时进行初始化，指针可以先定义然后再初始化；
	//	2. 引用被初始化后不能改变，指针可以随时改变其指向；
	//	3. 不存在空引用，但存在空指针。
	//
	int i = 10;
	int& ri = i; // ri 是一个初始化为 i 的整型引用
	ri = 20; // 对 ri 进行读写 = 对 i 进行读写

	cout << "To learn reference in C++, check 'learnref.cpp'.\n" << endl;
}

//
// C++ 函数支持引用类型的形参，对形参进行操作就是对实参进行操作
// 
// 假设外部存在整型变量 m, n：
//	对于 void swap(int& x, int& y)，调用 swap(m, n) 时，相当于 int& x = m; int& y = n; 即 x 和 y 分别为 m 和 n 的引用，对 x 和 y 的操作相当于对 m 和 n 的操作；
//	对于 void swap(int x, int y)，调用 swap(m, n) 时，相当于 int x = m; int y = n; 即 x 和 y 是两个新的变量，同 m 和 n 没有关系。
//
void swap(int& x, int& y)
{
	int tmp;
	tmp = x;
	x = y;
	y = tmp;
}

//
// C++ 函数支持返回引用
//
// 当函数返回一个引用时，该函数可以放到赋值语句的左边进行，如：
// setsetArrItem(0) = 10; // 相当于 arr[0] = 10
//
int& setArrItem(int idx)
{
	int& ref = arr[idx];
	return ref; // 返回 arr 中第 idx 个元素的引用
}