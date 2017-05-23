#include <ControlWebServer.h>
#include <Controller.h>

const char *WIFI_SSID = "Hello_IoT";
const char *WIFI_PASSWD = "12345678";

Controller PIDcontroller {ON, 400, "pid"};

Controller controllers[] = {PIDcontroller};
const size_t nControlllers = sizeof(controllers)/sizeof(Controller);

ControlWebServer server(80, controllers, nControlllers);

void setup(){
    WiFi.mode(WIFI_AP);
    WiFi.softAP(WIFI_SSID, WIFI_PASSWD);

    server.begin();
}

void loop(){
    server.handleClient();
}
