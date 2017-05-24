#ifndef SENSOR_H
#define SENSOR_H

class Sensor{
    int pin;
    int Rr;
    double Uref;
    public:
        Sensor(int pin, int Rr, double Uref);
        double read2resistor();
        virtual int sensor_value() = 0;
};

class PhotoSensor : public Sensor {
    int Ra;
    int Ea;
    double Y;
    public:
        PhotoSensor(int pin, int Rr, double Uref, int Ra, int Ea, double Y);
        int sensor_value();
};

#endif //SENSOR_H
