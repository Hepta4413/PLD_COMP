#include "Expression.h"
#include <iostream>

using namespace std;

Expression::Expression()
{
	#ifdef MAP
		cout << "Appel au constructeur vide de Expression" << endl;
	#endif
	typeContenu = _EXPR;
}

Expression::Expression(Type t)
{
	#ifdef MAP
		cout << "Appel au constructeur de Expression(Type t)" << endl;
	#endif
	type = t;
	typeContenu = _EXPR;
}

Type Expression::getType()
{
	#ifdef MAP
		cout << "Appel a la fonction getType de Expression" << endl;
	#endif
	return type;
}

string Expression::buildIR(CFG * cfg) {
	return "";
}
