#include "Return.h"
#include <iostream>

using namespace std;

Return::Return()
{
	#ifdef MAP
		cout << "Appel au constructeur vide de Return" << endl;
	#endif
	typeContenu = _RETURN;
}

Return::Return(Expression* e)
{
	#ifdef MAP
		cout << "Appel au constructeur vide de Return(Expression* e)" << endl;
	#endif
	toReturn = e;
	typeContenu = _RETURN;
}

Expression* Return::getExpression()
{
	#ifdef MAP
		cout << "Appel a la fonction getExpression de Return" << endl;
	#endif
	return toReturn;
}
