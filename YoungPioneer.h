//
// YoungPioneer.h
//
// 少先队员类，用于同小学生类（Pupil）、学生类（Student）一起演示多重继承，以及抽象类。
//
#ifndef _WYL_YOUNG_PIONEER
#define _WYL_YOUNG_PIONEER

//
// 抽象类
//
// 类中只要有一个成员函数是纯虚函数，则该类为抽象类。
//
// 特性：
//	1. 抽象类无法实例化对象；
//	2. 抽象类不能用作参数类型、函数返回类型、显式转换类型；
//	3. 可以定义指向抽象类的指针和引用，该指针和引用可指向抽象类的子类对象。
//
// 抽象类一般用作父类，用于实现多态。若继承自抽象类的子类未定义全部纯虚函数，则该子类依然是抽象类。
//
class YoungPioneer
{
	int mLevel; // 默认 private
public:
	YoungPioneer();
	YoungPioneer(int level);
	~YoungPioneer();

	int getLevel();
	void setLevel(int level);

	//
	// 纯虚函数
	//
	// 类中声明的无需实现的虚函数，称为纯虚函数。
	//
	// 语法格式：
	//	virtual return_type func_name(param) = 0;
	//
	virtual bool shouldUpgrade() = 0;
};

#endif // !_WYL_YOUNG_PIONEER