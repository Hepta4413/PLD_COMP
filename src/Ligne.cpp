#include "Ligne.h"
#include <iostream>

using namespace std;

Ligne::Ligne()
{
	#ifdef MAP
		cout << "Appel au constructeur vide de Ligne" << endl;
	#endif
}
