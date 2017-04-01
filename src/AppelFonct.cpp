#include "AppelFonct.h"
#include <iostream>

using namespace std;

AppelFonct::AppelFonct()
{
	#ifdef MAP
		cout << "Appel au constructeur vide de AppelFonct" << endl;
	#endif
	typeContenu = _APPELFONCT;
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

AppelFonct::AppelFonct(std::string* f, std::vector<Expression*>* param)
{
	#ifdef MAP
		cout << "Appel au constructeur de AppelFonct(std::string* f, std::vector<Expression*>* param)" << endl;
	#endif
    fonction = f;
	parametres = param;
	typeContenu = _APPELFONCT;
}
