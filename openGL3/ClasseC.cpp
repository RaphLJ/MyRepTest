#include "ClasseC.h"
#include <stdio.h>


ClasseC::ClasseC()
{
	printf("coucou, classe cree\n");
}

ClasseC::ClasseC(int param)
{
	AccX = param;
}


ClasseC::~ClasseC()
{
}
