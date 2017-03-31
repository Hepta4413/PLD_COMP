#include "Ligne.h"
#include <iostream>

using namespace std;

Ligne::Ligne()
{
	#ifdef MAP
		cout << "Appel au constructeur vide de Ligne" << endl;
	#endif
}

void Ligne::AddLigneColonne(int ligne,int colonne)
{
	#ifdef MAP
		cout << "Appel a la fonction AddLigneColonne de Ligne(int ligne, int colonne)" << endl;
	#endif
	this->ligne=ligne;
	this->colonne=colonne;
}

