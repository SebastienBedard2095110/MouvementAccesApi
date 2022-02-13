#include <Arduino.h> 

#include "LecteurRFIDProxy.h"

LecteurRFIDProxy::LecteurRFIDProxy(AbstractChaine* prochain, const int RX, const int TX)
	: AbstractChaine(prochain),
		RX(RX),
		TX(TX)
{ 
	Serial2.begin(9600, SERIAL_8N1, RX, TX);
	Serial2.setTimeout(250);
}

void LecteurRFIDProxy::traiter(Requete requete) {
	if(Serial2.available() <= 0)
		return;
	
	Requete reception = {0};
	uint8_t* data = (uint8_t*) &reception;
	int nombreLu = Serial2.readBytes(data, sizeof(Requete));
	if(nombreLu != sizeof(reception)) {
		Serial.println("[!] Erreur reception Serial");
		Serial.print("\tLue: ");
		Serial.println(nombreLu);
		Serial.print("\tAttendu: ");
		Serial.println(sizeof(Requete));
	}
	

	strcpy(requete.clef, reception.clef);

	faireSuivre(requete);
}
