//
// main.cpp
//
// C++ 是 C 语言的超集，任何合法的 C 程序都是合法的 C++ 程序
//
// C++ 支持多种编程范式：面向对象编程、过程化编程、泛型编程
//
#include <iostream>
#include "learnref.h"

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
	cout << "  auto apt's type is: " << typeid(apt).name() << "\n" << endl; // typeid(xxx).name() 可以获取 xxx 的类型

	// 引用
	introRef();
}