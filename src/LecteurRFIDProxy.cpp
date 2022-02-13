#include <Arduino.h> 

#include "LecteurRFIDProxy.h"

LecteurRFIDProxy::LecteurRFIDProxy(AbstractChaine* prochain, const int RX, const int TX)
	: AbstractChaine(prochain),
		RX(RX),
		TX(TX)
{ 
	Serial2.begin(9600, SERIAL_8N1, RX, TX);
}

void LecteurRFIDProxy::traiter(Requete requete) {
	if(Serial2.available() <= 0)
		return;
	
	Requete reception;
	uint8_t* data = (uint8_t*) &reception;
	int nombreLu = Serial2.readBytes(data, sizeof(reception));
	if(nombreLu != sizeof(reception))
		Serial.print("Erreur reception");

	strcpy(requete.clef, reception.clef);
	faireSuivre(requete);
}
