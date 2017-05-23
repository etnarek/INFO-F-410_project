#ifndef CONTROLLER_H
#define CONTROLLER_H

enum ControlType {ON, OFF, FULL};
typedef enum ControlType controlType;

typedef struct {
    controlType control;
    int treshold;
    String name;
} Controller;

#endif //CONTROLLER_H
