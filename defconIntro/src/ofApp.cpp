#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    //window settings
    //ofToggleFullscreen();
    ofSetVerticalSync(true);
    
    //video footage inits
    ofSetLogLevel(OF_LOG_VERBOSE);

    string videoPath = ofToDataPath("Intro_Putin.mov", true);

    //Somewhat like ofFboSettings we may have a lot of options so this is the current model
    ofxOMXPlayerSettings settings;
    settings.videoPath = videoPath;
    settings.useHDMIForAudio = true;	//default true
    settings.enableTexture = true;		//default true
    settings.enableLooping = false;		//default true
    settings.enableAudio = true;		//default true, save resources by disabling
    //settings.doFlipTexture = true;		//default false


    //so either pass in the settings
    omxPlayer.setup(settings);


    //footage.load("Intro_Putin.mov");
    //footage.setLoopState(OF_LOOP_NORMAL);
    //footage.play();
    
    //cam inits
    
    vector<ofVideoDevice> devices = liveCam.listDevices();
    
    for(int i = 0; i < devices.size(); i++){
        if(devices[i].bAvailable){
            ofLogNotice() << devices[i].id << ": " << devices[i].deviceName;
        }else{
            ofLogNotice() << devices[i].id << ": " << devices[i].deviceName << " - unavailable ";
        }
    }
    
    liveCam.setDeviceID(cameraID);
    liveCam.setDesiredFrameRate(30);
    liveCam.initGrabber(640, 360);
    
    camInverted.allocate(640, 360, OF_PIXELS_RGB);
    camTexture.allocate(camInverted);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    //footage.update();
    if(currentEvent == 1 || currentEvent == 2) { liveCam.update(); }
    
    
    if(liveCam.isFrameNew()){
        ofPixels & pixels = liveCam.getPixels();
        for(int i = 0; i < pixels.size(); i++){
            camInverted[i] = 255 - pixels[i];
        }
        camTexture.loadData(camInverted);
    }

    //getPosition <> getCurrentFrame
    //getDuration <> getDurationInSeconds

    mills = ofMap(omxPlayer.getCurrentFrame(), 0, omxPlayer.getTotalNumFrames(), 0, omxPlayer.getDurationInSeconds()*1E3);

    for(int e = currentEvent + 1; e < 4; e++){ if(mills > events[e].time && currentEvent != 3) currentEvent = e; }
}

//--------------------------------------------------------------
void ofApp::draw(){

    if(!omxPlayer.isTextureEnabled())
        {
            return;
        }

    omxPlayer.draw(0, 0, ofGetWidth(), ofGetHeight());

    if(currentEvent == 1 || currentEvent == 2) {  liveCam.draw(events[currentEvent].x, events[currentEvent].y, events[currentEvent].camWidth, events[currentEvent].camHeight); }

    //ofDrawBitmapString("fps:" + ofToString(ofGetFrameRate()) + " mills:" + ofToString(mills), 48, 48);

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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
