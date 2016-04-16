//
//  ofJellyTentacle.h
//  virality01
//
//  Created by Leprous on 03/12/2014.
//
//

#pragma once

#include "ofApp.h"

class ofJellyTentacle {
public:
    void setup(float initX, float initY, int nextIndex, int rotX);
    void update();
    void draw(ofVec3f parent, ofPoint pivot, float pivotAngle);
    
    float shiftX, shiftY, shiftZ, speedX, speedY, diameter;
    float hue;
    
    int itsIndex;
    float ang;

    float LENGTH = 400.0;
    
    int frameNum;
    int inner_counter;
    
    int resolution = 1;
    float margins = 50;
    
    float angleX;
    
    float a = 20;
    float b = 10;
    float c = 0.069f;
    float d = 0.01f;
    float e = 0.02f;
    
    //diameter bigger value = smaller
    float f = 16;
    float g = 8;

    
    ofPoint basePoints[8];
    
    int rColor, gColor, bColor;
};
