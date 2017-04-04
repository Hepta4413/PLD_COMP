#include "Ligne.h"
#include <iostream>

using namespace std;

Ligne::Ligne()
{
	#ifdef MAP
		cout << "Appel au constructeur vide de Ligne" << endl;
	#endif
	typeContenu = _LIGNE;
}

void Ligne::AddLigneColonne(int ligne,int colonne)
{
	#ifdef MAP
		cout << "Appel a la fonction AddLigneColonne de Ligne(int ligne, int colonne)" << endl;
	#endif
	this->ligne=ligne;
	this->colonne=colonne;
}

int Ligne::getLigne()
{
	#ifdef MAP
		cout << "Appel a la fonction getLigne de Ligne" << endl;
	#endif
	return ligne;
}

int Ligne::getColonne()
{
	#ifdef MAP
		cout << "Appel a la fonction getColonne de Ligne" << endl;
	#endif
	return colonne;
}

int Ligne::getSize()
{
	return 0;
}

string Ligne::buildIR(CFG * cfg) {
	return "";
}
