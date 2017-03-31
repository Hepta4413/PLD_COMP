#ifndef LIGNE_H
#define LIGNE_H

#include "Contenu.h"

//class Contenu;

class Ligne : public Contenu
{
	public:
	Ligne();
	void AddLigneColonne(int ligne,int colonne);
	int getSize();
	
	private:
	int ligne;
	int colonne;
		
};

#endif
