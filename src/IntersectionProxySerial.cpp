#include <Arduino.h>

#include "IntersectionProxySerial.h"

IntersectionProxySerial::IntersectionProxySerial(AbstractChaine* prochain)
	: AbstractChaine(prochain)
{
	Serial.begin(MONITOR_SPEED);
	while( ! Serial )
		;
	
}

void IntersectionProxySerial::traiter(Requete requete) {
	Serial.println("Reçu:");

	Serial.print("\tAction: ");
	Serial.println(requete.action);
	Serial.print("\tborneId: ");
	Serial.println(requete.borneId);
	Serial.print("\tClef: ");
	Serial.println(requete.clef);
}
