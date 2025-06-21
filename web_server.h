#ifndef WEB_SERVER_H
#define WEB_SERVER_H
#include <ESP8266WebServer.h>

extern bool browserControl;
ESP8266WebServer server(80);

void setup_WebServer()
{
  server.on("/",[](){
    String html= "<!DOCTYPE html><html><style>";
    html+= ".btn {width:120px;height:45px;backgorunf:#28a745;color:white;border:none;border-radius:6px;margin:10px; font-size: 16px; cursor:pointer;transition:backgrounf 0.3s;} strong{color:green;} .btn:hover {background:#1e7e34;}";
    html+= ".btn-disable {background:#dc3545;} .btn-disable: hover {background:#a71d2a;}</style><head><meta charset='utf-8'><title>Motion System</title></head><body>";
    html+= "<center><h2>Motion System Control </h2>";
    html+= " System: <strong>" + String(browserControl ? "ON":"OFF") + "</strong><br><br>";
    html+= "<a href=\"/on\">button class-'btn'>Enable</button></a>";
    html+= "<a href=\"/off\"> <button class='btn btn-disable'> Disable</button></a>";
    html+= "</center></body></html>";
    server.send(200,"text/html",html);
  });
  server.on("/on",[](){
    browserControl=true;
    server.sendHeader("Location","/");
    server.send(303);

  });
  server.on("/off",[](){
    browserControl=false;
    server.sendHeader("Location","/");
    server.send(303);

  });
  server.begin();
}
#endif