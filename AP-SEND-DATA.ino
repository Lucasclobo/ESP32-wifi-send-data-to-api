#include <Arduino.h>
#include <HTTPClient.h>
#include <DNSServer.h>
#include <WebServer.h>
#include <WiFiManager.h>

/* WIFI FUNCTION */
WiFiManager wifiManager;

void configModeCallback (WiFiManager *myWiFiManager) {
  Serial.println("Entrando no mode de configuração..."); /* Entering the configuration mode ... */
  Serial.println(WiFi.softAPIP());
  Serial.println(myWiFiManager->getConfigPortalSSID());  
}
/* END WIFI FUNCTION */

void setup() {
  Serial.begin(9600);  
  
  /* WIFI CONNECTION */
  
    wifiManager.setAPCallback(configModeCallback);
    if (!wifiManager.autoConnect("SSID NAME", "PASSWORD")) {
      Serial.println("Failed to connect...");
      ESP.restart();
      delay(1000);
    }
    Serial.println("Connected...");
    
  /* END WIFI CONNECTION */
  delay(1000);
}

/* DEVICE CODE REGISTERED IN THE SYSTEM */
String apiKeyValue = "123456";

void loop() {
  
  if(WiFi.status() == WL_CONNECTED){
      /* SEND DATA */
        HTTPClient http;
        http.begin("LINK URL");
        http.addHeader("Content-Type", "application/x-www-form-urlencoded");
        
        String data1 = "1";
        double data2 = "2";  
        double data3 = "3";
      
        String httpRequestData = "data1=" + data1 + "&data2=" + data2 + "&data3=" + data3 + "&key=" + apiKeyValue;
        int httpResponseCode = http.POST(httpRequestData);
      
        if(httpResponseCode > 0){
          String response = http.getString();
          Serial.println(response);
        }else{
          Serial.print("Error on sending POST: ");
          Serial.println(httpResponseCode);
        }
       http1.end(); 
      /* SEND DATA */
  }
  delay(10000);  //Send a request every 10 seconds
}
