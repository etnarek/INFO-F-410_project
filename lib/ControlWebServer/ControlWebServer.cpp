#include <ControlWebServer.h>
#include <stdlib.h>
#include <stdio.h>

void goto_home(ControlWebServer *server){
    server->sendHeader("Location", String("/"), true);
	server->send( 302, "text/plain", "");
}


ControlWebServer::ControlWebServer(int port, Controller** controllers, size_t nControllers)
    : ESP8266WebServer(port)
{
    for(int i=0; i< nControllers; i++){
        add_controller(controllers[i]);
    }
}

void ControlWebServer::add_controller(Controller *controller){
    ESP8266WebServer::on(("/"+controller->name+"/on").c_str(), [controller, this]{controller->control = ON; goto_home(this);});
    ESP8266WebServer::on(("/"+controller->name+"/off").c_str(), [controller, this]{controller->control = OFF; goto_home(this);});
    ESP8266WebServer::on(("/"+controller->name+"/full").c_str(), [controller, this]{controller->control = FULL; goto_home(this);});
    ESP8266WebServer::on(("/"+controller->name+"/treshold").c_str(), [controller, this]{
        if (this->arg("t")== ""){
            this->send(400, "text/plain", "Missing t parameter (treshold).");
            return;
        }
        controller->treshold = atoi(this->arg("t").c_str());
        goto_home(this);
    });
}
