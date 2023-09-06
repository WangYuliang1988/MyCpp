#include "Student.h"

//
// 在类的外部定义成员函数
//
// 普通成员函数语法格式为：
//	return_type class_name::func_name(param) {}
// 
float Student::getScore()
{
	return mScore;
}
void Student::setScore(float score)
{
	mScore = score;
}
//
// 构造函数语法格式为：
//	class_name::class_name(param) {}
//
Student::Student(char* name)
{
	mName = name;
	mScore = -1.0f;
}
//
// 拷贝构造函数语法格式为：
//	class_name::class_name(const class_name& param) {}
//
Student::Student(const Student& obj)
{
	// mId 在定义时已初始化，无需在构造函数中再进行赋值

	// 为 mName 分配新内存，避免与 obj 的 mName 指向相同内存
	char* oName = obj.mName;
	size_t len = strlen(oName);
	mName = new char[len + 1];
	strcpy(mName, oName);

	// mScore 为基础数据类型，直接赋值
	mScore = obj.mScore;
}
//
// 析构函数语法格式为：
//	class_name::~class_name() {}
//
Student::~Student()
{
	if (mNeedClear)
	{
		delete mName;
	}
}
//
// 运算符重载函数语法格式为：
//	return_type class_name::operator[oper_symbol](param) {}
//
float Student::operator-(float f)
{
	return mScore - f;
}
float Student::operator+(float f)
{
	return this->mScore + f;
}
void Student::operator=(const Student& obj)
{
	mScore = obj.mScore;
}