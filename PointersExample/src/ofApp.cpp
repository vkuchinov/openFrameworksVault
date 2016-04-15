#include "ofApp.h"
#include "ofClassOne.h"
#include "ofClassTwo.h"

//--------------------------------------------------------------
void ofApp::setup(){

    float a = 578.0; //init float
    float *p = &a;
    
    cout << p << endl; //return address of float 'a'
    cout << *p << endl; //return value of float 'a'
    
    //changing
    *p += 54.0;
    
    cout << a << endl;
    
    
    //example with bespoke class
    ofClassOne objectA = ofClassOne(40.0);
    ofClassOne *objectAPointer = &objectA;
    
    cout << objectA.value << endl; //default value
    
    ofClassTwo objectB;
    objectB.calculate(&objectA);
    
    cout << objectA.value << endl; //updated value
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

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