#include <ControlWebServer.h>
#include <Controller.h>

const char *WIFI_SSID = "Hello_IoT";
const char *WIFI_PASSWD = "12345678";

PIDcontroller pidController("pid");

Controller *controllers[] = {&pidController};
const size_t nControlllers = 2;

ControlWebServer server(80, controllers, nControlllers);

void setup(){
    WiFi.mode(WIFI_AP);
    WiFi.softAP(WIFI_SSID, WIFI_PASSWD);

    server.begin();
}

void loop(){
    server.handleClient();
}
