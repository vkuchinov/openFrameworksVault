#include "ofApp.h"
#include "ofJelly.h"

#define NUM_TENTACLES 16
ofJellyTentacle tents[NUM_TENTACLES];

bool firstFrame = true;
float gap = 32;

void ofJelly::setup(int ind, float x, float y, float z){
    
    a = ofRandom(-0.5, 0.5);
    b = ofRandom(150, 450);

    index = ind;
    center = ofPoint( x, y, z);
    
    pos = center;

    axisX = ofPoint( 1, 0, 0 );
    axisY = ofPoint( 0, 1, 0 );
    axisZ = ofPoint( 0, 0, 1 );
    
    for(int t = 0; t < NUM_TENTACLES; t++){
        
        ofJellyTentacle newTentacle;
        newTentacle.setup(center.x, center.y, 0, 360/NUM_TENTACLES);
        tents[t] = newTentacle;
        
    }
    
}

void ofJelly::update(){
    
}

void ofJelly::draw(){
    
    if(firstFrame){ lastPos = pos; firstFrame = false; }
    else{

        float time = ofGetElapsedTimef();
        float twistAngle = 5.0 * ofSignedNoise( time * a + b );
        float rotateAngle = 1.5;
        
        axisX.rotate( twistAngle, axisZ );
        axisY.rotate( twistAngle, axisZ );
        axisX.rotate( rotateAngle, axisY );
        axisZ.rotate( rotateAngle, axisY );
        
        ofPoint move = axisZ * gap;
        pos += move;
        
        //core calculation
        //vector beetween two positions
        
        ofVec3f normal = pos - lastPos;
        normal.normalize();
        
        ofVec3f forward = ofVec3f(0, -1, 0);
        ofVec3f axis	= forward.crossed(normal);
        axis.normalize();
        float angle	= forward.angle(normal);

        for(int t=0; t < NUM_TENTACLES; t++)
        {
            
            float time = ofGetElapsedTimef(); //Time //Parameters – twisting and rotating angles and color
            
            float colorShift = t * 0.025;
            ofFloatColor color( ofNoise( time * 0.05 + colorShift ), ofNoise( time * 0.1 + colorShift ), ofNoise( time * 0.15 + colorShift ));
            color.setSaturation( 1.0 ); //Make the color maximally
            ofSetColor(color);
            
            tents[t].draw(lastPos, axis, angle);
        }
        
        
        lastPos = pos;
        //printf("object %i: position : %f, %f, %f\n", index, pos.x, pos.y, pos.z);
    }
    
}