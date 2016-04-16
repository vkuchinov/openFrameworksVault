//
//  ofEnvironment.h
//  virality01
//
//  Created by Leprous on 03/12/2014.
//
//

#pragma once

#include "ofMain.h"

class ofParticle {
public:
    void setup();
    void update();
    void draw();
    
    ofVec3f position, velocity;
    ofSpherePrimitive core;
};