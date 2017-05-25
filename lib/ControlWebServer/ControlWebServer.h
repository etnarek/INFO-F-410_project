#ifndef CONTROL_WEB_SERVER_H
#define CONTROL_WEB_SERVER_H
#include <ESP8266WebServer.h>
#include <Controller.h>
#include <Sensor.h>

class ControlWebServer : public ESP8266WebServer{
    public:
        ControlWebServer(int port, PIDcontroller** controllers, size_t nControllers, Sensor* sensor);
        void add_controller(PIDcontroller *controller);
};

#endif // CONTROL_WEB_SERVER_H
