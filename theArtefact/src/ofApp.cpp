#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0, 0, 0);
    ofEnableDepthTest();
    

    ofSetFrameRate(30);

    camera.getMouseInputEnabled();

    //creature
    for(int p = 0; p < 1; p++){
    ofJelly newJelly;
    newJelly.setup(p, ofGetWidth()/4, ofGetHeight()/4, -300.0);
    placeholders.push_back(newJelly);
    }

}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    camera.setTarget(ofVec3f(500, -500, 0));
    camera.setFov(FOV);

    camera.begin();
    ofPushMatrix();
    ofRotateY(70);
    ofRotateZ(-10);
    //creatures
    placeholders[0].draw();
    ofPopMatrix();
    camera.end();
    
    //on-screen interface / captions
    ofDrawBitmapString("FOV: " + ofToString(FOV), 32, 32);
    ofNode n = camera.getTarget();
  
    FOV = 40.0;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    //if (key == 'Q' || key == 'q') { FOV += 1.0; }
    //if (key == 'A' || key == 'a') { FOV -= 1.0; }

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
