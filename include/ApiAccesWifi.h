#pragma once 


#include <HTTPClient.h>

#include "AbstractChaine.h"


class ApiAccesWifi : public AbstractChaine {	
private:
	HTTPClient client;
	const char* urlApi;

public:
	ApiAccesWifi(AbstractChaine* prochain, const char* urlApi);
	void traiter(Requete requete) override;
};