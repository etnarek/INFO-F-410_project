#include <ControlWebServer.h>
#include <stdlib.h>
#include <stdio.h>

void goto_home(ControlWebServer *server){
    server->sendHeader("Location", String("/"), true);
	server->send( 302, "text/plain", "");
}

void render_home(PIDcontroller* controller, ControlWebServer* server, Sensor* sensor){
    String webpage = "<!DOCTYPE html><html><head> <link rel=\"stylesheet\" href=\"skeleton.css\"> <title>Super Smart Lamp</title></head><body> <div class=\"container\"> <div class=\"row\"> <h1>Super Smart Lamp</h1> </div><div class=\"row\"> <h5>Current lux : <em>";
    webpage += sensor->sensor_value();
    webpage += "</em></h5> </div><div class=\"row\"> <form action=\"/pid/treshold\" method=\"GET\"> <label for=\"target\">Target : </label><input name=\"target\" type=\"number\" value=\"";
    webpage += controller->treshold;
    webpage += "\" id=\"target\" class=\"u-full-width\"/> <input type=\"submit\" value=\"Submit\"/> </form> </div><div class=\"row\"> <h4>Change mode</h4> <a class=\"button ";
    webpage += (controller->control == ON) ? "button-primary":"";
    webpage += "\" href=\"/pid/ON\">ON</a> <a class=\"button ";
    webpage += (controller->control == OFF) ? "button-primary":"";
    webpage += "\" href=\"/pid/OFF\">OFF</a> <a class=\"button ";
    webpage += (controller->control == FULL) ? "button-primary":"";
    webpage += "\" href=\"/pid/FULL\">FULL</a> </div></br> <div class=\"row\"> <h4>Advanced PID Configuration</h4> <form method=\"GET\" action=\"/pid/set\"> <div class=\"row\"> <div class=\"four columns\"><label for=\"pidP\">Value of P:</label> <input name=\"P\" type=\"number\" value=\"";
    webpage += controller->kp;
    webpage += "\" id=\"pidP\" class=\"u-full-width\"/></div><div class=\"four columns\"><label for=\"pidI\">Value of I :</label> <input name=\"I\" type=\"number\" value=\"";
    webpage += controller->ki;
    webpage += "\" id=\"pidI\" class=\"u-full-width\"/></div><div class=\"four columns\"><label for=\"pidD\">Value of D :</label> <input name=\"D\" type=\"number\" value=\"";
    webpage += controller->kd;
    webpage += "\" id=\"pidD\" class=\"u-full-width\"/></div></div><input type=\"submit\" value=\"Submit\"/> </form> </div></div></body></html>";

    server->send(200, "text/html", webpage);

}

void render_css(ControlWebServer *server){
    server->send(200, "text/css", ".column,.columns,.container,.u-full-width{width:100%;box-sizing:border-box}h1,h2,h3{letter-spacing:-.1rem}body,h6{line-height:1.6}.container{position:relative;max-width:960px;margin:0 auto;padding:0 20px}ol,p,ul{margin-top:0}.column,.columns{float:left}@media (min-width:400px){.container{width:85%;padding:0}}html{font-size:62.5%}body{font-size:1.5em;font-weight:400;font-family:Raleway,HelveticaNeue,\"Helvetica Neue\",Helvetica,Arial,sans-serif;color:#222}h1,h2,h3,h4,h5,h6{margin-top:0;margin-bottom:2rem;font-weight:300}h1{font-size:4rem;line-height:1.2}h2{font-size:3.6rem;line-height:1.25}h3{font-size:3rem;line-height:1.3}h4{font-size:2.4rem;line-height:1.35;letter-spacing:-.08rem}h5{font-size:1.8rem;line-height:1.5;letter-spacing:-.05rem}h6{font-size:1.5rem;letter-spacing:0}@media (min-width:550px){.container{width:80%}.column,.columns{margin-left:4%}.column:first-child,.columns:first-child{margin-left:0}.one.column,.one.columns{width:4.66666666667%}.two.columns{width:13.3333333333%}.three.columns{width:22%}.four.columns{width:30.6666666667%}.five.columns{width:39.3333333333%}.six.columns{width:48%}.seven.columns{width:56.6666666667%}.eight.columns{width:65.3333333333%}.nine.columns{width:74%}.ten.columns{width:82.6666666667%}.eleven.columns{width:91.3333333333%}.twelve.columns{width:100%;margin-left:0}.one-third.column{width:30.6666666667%}.two-thirds.column{width:65.3333333333%}.one-half.column{width:48%}.offset-by-one.column,.offset-by-one.columns{margin-left:8.66666666667%}.offset-by-two.column,.offset-by-two.columns{margin-left:17.3333333333%}.offset-by-three.column,.offset-by-three.columns{margin-left:26%}.offset-by-four.column,.offset-by-four.columns{margin-left:34.6666666667%}.offset-by-five.column,.offset-by-five.columns{margin-left:43.3333333333%}.offset-by-six.column,.offset-by-six.columns{margin-left:52%}.offset-by-seven.column,.offset-by-seven.columns{margin-left:60.6666666667%}.offset-by-eight.column,.offset-by-eight.columns{margin-left:69.3333333333%}.offset-by-nine.column,.offset-by-nine.columns{margin-left:78%}.offset-by-ten.column,.offset-by-ten.columns{margin-left:86.6666666667%}.offset-by-eleven.column,.offset-by-eleven.columns{margin-left:95.3333333333%}.offset-by-one-third.column,.offset-by-one-third.columns{margin-left:34.6666666667%}.offset-by-two-thirds.column,.offset-by-two-thirds.columns{margin-left:69.3333333333%}.offset-by-one-half.column,.offset-by-one-half.columns{margin-left:52%}h1{font-size:5rem}h2{font-size:4.2rem}h3{font-size:3.6rem}h4{font-size:3rem}h5{font-size:2.4rem}h6{font-size:1.5rem}}a{color:#1EAEDB}a:hover{color:#0FA0CE}.button,button,input[type=submit],input[type=reset],input[type=button]{display:inline-block;height:38px;padding:0 30px;color:#555;text-align:center;font-size:11px;font-weight:600;line-height:38px;letter-spacing:.1rem;text-transform:uppercase;text-decoration:none;white-space:nowrap;background-color:transparent;border-radius:4px;border:1px solid #bbb;cursor:pointer;box-sizing:border-box}.button:focus,.button:hover,button:focus,button:hover,input[type=submit]:focus,input[type=submit]:hover,input[type=reset]:focus,input[type=reset]:hover,input[type=button]:focus,input[type=button]:hover{color:#333;border-color:#888;outline:0}.button.button-primary,button.button-primary,input[type=submit].button-primary,input[type=reset].button-primary,input[type=button].button-primary{color:#FFF;background-color:#33C3F0;border-color:#33C3F0}.button.button-primary:focus,.button.button-primary:hover,button.button-primary:focus,button.button-primary:hover,input[type=submit].button-primary:focus,input[type=submit].button-primary:hover,input[type=reset].button-primary:focus,input[type=reset].button-primary:hover,input[type=button].button-primary:focus,input[type=button].button-primary:hover{color:#FFF;background-color:#1EAEDB;border-color:#1EAEDB}input[type=tel],input[type=url],input[type=password],input[type=email],input[type=number],input[type=search],input[type=text],select,textarea{height:38px;padding:6px 10px;background-color:#fff;border:1px solid #D1D1D1;border-radius:4px;box-shadow:none;box-sizing:border-box}input[type=tel],input[type=url],input[type=password],input[type=email],input[type=number],input[type=search],input[type=text],textarea{-webkit-appearance:none;-moz-appearance:none;appearance:none}textarea{min-height:65px;padding-top:6px;padding-bottom:6px}input[type=tel]:focus,input[type=url]:focus,input[type=password]:focus,input[type=email]:focus,input[type=number]:focus,input[type=search]:focus,input[type=text]:focus,select:focus,textarea:focus{border:1px solid #33C3F0;outline:0}label,legend{display:block;margin-bottom:.5rem;font-weight:600}fieldset{padding:0;border-width:0}input[type=checkbox],input[type=radio]{display:inline}label>.label-body{display:inline-block;margin-left:.5rem;font-weight:400}ul{list-style:circle inside}ol{list-style:decimal inside}ol,ul{padding-left:0}ol ol,ol ul,ul ol,ul ul{margin:1.5rem 0 1.5rem 3rem;font-size:90%}.button,button,li{margin-bottom:1rem}code{padding:.2rem .5rem;margin:0 .2rem;font-size:90%;white-space:nowrap;background:#F1F1F1;border:1px solid #E1E1E1;border-radius:4px}pre>code{display:block;padding:1rem 1.5rem;white-space:pre}td,th{padding:12px 15px;text-align:left;border-bottom:1px solid #E1E1E1}td:first-child,th:first-child{padding-left:0}td:last-child,th:last-child{padding-right:0}fieldset,input,select,textarea{margin-bottom:1.5rem}blockquote,dl,figure,form,ol,p,pre,table,ul{margin-bottom:2.5rem}.u-max-full-width{max-width:100%;box-sizing:border-box}.u-pull-right{float:right}.u-pull-left{float:left}hr{margin-top:3rem;margin-bottom:3.5rem;border-width:0;border-top:1px solid #E1E1E1}.container:after,.row:after,.u-cf{content:\"\";display:table;clear:both}");
}

ControlWebServer::ControlWebServer(int port, PIDcontroller** controllers, size_t nControllers, Sensor* sensor)
    : ESP8266WebServer(port)
{
    ESP8266WebServer::on("/", [controllers, sensor, this]{render_home(controllers[0], this, sensor);});
    ESP8266WebServer::on("/skeleton.css", [this]{render_css(this);});
    for(int i=0; i< nControllers; i++){
        add_controller(controllers[i]);
    }
}

void ControlWebServer::add_controller(PIDcontroller *controller){
    ESP8266WebServer::on(("/"+controller->name+"/ON").c_str(), [controller, this]{controller->control = ON; goto_home(this);});
    ESP8266WebServer::on(("/"+controller->name+"/OFF").c_str(), [controller, this]{controller->control = OFF; goto_home(this);});
    ESP8266WebServer::on(("/"+controller->name+"/FULL").c_str(), [controller, this]{controller->control = FULL; goto_home(this);});
    ESP8266WebServer::on(("/"+controller->name+"/treshold").c_str(), [controller, this]{
        if (this->arg("target")== ""){
            this->send(400, "text/plain", "Missing target parameter (treshold).");
            return;
        }
        controller->treshold = atoi(this->arg("target").c_str());
        goto_home(this);
    });
    ESP8266WebServer::on(("/"+controller->name+"/set").c_str(), [controller, this]{
        if (this->arg("P")== ""){
            this->send(400, "text/plain", "Missing P parameter (PID).");
            return;
        }
        if (this->arg("I")== ""){
            this->send(400, "text/plain", "Missing I parameter (PID).");
            return;
        }
        if (this->arg("D")== ""){
            this->send(400, "text/plain", "Missing D parameter (PID).");
            return;
        }

        controller->kp = atoi(this->arg("P").c_str());
        controller->ki = atoi(this->arg("I").c_str());
        controller->kd = atoi(this->arg("D").c_str());
        goto_home(this);
    });
}
