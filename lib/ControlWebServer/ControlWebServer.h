#ifndef CONTROL_WEB_SERVER_H
#define CONTROL_WEB_SERVER_H
#include <ESP8266WebServer.h>
#include <Controller.h>

class ControlWebServer : public ESP8266WebServer{
    public:
        ControlWebServer(int port, Controller** controllers, size_t nControllers);
        void add_controller(Controller *controller);
};

#endif // CONTROL_WEB_SERVER_H
