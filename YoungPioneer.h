//
// YoungPioneer.h
//
// 少先队员类，用于同小学生类（Pupil）、学生类（Student）一起演示多重继承
//
#ifndef _WYL_YOUNG_PIONEER
#define _WYL_YOUNG_PIONEER

class YoungPioneer
{
	int mLevel; // 默认 private
public:
	YoungPioneer();
	YoungPioneer(int level);
	~YoungPioneer();

	int getLevel();
	void setLevel(int level);
};

#endif // !_WYL_YOUNG_PIONEER


