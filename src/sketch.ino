#include <ControlWebServer.h>
#include <Controller.h>
#include <Sensor.h>
#include <math.h>

const char *WIFI_SSID = "Hello_IoT";
const char *WIFI_PASSWD = "12345678";

PIDcontroller pidController("pid");

PIDcontroller *controllers[] = {&pidController};
const size_t nControlllers = 2;

PhotoSensor l(A0, 10000, 3.3, pow(2614, 1.25), 296, 0.8);

ControlWebServer server(80, controllers, nControlllers, &l);


void setup(){
    Serial.begin(115200);
    WiFi.mode(WIFI_AP);
    WiFi.softAP(WIFI_SSID, WIFI_PASSWD);

    pinMode(D7, OUTPUT);
    pidController.kp = 1;

    server.begin();
}

void loop(){
    server.handleClient();
    int corr = pidController.next_correction(l.sensor_value());
    Serial.println(pidController.control);
    delay(300);
    analogWrite(D7, corr);
}
