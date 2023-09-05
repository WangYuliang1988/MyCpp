//
// main.cpp
//
// C++ 是 C 语言的超集，任何合法的 C 程序都是合法的 C++ 程序
//
// C++ 支持多种编程范式：面向对象编程、过程化编程、泛型编程
//
#include <iostream>
#include "learnref.h"
#include "learnoop.h"

using namespace std;

int main()
{
	cout << "Hello, World!\n" << endl;

	//
	// 变量
	//
	// 变量其实只不过是程序可以操作的存储区的名称
	//

	//
	// 数据类型，相比 C 语言，增加如下类型：
	// 
	//	wchar_t：宽字符类型，占 2 个字节，相比 char 类型（占 1 个字节）可以存储更多字符
	//	   bool：布尔类型，占 1 个字节，0 为假，非 0 为真，可搭配 C++ 的 true/false 关键字使用
	//	   auto：自动类型，让编译器自动分析表达式类型
	//
	wchar_t wc = L'C'; // 赋值时左侧加 'L'
	wcout << wc << "++ Types:" << endl; // 打印时用 wcout
	cout << "  wchar_t size: " << sizeof(wchar_t) << " bytes" << endl;
	//
	bool bf = 0;
	bool bt = true;
	cout << "  bool size: " << sizeof(bool) << " bytes" << endl;
	//
	auto ai = 10;
	auto awc = L'C';
	auto apt = &awc;
	cout << "  auto apt's type is: " << typeid(apt).name() << "\n" << endl; // typeid(xxx).name() 可以获取 xxx 对应的类型

	//
	// 范围解析运算符 ::
	//
	// 范围解析运算符用于标识一个标识符所属的范围，通常用于命名空间和类。
	//

	//
	// new 和 delete
	//
	// new 和 delete 是 C++ 用于在堆上占用和释放内存的两个运算符
	//
	// new 语法格式：
	//	type* pointer_name = new type;
	// 
	// new 运算符的内部实现分为两步：
	//	1. 内存分配：调用 operator new(size_t) 函数，完成内存分配；// 对应 C 语言中的 malloc 函数
	//	2. 创建对象：调用构造函数在分配的堆内存上创建相应类型的对象，并返回该内存块的首地址。若构造函数运行失败，则释放分配的内存。
	//
	int* pi = new int;
	cout << "new int without initial value: " << *pi << endl;
	char* pc = new char('C');
	cout << "new char with initial value: " << *pc << endl;
	float* parr = new float[3] {1.2f, 2.4f, 3.6f};
	cout << "new float array: ";
	for (int i = 0; i < 3; i++)
	{
		cout << parr[i];
		if (i != 2)
		{
			cout << ", ";
		}
	}
	cout << "\n" << endl;
	//
	// delete 语法格式：
	//	delete pointer_name;
	//
	// delete 运算符的内部实现分为两步：
	//	1. 清理对象：调用析构函数完成可能涉及的资源释放；
	//	2. 内存释放：调用 operator delete(void*) 函数，释放堆内存。// 对应 C 语言的 free 函数
	//
	delete pi;
	delete pc;
	delete []parr; // 注意释放数组堆内存的语法格式

	// 
	// inline
	//
	// C++ 提供 inline 关键字用以提高函数执行效率，其语法格式为：
	//	inline function_type function_name(params) { ... }
	//
	// 内联函数可以取代宏关于函数内联展开的作用，内联函数会对函数参数等进行类型检查，而宏不会，因此内联函数相比宏更安全。
	//
	// 内联函数是以代码膨胀的代价减少函数调用的开销，只有短小简单的函数适合内联。若函数代码较长或包含循环等复杂逻辑，则不适合内联。
	//

	//
	// 函数重载
	// 
	// 相同的函数名，不同的参数个数或不同的参数类型。
	// 
	// 实现机制：C++ 在编译时会根据函数的参数列表对函数进行重命名，发生调用时，编译器根据传入的实参来匹配对应的函数。
	//

	// 引用
	introRef();

	// 面向对象
	introOop();
}