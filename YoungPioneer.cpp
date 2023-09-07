#include "YoungPioneer.h"

YoungPioneer::YoungPioneer()
{
	mLevel = 0;
}

YoungPioneer::YoungPioneer(int level)
{
	mLevel = level;
}

YoungPioneer::~YoungPioneer()
{
	// nothing to do here
}

int YoungPioneer::getLevel()
{
	return mLevel;
}

void YoungPioneer::setLevel(int level)
{
	this->mLevel = level;
}