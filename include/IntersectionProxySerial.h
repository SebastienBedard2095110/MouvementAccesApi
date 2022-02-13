#pragma once

#include "AbstractChaine.h"

class IntersectionProxySerial : public AbstractChaine {
public:
	IntersectionProxySerial(AbstractChaine* prochain);
	void traiter(Requete requete) override;
};