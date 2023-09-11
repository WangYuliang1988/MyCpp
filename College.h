//
// College.h
//
// 大学生类，用于同 Student、Pupil 类一起演示多态
//
#ifndef _WYL_COLLEGE
#define _WYL_COLLEGE

#include "Student.h"

class College : public Student
{
public:
	College();
	College(char* name, float score, char* major) : Student(name, score)
	{
		mMajor = major;
	}
	College(const College& obj);
	~College();

	void setMajor(char* major);
	char* getMajor();
	void print();
private:
	char* mMajor; // 大学专业
	bool mNeedClear = false; // 是否需要释放 mMajor 对应的内存，只有当 mMajor 通过 new 初始化时为 true
};

#endif // !_WYL_COLLEGE

