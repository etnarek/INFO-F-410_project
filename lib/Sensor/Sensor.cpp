#include <Sensor.h>
#include <Arduino.h>
#include <math.h> 

Sensor::Sensor(int _pin, int _Rr, double _Uref) : pin(_pin), Rr(_Rr), Uref(_Uref){}

double Sensor::read2resistor(){
    double U = analogRead(pin) * (Uref / 1023.0);

    return ((double)Rr * (double)Uref) / U - Rr;
}

PhotoSensor::PhotoSensor(int pin, int Rr, double Uref, int _Ra, int _Ea, double _Y) :
    Sensor(pin, Rr, Uref),
    Ra(_Ra),
    Ea(_Ea),
    Y(_Y){}

int PhotoSensor::sensor_value(){
    int resistance = read2resistor();
    return (Ra/pow(resistance, 1.25)) * Ea;
}
