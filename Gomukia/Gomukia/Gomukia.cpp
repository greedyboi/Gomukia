// Gomukia.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Handler.h"
#include <ctime>

int main()
{
	Handler h;

	srand(time(0));

	h.handle();
	return 0;
}

