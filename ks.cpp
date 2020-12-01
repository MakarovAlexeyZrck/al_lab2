#include "ks.h"
int ks::MAX_ID = 0;
ks::ks()
{
	id = ++MAX_ID;
}