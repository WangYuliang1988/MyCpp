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
#include "Student.h"
#include "Pupil.h"

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

	//
	// static
	//
	// static 关键字具有以下作用：
	//	1. 限定全局变量只能在定义该变量的文件内使用；
	//	2. 限定函数只能在定义该函数的文件内使用；
	//	3. 让局部变量在程序生命周期内存活，不再随函数的结束而结束，且只进行一次初始化；
	//	4. 将类的成员变量和成员函数变为静态成员变量和静态成员函数，实现多个同类对象之间的数据共享。
	//

	// 引用
	introRef();

	// 面向对象
	introOop();

	//
	// 运算符重载
	// 
	// Student 类中对 -/+/= 运算符进行了重载
	// 
	// 注意：此处重载的 '=' 是赋值运算符，是对一个已存在的对象进行赋值，而不是调用拷贝构造函数：
	//	1.调用拷贝构造函数：Student stu = jack; // 假设 jack 是已存在的 Student 对象
	//	2.进行赋值运算：Student stu; stu = jack; // 假设 jack 是已存在的 Student 对象
	//
	cout << "Operator Overloading:" << endl;
	Student andy = { "Andy", 90.f };
	cout << " Student minus float: " << andy - 10.f << endl;
	cout << " Student plus float: " << andy + 10.f << endl;
	Student bob = {"Bob", 80.f};
	bob = andy; // 自定义的 "=" 重载函数只对 mScore 进行赋值
	cout << " Student Bob now has the same score with Andy: " << bob.getScore() << "\n" << endl;

	//
	// 类型转换
	//
	// static_cast
	// 
	// 语法：
	//	static_cast<type>(expression)
	// 
	// 说明：
	//	1. 用于基本数据类型之间的转换；
	//	2. 用于父类-子类之间指针或引用的转换；
	//	2. 转换是不安全的（即不保证转换结果是正确的）。
	//
	cout << "Use static_cast to:\n";
	float scF = 3.14f;
	int scI = static_cast<int>(scF);
	cout << " convert float " << scF << " to int " << scI << endl;
	void* scVp = { "hi" };
	float* scFp = static_cast<float*>(scVp); // 将字符串指针经 void 指针中介转换为浮点型指针，可以转换成功，但转换结果没有意义（不安全）
	cout << " convert void pointer to float pointer, result can be nonsense: " << *scFp << endl;
	Student* scpStu = new Student();
	Pupil* scpPu = static_cast<Pupil*>(scpStu); // 将父类型指针转换为子类型指针，可以转换成功，但是获取到的子类信息是错误的（不安全）
	cout << " convert Student pointer to Pupil pointer, fail to get Pupil member 'level': " << scpPu->getLevel() << endl;
	delete scpStu;
	scpStu = NULL;
	scpPu = NULL;
	//
	// dynamic_cast
	// 
	// 语法：
	//	dynamic_cast<type>(expression)
	// 
	// 说明：
	//	1. 用于父类-子类之间指针或引用的转换；
	//	2. 父类必须含有虚函数，否则编译报错；
	//	3. type 只能是类指针、类引用、void* 中的一种；
	//	4. 运行时转换（另外三种转换都是编译时转换），若转换失败，则返回 NULL。
	//
	cout << "Use dynamic_cast to:" << endl;
	Student* dcpStu = new Student();
	Pupil* dcpPu = dynamic_cast<Pupil*>(dcpStu); // 将父类型指针转换为子类型指针，转换失败，返回 NULL
	cout << " fail to convert Student pointer to Pupil pointer, result: " << dcpPu << endl;
	delete dcpStu;
	dcpStu = NULL;
	//
	// const_cast
	// 
	// 语法：
	//	const_cast<type>(expression)
	// 
	// 说明：
	//	1. 去除指向常量的指针或引用的常量性，使得可以通过指针或引用修改对应常量的值；
	//	2. type 必须是指针或引用，且除 const 修饰外，type 和 expression 的类型相同。
	//
	const int CI = 10;
	const int* p = &CI;
	//*p = 20; // 报错，因为 p 指向常量，不能通过 *p = xxx 来改变 CI 的值
	int* q = const_cast<int*>(p);
	*q = 20; // 成功
	cout << "Use const_cast to:\n change const variable by pointer, ";
	cout << "CI: " << CI << "(0x" << &CI << "), "; // 注意：CI 的值仍然是 10，即使通过调试可以看到其内存存储的值是 20 ！
	cout << "p: " << *p << "(0x" << p << "), ";
	cout << "q: " << *q << "(0x" << q << ")" << endl;
	//
	// reinterpret_cast
	// 
	// 语法：
	//	reinterpret_cast<type>(expression)
	// 
	// 说明：
	//	1. 将某种类型的指针或引用转换为任意其他类型的指针或引用；
	//	2. 将一个指针或引用转换为一个整数；
	//	3. 将一个整数转换为一个指针或引用；
	//	4. 转换时只是进行纯粹的比特位拷贝，谨慎使用。
	//
	int* rcPi = new int(10);
	double* rcPd = reinterpret_cast<double*>(rcPi);
	cout << "Use reinterpret_cast to:\n convert int pointer to double pointer, ";
	cout << "rcPi: " << *rcPi << "(0x" << rcPi << "), " << "rcPd:" << *rcPd << "(0x" << rcPd << ")" << endl;

	//
	// 虚继承（虚基类）
	//
	// 解决继承的二义性问题。考虑这样一种情况：
	//
	// 类 A 包含一个公开的成员变量 int i，类 B、类 C 公开继承类 A，则 B、C 各自包含一个成员变量 int i。
	//
	// 此时又有一个类 D，公开继承类 B 和 类 C，那么 D 中将包含两个成员 i，一个继承自 B，一个继承自 C。
	// 
	// 如果通过类 D 的对象去访问 i，编译会报错，因为无法确认 i 的来源。对此，有两种解决方式：
	//
	// 方式一：保持 D 中含有两个 i，在访问时指明 i 的来源。
	//	D d = D();
	//	d.B::i; // 指明访问的是 B 的成员 i
	//
	// 方式二：类 B 和类 C 继承类 A 时添加 virtual 修饰，使类 A 的继承路径上，子类中都只保留一份类 A 的成员，即类 D 中只有一个 i。
	//	class B: virtual public A {...};
	//	class C: virtual public A {...};
	//	class D: public B, public C {...};
	//	D d = D();
	//	d.i; // D 中只包含一个成员变量 i，可直接调用
	//
}
