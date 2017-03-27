#include "AppelFonct.h"

AppelFonct::AppelFonct()
{
}


AppelFonct::AppelFonct(std::string* f, std::vector<Expression*>* param)
{
    fonction = f;
	parametres = param;
}
