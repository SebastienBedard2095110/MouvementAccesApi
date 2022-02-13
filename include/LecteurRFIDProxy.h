#pragma once

#include "AbstractChaine.h"



class LecteurRFIDProxy : public AbstractChaine {
private:
	const int RX;
	const int TX;


public:
	LecteurRFIDProxy(AbstractChaine* prochain, const int RX, const int TX);
	void traiter(Requete requete) override;

};