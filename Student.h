//
// Student.h
//
// 学生类，用于学习 C++ 类相关知识
//
#ifndef _WYL_STUDENT
#define _WYL_STUDENT

#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

//
// C++ 中类定义语法：
//	class class_name
//	{
//	access specifiers: // 访问修饰符：private/protected/public
//		type variables; // 成员变量
//		return_type func() {}; // 成员函数
//	};
// 
// 访问修饰符的限定范围：
//	private：类的内部可见
//	protected：类及其子类的内部可用
//	public：类的内部、外部均可见
//
class Student
{
private:
	//
	// 成员变量
	//
	char* mName;
	float mScore;
	bool mNeedClear = false; // 是否需要释放 mName 对应的内存，只有当 mName 通过 new 初始化时为 true

	//
	// 常成员变量
	//
	// 初始化后值不能再改变，此处采用定义时初始化的方式进行初始化
	// 
	// 若使用构造函数初始化，则只能采用下面提到的构造函数成员初始化列表方式
	//
	const long long mId = time_point_cast<microseconds>(system_clock::now()).time_since_epoch().count();
public:
	// 
	// 成员函数
	// 
	// 方式一：直接在类中定义，该情况下成员函数自动变为内联函数，即使没有显式声明为 inline 函数。
	char* getName()
	{
		return mName;
	}
	void setName(char* name)
	{
		// 
		// this 指针
		// 
		// C++ 中 this 指针是一个指向当前对象的特殊指针，它并不是类本身的一部分，而是由编译器管理。
		// 
		// this 只能在类的成员函数中使用，它在成员函数开始执行前构造，在成员函数完成执行后清除。
		// 
		// 原理：
		//	假设有一个类 Foo，拥有一个成员函数 func(param)，且 foo 是 Foo 的一个对象，那么：
		//	当执行 foo.func(param) 时，编译器会编译成 Foo::func(&foo, param)，并将 &foo 赋值给 this，然后执行。
		//
		this->mName = name; // 此处的 this 并不是必须的，如果成员函数的形参名称和成员变量相同，则必须使用 this 指针
	}
	// 方式二：在类中声明，在类的外部定义，该情况下成员函数为普通函数，不会自动变为内联函数。
	float getScore();
	void setScore(float score);

	//
	// 常成员函数
	//
	// 函数体内只能读取成员变量的值，不能修改
	// 
	// 若某个成员变量不想受此限制，可在声明该成员变量时用 mutable 关键字进行修饰
	// 
	// 备注：对于常对象，如：const Student CSTU，将只能调用常成员函数，不能调用其它普通成员函数
	//
	void print() const
	{
		cout << mName << ", id: " << mId << ", score: " << mScore << endl;
	}

	// 
	// 构造函数
	// 
	// 构造函数是一种特殊的成员函数，用来在创建对象时对对象进行初始化，如为对象的成员变量赋初始值等。
	//
	// 构造函数遵循成员函数的所有规则，其特殊之处在于：函数名与类名相同，且没有返回类型。语法格式为：
	//	1. 类中定义：class_name(param) {}
	//	2. 类中声明：class_name(param);，外部定义：class_name::class_name(param) {}
	// 
	// 如果开发者未定义构造函数，编译器会自动生成一个默认的无参构造函数。构造函数在对象创建时被系统自动调用。
	//
	Student()
	{
		mName = new char[8] {"Unknown"};
		mNeedClear = true;
		mScore = -1.0f;
	}
	//
	// explicit
	// 
	// 当构造函数只接收一个参数时，C++ 支持用直接赋值为参数对应类型的值的方式创建对象。
	//
	// 例如，假设构造函数为 Student(char* name)，则可通过 Student stu = "Wang"; 创建对象。
	// 
	// 该方式会带来一些便利，但也容易造成混淆，可通过在构造函数前加 explicit 关键字进行禁用。
	//
	explicit Student(char* name);
	//
	// 构造函数成员初始化列表
	// 
	// 一种初始化类成员的方式，在构造函数运行之前直接初始化成员，相比构造函数中赋值更为高效。
	// 
	// 语法格式为：class_name(paramX, paramY) : memberX(paramX), memberY(paramY) {}
	// 
	// 注意：成员变量的初始化顺序按照其在类中的定义顺序进行，跟成员初始化列表的书写顺序无关
	//
	Student(char* name, float score) : mName(name), mScore(score) {}
	//
	// 拷贝构造函数
	//
	// 拷贝构造函数是构造函数的一种，使用已创建的对象来初始化新创建的同类对象。
	// 
	// 拷贝构造函数的定义和使用同普通构造函数一致，特殊之处在于其形参固定为该类的类类型常引用：
	//	class_name(const class_name& obj) {};
	// 
	// 如果开发者未定义拷贝构造函数，则编译器会自动生成一个，默认将已有对象成员的值赋给新建对象中对应的未初始化的成员。
	// 
	// 当类中有指针类型的成员变量时，需要注意：
	//	* 默认的拷贝构造函数会将已有对象中指针成员的值赋给新建对象的指针成员，即两个对象的指针成员指向同一块地址。
	//	* 此时，对一块内存存储内容的修改，会同时影响到多个不同的对象，这在大多数情况下都是不符合预期的。
	// 
	//	* 而且，如果定义了析构函数，且析构函数会释放指针成员对应的内存，将造成同一块内存被释放两次，引发报错。
	// 因此，对于含有指针成员的类，一般会定义一个拷贝构造函数，确保新对象的指针成员指向一个新的地址。
	//
	Student(const Student& obj);

	//
	// 析构函数
	//
	// 析构函数是一种特殊的成员函数，用来在对象销毁时进行一些清理工作，如释放指针成员指向的内存等。
	//
	// 析构函数遵循成员函数的所有规则，其特殊之处在于：函数名固定、无返回类型、无形参、无法重载。语法格式为：
	//	1.类中定义：~class_name() {}
	//	2.类中声明：~class_name(); 外部定义：class_name::~class_name() {}
	//
	// 如果开发者未定义析构函数，编译器会自动生成一个默认的析构函数。析构函数在对象的生命周期结束时被系统自动调用。
	//
	~Student();
};

#endif // !_WYL_STUDENT