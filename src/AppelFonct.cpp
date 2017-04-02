#include "AppelFonct.h"
#include <iostream>

using namespace std;

AppelFonct::AppelFonct()
{
	#ifdef MAP
		cout << "Appel au constructeur vide de AppelFonct" << endl;
	#endif
	typeContenu = _APPELFONCT;
	fonctionAssocie=NULL;
}

AppelFonct::AppelFonct(std::string* f, std::vector<Expression*>* param)
{
	#ifdef MAP
		cout << "Appel au constructeur de AppelFonct(std::string* f, std::vector<Expression*>* param)" << endl;
	#endif
    fonction = f;
    if(param==NULL)
    {
		parametres = new vector<Expression*>();
	}
	else
	{
		parametres = param;
	}
	
	typeContenu = _APPELFONCT;
	fonctionAssocie=NULL;
}

vector<Variable*> AppelFonct::variableUtilise(){
	#ifdef MAP
		cout << "Appel a la fonction variableUtilise de AppelFonct" << endl;
	#endif
	vector<Variable*> result;
	 for(auto expr = parametres->begin(); expr != parametres->end(); expr++) {
		vector<Variable*> resultIntermediaire = (*expr)->variableUtilise();
		result.insert( result.end(), resultIntermediaire.begin(), resultIntermediaire.end() );
	  }
	return result;
}

vector<Expression*>* AppelFonct::getParam()
{
	#ifdef MAP
		cout << "Appel a la fonction getParam de AppelFonct" << endl;
	#endif
	return parametres;
}

Fonction* AppelFonct::getFonctionAssocie()
{
	#ifdef MAP
		cout << "Appel a la fonction getFonctionAssocie de AppelFonct" << endl;
	#endif
	return fonctionAssocie;
}

void AppelFonct::setFonctionAssocie(Fonction* f)
{
	#ifdef MAP
		cout << "Appel a la fonction setFonctionAssocie de AppelFonct" << endl;
	#endif
	fonctionAssocie = f;
}

string* AppelFonct::getNom()
{
	#ifdef MAP
		cout << "Appel a la fonction getNom de AppelFonct" << endl;
	#endif
	return fonction;
}

Type AppelFonct::calculType()
{
	#ifdef MAP
		cout << "Appel a la fonction calculType de AppelFonct " <<fonctionAssocie<< endl;
	#endif
	if(fonctionAssocie!=NULL)
	{
		type=fonctionAssocie->getTypeRetour();
		return type;
	}
	return INT32_T;
}

