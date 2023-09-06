#include <iostream>
#include "learnoop.h"
#include "Student.h"

using namespace std;

void introOop()
{
	//
	// C++ 创建对象
	// 
	// 创建对象，其实就是定义并初始化一个类类型的变量，创建出的对象位于栈上
	// 
	// 方式一：显式调用构造函数创建对象
	//
	Student unknown = Student();
	Student jack = Student("Jack");
	Student tom = Student("Tom", 98.5f);
	Student dave = Student(unknown); // 注意：该初始化调用的是拷贝构造函数，可简写为 Student dave = unknown;
	//
	// 方式二：隐式调用构造函数创建对象
	//
	Student hUnknown; // Student()
	Student hJack("Jack"); // Student("Jack")
	Student hTom("Tom", 98.5f); // Student("Tom", 98.5f)
	Student hDave(hUnknown); // Student(hUnknown);
	//
	// 方式三：列表初始化
	// 
	// 注意：创建对象的列表初始化同类的构造函数成员初始化列表没有关系
	//
	Student lsUnknown{}; // Student()
	Student lsJack{ "Jack" }; // Student("Jack")
	Student lsTom{ "Tom", 98.5f }; // Student("Tom", 98.5f)
	Student lsDave{ lsUnknown }; // Student(lsUnknown);

	// 
	// C++ 创建对象指针
	//
	// 除了直接创建具名对象，还可以通过 new 隐式地创建对象并返回指向对象的指针，该方式创建的对象位于堆上
	//
	// 该情况下对象没有名字，只能通过对象指针来操作对象，对象指针使用 '->' 操作符来访问对象成员
	// 
	// 如：Student* pStu = new Student(); // Student* 是类类型指针类型，pStu 是类类型指针，指向 Student 类类型变量（即对象）的地址
	//
	// 方式一：构造函数
	//
	Student* pUnknown = new Student();
	Student* pJack = new Student("Jack");
	Student* pTom = new Student("Tom", 98.5f);
	Student* pDave = new Student(*pUnknown);
	//
	// 方式二：列表初始化
	//
	Student* plsUnknown = new Student{};
	Student* plsJack = new Student{ "Jack" };
	Student* plsTom = new Student{ "Tom", 98.5f };
	Student* plsDave = new Student{ *plsUnknown };
	//
	// new 创建对象指针时隐式创建的对象位于堆上，不会自动清除，需要手动调用 delete 释放内存
	//
	delete pUnknown;
	delete pJack;
	delete pTom;
	delete pDave;
	delete plsUnknown;
	delete plsJack;
	delete plsTom;
	delete plsDave;

	cout << "To learn OOP in C++, check 'Student.h' and 'learnoop.cpp'.\n" << endl;
}