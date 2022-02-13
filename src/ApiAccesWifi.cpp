#pragma once 

#include <ArduinoJson.h>
#include "ApiAccesWifi.h"



ApiAccesWifi::ApiAccesWifi(AbstractChaine* prochain, const char* urlApi)
	: AbstractChaine(prochain),
		client(),
		urlApi(urlApi)
{ ; }


void ApiAccesWifi::traiter(Requete requete) {
		strncpy(requete.action, "ACTION", 50);


	// if( strlen(requete.clef) == 0 ) {
	// 	return;
	// }
	// if(WiFi.status() != WL_CONNECTED) {
	// 	Serial.println("Echec connexion WiFi.");
	// 	return ;
	// }

	
	// client.begin(urlApi);
	// client.addHeader("Contente-Type", "Content-Type: application/json");
	
	// DynamicJsonDocument chargeUtile(2048);
	// chargeUtile["clef"]    = requete.clef;
	// chargeUtile["borneId"] = requete.borneId;
	// chargeUtile["date"]    = requete.date;
	// char chargeJSON[2048];
	// serializeJson(chargeUtile, chargeJSON);

	// int codeReponse = client.POST(chargeJSON);


	// if(codeReponse != 200) {
	// 	Serial.print("Erreur depuis ApiAcces: ");
	// 	Serial.println(HTTPClient::errorToString(codeReponse));
	// 	return;
	// }
	
	// String reponse = client.getString();
	// client.end();


	// DynamicJsonDocument resultat(2048);
	// DeserializationError erreur = deserializeJson(resultat, reponse);
	// if(erreur) {
	// 	return;
	// }

	// strncpy(requete.action, resultat["action"], 50);
	faireSuivre(requete);
}

