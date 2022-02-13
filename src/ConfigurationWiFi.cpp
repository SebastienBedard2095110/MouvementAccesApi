#include <SPIFFS.h>
#include <ArduinoJson.h>
#include <Arduino.h>

#include "ConfigurationWiFi.h"

const char* Portail_SSID = "Mouvement";
const char* Portail_PASS = "12345678";
IPAddress adressePortail(192, 168, 23, 1);
IPAddress adressePasserelle(192, 168, 23, 1);
IPAddress masqueReseau(255, 255, 255, 0);

ConfigurationWiFi::ConfigurationWiFi(bool p_estModeDebug)
	:	m_wifiManager()
{
	m_wifiManager.setDebugOutput(p_estModeDebug);
	m_wifiManager.setConfigPortalTimeout(180);
	m_wifiManager.setAPStaticIPConfig(adressePortail, adressePasserelle, masqueReseau);

	m_wifiManager.autoConnect(Portail_SSID, Portail_PASS);

	if(WiFi.isConnected() == false) {
		Serial.println("configuration wifi: erreur connexion reseau.");
		return;
	}
	Serial.println("connexion reseau reussie.");
}
