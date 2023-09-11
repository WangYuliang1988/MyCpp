#include "Pupil.h"

Pupil::Pupil()
{
	mYoungPioneer = false;
}

Pupil::Pupil(bool isPioneer)
{
	mYoungPioneer = isPioneer;
	setLevel(isPioneer); // 确保若是少先队员，则级别默认是 1（即 true）
}

Pupil::Pupil(const Pupil& obj)
{
	mYoungPioneer = obj.mYoungPioneer;
	setLevel(obj.mYoungPioneer); // 确保若是少先队员，则级别默认是 1（即 true）
}

Pupil::~Pupil()
{
	// nothing to do here
}

bool Pupil::isYoungPioneer()
{
	return mYoungPioneer;
}

void Pupil::setYoungPioneer(bool isPioneer)
{
	this->mYoungPioneer = isPioneer;
}

void Pupil::print()
{
	cout << "Pupil " << getName() << ", id: " << cGetId() << ", score: " << getScore();
	cout << ", pioneer: " << boolalpha << mYoungPioneer << ", level: " << getLevel() << endl; // boolalpha 用于将 bool 值打印为 true/false
}
