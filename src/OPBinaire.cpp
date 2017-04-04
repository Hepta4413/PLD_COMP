#include "OPBinaire.h"
#include <iostream>

using namespace std;

OPBinaire::OPBinaire()
{
	#ifdef MAP
		cout << "Appel au constructeur vide de OPBinaire" << endl;
	#endif
	typeContenu = _OPBINAIRE;
}

OPBinaire::OPBinaire(Expression* ex1, Expression* ex2, Opbinaire ope)
{
	#ifdef MAP
		cout << "Appel au constructeur de OPBinaire(Expression* ex1, Expression* ex2, Opbinaire ope)" << endl;
	#endif
	e1 = ex1;
	e2 = ex2;
	op = ope;
	typeContenu = _OPBINAIRE;
}

void OPBinaire::setBloc(Bloc* blc)
{
	#ifdef MAP
		cout << "Appel a la fonction setBloc de OPBinaire" << endl;
	#endif
    blocParent = blc;
	e1->setBloc(blc);
	e2->setBloc(blc);
}

vector<Variable*> OPBinaire::variableUtilise(){
	#ifdef MAP
		cout << "Appel a la fonction variableUtilise de opBinaire" << endl;
	#endif
	vector<Variable*> result;
	vector<Variable*> vector1=e1->variableUtilise();
	vector<Variable*> vector2=e2->variableUtilise();
	result.insert( result.end(), vector1.begin(), vector1.end() );
	result.insert( result.end(), vector2.begin(), vector2.end() );
	return result;
}

Type OPBinaire::calculType()
{
	#ifdef MAP
		cout << "Appel a la fonction calculType de OPBinaire" << endl;
	#endif
	Type typeE1 = e1->calculType();
	Type typeE2 = e2->calculType();
	if(typeE1==CONSTVAL_T || typeE2==CONSTVAL_T || typeE1==typeE2)
	{
		type=(typeE1==CONSTVAL_T?typeE2:typeE1);
		return type;
	}
	else
	{
		#ifdef WAR
		cerr<<"Warning ligne "<<getLigne()<<" : "
			<<getColonne()<<" opération sur des types différents "<<typeE1<<" "<<typeE2<<endl;
		#endif
		return INT32_T;

	}
}
