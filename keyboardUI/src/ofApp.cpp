#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    keyClick.load("typewriterClick.mp3");
    keyClick.setMultiPlay(true);

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetBackgroundColor(225, 220, 215);
    
    ofSetColor(0);
    if(ofGetFrameNum() % 30 == 0) { carriageVisible *= -1; }
    if(carriageVisible == 1) { ofDrawBitmapString(formatText() + carriage, 64, 64); } else { ofDrawBitmapString(formatText(), 64, 64); }
    
    ofSetColor(255);
    string data = "LENGTH: " + ofToString(text.length()) + " WORDS: " + ofToString(getNumOfWords());

    ofDrawBitmapStringHighlight(data, 64, ofGetHeight() - 64);
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
        
        for(int c = 0; c < 26; c++){
            
            if(char(key) == map[c].key) { text += map[c].replacement; }
            
        }
        
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