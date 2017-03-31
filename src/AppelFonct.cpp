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


AppelFonct::AppelFonct(std::string* f, std::vector<Expression*>* param)
{
	#ifdef MAP
		cout << "Appel au constructeur de AppelFonct(std::string* f, std::vector<Expression*>* param)" << endl;
	#endif
    fonction = f;
	parametres = param;
	typeContenu = _APPELFONCT;
}
