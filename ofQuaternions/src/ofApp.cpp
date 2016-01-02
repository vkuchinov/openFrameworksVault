#include "ofApp.h"

//Almost there...
//If sphere, cone are global the rotation goes mad
//If sphere, cone are re-creating each time in draw() - seems ok!

ofVec3f tar;


//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetFrameRate(30);
    ofEnableDepthTest();
    
    camera.getMouseInputEnabled();
    camera.setTarget(ofVec3f(300, 300, 0));
    
    light.enable();

    tar = ofVec3f(ofRandom(-400, 400), ofRandom(-400, 400), ofRandom(-400, 400));
}

//--------------------------------------------------------------
void ofApp::update(){

    currentFrame++;
    printf("frame #: %i\n", currentFrame);
}

//--------------------------------------------------------------
void ofApp::draw(){

    float z = sin( ofGetElapsedTimef() ) * 200.0f;
    
    ofVec3f center = ofVec3f(0, 0, 0);
    
    if(currentFrame%120 == 0){
    tar = ofVec3f(ofRandom(-400, 400), ofRandom(-400, 400), ofRandom(-400, 400));
    }
    
    //set 0,0,0 point at the middle of the screen
    glPushMatrix();
    glTranslatef(ofGetWidth()*.5, ofGetHeight()/2, 0);
    
    
    ofSetColor(255, 0, 0);
    ofSpherePrimitive sphere;
    sphere.setPosition(tar.x, tar.y, tar.z);
    sphere.setRadius( 16.0f );
    sphere.draw();

    ofVec3f normal = tar - center;
    normal.normalize();
    
    ofVec3f forward = ofVec3f(0, -1, 0);
    ofVec3f axis	= forward.crossed(normal);
    axis.normalize();
    float angle	= forward.angle(normal);
    
    ofVec3f right = axis.crossed(normal);
    right.normalize();
    right *= 250;
    
    // extend the axis
    ofVec3f da = axis;
    da *= 250;
    
    //axis guides
    ofSetColor(255, 0, 0);
    ofLine(center, tar);
    ofSetColor(0, 255, 0);
    ofLine(center, da);
    ofSetColor(0, 0, 255);
    ofLine(center, right);
    
    ofSetColor(150, 150, 150);
    ofConePrimitive cone;
    cone.set(50, 180);
    cone.setPosition(0, 0, 0);
    cone.rotate(angle, axis.x, axis.y, axis.z);
    cone.draw();

    glPopMatrix();
    
}  



//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}