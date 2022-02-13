#pragma once 

#include <ArduinoJson.h>
#include "ApiAccesWifi.h"



ApiAccesWifi::ApiAccesWifi(AbstractChaine* prochain, const char* urlApi)
	: AbstractChaine(prochain),
		client(),
		urlApi(urlApi)
{ ; }


void ApiAccesWifi::traiter(Requete requete) {
	if( strlen(requete.clef) == 0 ) {
		return;
	}

	if(WiFi.status() != WL_CONNECTED) {
		Serial.println("[!] Echec connexion WiFi.");
		return ;
	}

	
	client.begin(urlApi);
	client.addHeader("Content-Type", "application/json");
	
	DynamicJsonDocument chargeUtile(2048);
	chargeUtile["cleUtilisateur"] = requete.clef;
	chargeUtile["idBorne"]        = requete.borneId;
	char chargeJSON[2048];
	serializeJson(chargeUtile, chargeJSON);

	Serial.println("\n\nTransfert vers API:");
	Serial.print("\t");
	Serial.println(chargeJSON);
	int codeReponse = client.POST(chargeJSON);


	if(codeReponse != 200) {
		Serial.print("[!] Erreur depuis ApiAcces: ");
		Serial.println(codeReponse);
		Serial.println(HTTPClient::errorToString(codeReponse));
		return;
	}
	
	String reponse = client.getString();
	client.end();


	DynamicJsonDocument resultat(2048);
	DeserializationError erreur = deserializeJson(resultat, reponse);
	if(erreur)
		return;

	strncpy(requete.action, resultat["type"], 50);
	faireSuivre(requete);
}

