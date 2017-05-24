#include <ControlWebServer.h>
#include <Controller.h>
#include <Sensor.h>

const char *WIFI_SSID = "Hello_IoT";
const char *WIFI_PASSWD = "12345678";

PIDcontroller pidController("pid");

Controller *controllers[] = {&pidController};
const size_t nControlllers = 2;

PhotoSensor l(A0, 10000, 3.3, 2614, 296, 0.8);

ControlWebServer server(80, controllers, nControlllers);

void setup(){
    WiFi.mode(WIFI_AP);
    WiFi.softAP(WIFI_SSID, WIFI_PASSWD);

    server.begin();
    Serial.begin(115200);
}

void loop(){
    server.handleClient();
    Serial.println(l.sensor_value());
}
