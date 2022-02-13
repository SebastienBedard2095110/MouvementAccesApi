#pragma once 


#include <WiFiManager.h>

class ConfigurationWiFi {
private:
	WiFiManager m_wifiManager;

public:
	ConfigurationWiFi(bool p_estModeDebug);	
};