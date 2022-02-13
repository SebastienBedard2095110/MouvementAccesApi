#include <Arduino.h>


#include "ConfigurationWiFi.h"

#include "LecteurRFIDProxy.h"
#include "ApiAccesWifi.h"
#include "IntersectionProxySerial.h"


#include "Program.h"


#define URL_API "localhost:5221/api/"
#define BORNE_RX 16
#define BORNE_TX 17


Program::Program() {
	Serial.begin(MONITOR_SPEED);
	while ( ! Serial ) { ; }

	// ConfigurationWiFi wifi(true);


	IntersectionProxySerial* intersection = new IntersectionProxySerial(nullptr);
	ApiAccesWifi* api = new ApiAccesWifi(intersection, URL_API);
	LecteurRFIDProxy* lecteur = new LecteurRFIDProxy(api, BORNE_RX, BORNE_TX);

	tete = lecteur;
}


void Program::loop() {
	Requete requete = {};
	requete.borneId = BORNE_ID;
	
	tete->traiter(requete);
}
