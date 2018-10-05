/*
  InternetOfNothings by Unusual Computers Collective
    adapted from:
      Captive Portal by: M. Ray Burnette 20150831
*/

#include <ESP8266WiFi.h>
#include "./DNSServer.h"                  // Patched lib
#include <ESP8266WebServer.h>

const byte        DNS_PORT = 53;          // Capture DNS requests on port 53
IPAddress         apIP(10, 10, 10, 1);    // Private network for server
DNSServer         dnsServer;              // Create the DNS object
ESP8266WebServer  webServer(80);          // HTTP server


String responseHTML = ""
                      "<!DOCTYPE html><html><head><title>nothing.</title>"
                      "<style>"
                      "body {background: black;color: white;font-family: courier;font-size: xx-large;}"
                      "section {position: absolute;top: 50%;left: 50%;margin-right: -50%;transform: translate(-50%, -50%) }"
                      "</style></head>"
                      "<body><section><strong>nothing.</strong></section></body>"
                      "</html>";

void handle204(){
      Serial.println("204");

  webServer.send(204);
}
void handleSuccess(){
    Serial.println("SUCCES");
  webServer.send(204,"text/plain","success");
}
void handleAppleSuccess(){
    Serial.println("APPLE SUCCES");
   dnsServer.isCaptive=false;
   webServer.send(200,"text/html","<HTML><HEAD><TITLE>Success</TITLE></HEAD><BODY>Success</BODY></HTML>");
}
void setup() {
  Serial.begin(115200);
  Serial.println("starting");
  WiFi.mode(WIFI_AP);
  WiFi.softAPConfig(apIP, apIP, IPAddress(255, 255, 255, 0));
  WiFi.softAP("InternetOfNothings");

  // if DNSServer is started with "*" for domain name, it will reply with
  // provided IP to all DNS request
  dnsServer.start(DNS_PORT, "*", apIP);

  // replay to all requests with same HTML
  webServer.on("/generate_204", handle204);
  webServer.on("/success.txt",handleSuccess);
  webServer.on("/library/test/success.html",handleAppleSuccess);
  webServer.on("/success.html",handleAppleSuccess);
  webServer.on("/hotspot-detect.html",handleAppleSuccess);


  webServer.onNotFound([]() {
    if(dnsServer.isCaptive){
      dnsServer.isCaptive=false;
      Serial.println("IS CAPTIVE");
      Serial.println(webServer.uri());
      webServer.send(200,"text/html","<HTML><HEAD><TITLE>Success</TITLE></HEAD><BODY>Success</BODY></HTML>"); 
    }
    else{
      webServer.send(200, "text/html", responseHTML);
    }
  });
  webServer.begin();
}

void loop() {
  dnsServer.processNextRequest();
  webServer.handleClient();
}
