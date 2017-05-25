#include <ControlWebServer.h>
#include <Controller.h>
#include <Sensor.h>

const char *WIFI_SSID = "Hello_IoT";
const char *WIFI_PASSWD = "12345678";

PIDcontroller pidController("pid");

PIDcontroller *controllers[] = {&pidController};
const size_t nControlllers = 2;

PhotoSensor l(A0, 10000, 3.3, 2614, 296, 0.8);

ControlWebServer server(80, controllers, nControlllers, &l);

int i=0;

void setup(){
    WiFi.mode(WIFI_AP);
    WiFi.softAP(WIFI_SSID, WIFI_PASSWD);

    pinMode(D7, OUTPUT);

    server.begin();
    Serial.begin(115200);
}

void loop(){
    server.handleClient();
    analogWrite(D7, i*10);
    i++;
    if(i>25){
        i=0;
    }
    Serial.println(i);
    delay(1000);
}
