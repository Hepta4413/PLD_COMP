#include "Return.h"
#include <iostream>

using namespace std;

Return::Return()
{
	#ifdef MAP
		cout << "Appel au constructeur vide de Return" << endl;
	#endif
}

Return::Return(Expression* e)
{
	#ifdef MAP
		cout << "Appel au constructeur vide de Return(Expression* e)" << endl;
	#endif
	toReturn = e;
}
