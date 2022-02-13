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
	Serial.println("\n\nTransfert vers intersection:");

	Serial.print("\tAction: ");
	Serial.print(requete.action);
	Serial.println(" secondes");
	Serial.print("\tborneId: ");
	Serial.println(requete.borneId);
	Serial.print("\tClef: ");
	Serial.println(requete.clef);
}
