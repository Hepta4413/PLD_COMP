#include "Expression.h"
#include <iostream>

using namespace std;

Expression::Expression()
{
	#ifdef MAP
		cout << "Appel au constructeur vide de Expression" << endl;
	#endif
}

Expression::Expression(Type t)
{
	#ifdef MAP
		cout << "Appel au constructeur de Expression(Type t)" << endl;
	#endif
	type = t;
}
