//
//  ofEnvironment.cpp
//  virality01
//
//  Created by Leprous on 03/12/2014.
//
//

#include "ofApp.h"
#include "ofParticle.h"


void ofParticle::setup(){
    
    position = ofVec3f(ofRandom(-1000, 1000), ofRandom(-1000, 1000), ofRandom(-1000, 1000));
    velocity = ofVec3f(ofRandom(-1.5, 1.5), ofRandom(-1.5, 1.5), ofRandom(-1.5, 1.5));
    core.setRadius(2);
    core.setResolution(4);
    
}

void ofParticle::update(){
    
    if(position.x < -1000 || position.x > 1000) velocity.x *= -1;
    if(position.y < -1000 || position.y > 1000) velocity.y *= -1;
    if(position.z < -1000 || position.z > 1000) velocity.z *= -1;
    
    position += velocity;
    
}

void ofParticle::draw(){
    
    core.setPosition(position.x, position.y, position.z);
    core.draw();
    
}