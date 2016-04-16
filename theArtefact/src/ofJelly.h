#pragma once

#include "ofApp.h"
#include "ofJellyTentacle.h"

class ofJelly {
public:
    void setup(int ind, float x, float y, float z);
    void update();
    void draw();
    
    ofVec3f position, velocity, acceleration, target;
    float maxSpeed = 5;
    float maxForce = 0.5;
    
    ofVec3f direction;
    
    bool rotationEnabled = true;
    ofPoint pos, lastPos;
    ofPoint axisX, axisY, axisZ, lastX, lastY, lastZ;
    
    //twist parameters
    float a, b;
    
    int index;
    ofPoint center;
    
};
