#include "College.h"

College::College()
{
	mMajor = new char[8] { "Unknown" };
}

College::College(const College& obj)
{
	size_t len = strlen(obj.mMajor);
	mMajor = new char[len];
	strcpy(mMajor, obj.mMajor);
	mNeedClear = true;
}

College::~College()
{
	if (mNeedClear)
	{
		delete mMajor;
	}
}

void College::setMajor(char* major)
{
	this->mMajor = major;
}

char* College::getMajor()
{
	return mMajor;
}

void College::print()
{
	cout << "College " << getName() << ", id: " << cGetId() << ", score: " << getScore();
	cout << ", major: " << mMajor << endl;
}
