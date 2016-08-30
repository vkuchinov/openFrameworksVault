#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    tf.load("FiraMono.ttf", 20, true, true, true);
    tf.setLineHeight(28.0);
    tf.setLetterSpacing(1.1);
    
    keyClick.load("typewriterClick.mp3");
    keyClick.setMultiPlay(true);
    
    background.load("background.jpg");

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    background.draw(0, 0);
    ofSetColor(245, 235, 235);
    ofDrawRectangle(360, 180, 1200, 720);
    
    ofSetColor(0);
    if(ofGetFrameNum() % 30 == 0) { carriageVisible *= -1; }
    if(carriageVisible == 1) { tf.drawString(formatText() + carriage, 424, 244); } else { tf.drawString(formatText(), 424, 244); }
    
    ofSetColor(255);
    string data = "LENGTH: " + ofToString(text.length()) + " WORDS: " + ofToString(getNumOfWords());

    ofSetColor(128, 128, 128);
    tf.drawString(data, 424, 836);
}

string ofApp::formatText(){
    
    int currentLine = 0;
    if(text.length() < maxLineLength) { return text; }
    else{
        
    string output = "";
    vector<string> elements;
    
    elements = ofSplitString(text, " ");
        
    for(int e = 0; e < elements.size() - 1; e++){
        if( currentLine < maxLineLength - elements[e].length()) { output += elements[e] + " "; currentLine += elements[e].length(); } else { output += "\n" + elements[e]; currentLine = 0; }
    }
        
    output += elements[elements.size() - 1];
    return output;
        
    }
    
}

int ofApp::getNumOfWords(){
    
        vector<string> elements;
        elements = ofSplitString(text, " ", true, true); //what about "\n"???
        return elements.size();
}



//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    if((key > 96 && key < 123) || (key > 64 && key < 91)){
        
        //upper case to lower
        if(key > 64 && key < 91) { key += 32; }
        
        text += char(key);

        
        keyClick.play();
        
    }
    
    else if(key == 32 && text.back() != 32) { text += " "; keyClick.play(); }
    else if(key == OF_KEY_BACKSPACE && text.length() > 0) { text.pop_back(); keyClick.play();}

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