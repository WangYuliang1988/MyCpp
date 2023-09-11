//
// Pupil.h
//
// 小学生类，用于学习 C++ 继承相关知识
//
#ifndef _WYL_PUPIL
#define _WYL_PUPIL

#include <iostream>
#include "Student.h"
#include "YoungPioneer.h"

//
// 继承
// 
// 子类可以继承父类中标记为 protected/public 的成员变量和成员函数。
// 
// 语法格式：class son: access_symbol father_A, access_symbol father_B, ... {};
//
// 其中，访问修饰符用来指定继承自父类的成员会成为子类的 public/protected/private 成员。
//
class Pupil : public Student, public YoungPioneer
{
private:
    bool mYoungPioneer; // 是否少先队员（年龄满6周岁、未满14周岁且经过组织审批同意）
public:
    //
    // 构造函数
    //
    // 定义子类对象时，编译器会：
    //  1. 首先，自动调用父类的构造函数，对父类的成员进行初始化；
    //  2. 然后，调用子类的构造函数，对子类的成员进行初始化。
    // 
    // 编译器自动调用父类构造函数时：
    //  1. 若父类只有有参构造函数，则子类必须使用构造函数成员初始化列表，指明要调用的父类的有参构造函数，并传递对应的值；
    //  2. 若父类同时包含无参和有参构造函数，则默认调用父类的无参构造函数。若要调用父类的有参构造函数，则子类须使用构造函数成员初始化列表。
    //
    Pupil(); // 父类调用无参构造函数
    explicit Pupil(bool isPioneer); // 父类调用无参构造函数
    Pupil(char* name, float score, bool isPioneer, int level) : Student(name, score), YoungPioneer(level) // 父类调用有参构造函数
    {
        mYoungPioneer = isPioneer;
    }
    Pupil(const Pupil& obj); // 父类调用无参构造函数

    //
    // 析构函数
    //
    // 销毁子类对象时，编译器会：
    //  1.首先，调用子类的析构函数，完成子类的析构工作；
    //  2.然后，调用父类的析构函数，完成父类的析构工作。
    //
    ~Pupil();
    
    //
    // 普通成员函数
    //
    void setYoungPioneer(bool isPioneer);
    bool isYoungPioneer();
    void print();
};

#endif // !_WYL_PUPIL