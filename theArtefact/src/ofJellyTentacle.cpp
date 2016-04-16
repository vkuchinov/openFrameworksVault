#include "ofJellyTentacle.h"

void ofJellyTentacle::setup(float initX, float initY, int nextIndex, int rotX){
    
    shiftX = initX;
    shiftZ = initY;
    angleX = rotX;
    rColor = ofRandom(255);
    gColor = ofRandom(255);
    bColor = ofRandom(255);
    
}

void ofJellyTentacle::update(){
    
    
}

void ofJellyTentacle::draw(ofVec3f parent, ofPoint pivot, float pivotAngle){
    
    
    //Update x.y
    
    shiftX = parent.x/50;
    shiftY = parent.y/50;
    

    ofMesh mesh;
    
    ofTranslate(pivot.x, pivot.y, pivot.z);
    ofRotateX(pivotAngle + angleX);
    mesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);

    
    for(int x= - LENGTH; x< LENGTH; x+= resolution) {
        
        basePoints[0] = ofPoint(x, ofGetHeight()/f + ofGetHeight() * c * sin(x * d + g * ofGetFrameNum() * e), shiftZ + a);
        basePoints[1] = ofPoint(x, ofGetHeight()/f + ofGetHeight() * c * sin(x * d + g * ofGetFrameNum() * e), shiftZ + -a);
        basePoints[2] = ofPoint(x + b, ofGetHeight()/f + ofGetHeight() * c * sin(x * d + g * ofGetFrameNum() * e), shiftZ + -a);
        basePoints[3] = ofPoint(x + b, ofGetHeight()/f + ofGetHeight() * c * sin(x * d + g * ofGetFrameNum() * e), shiftZ + a);
        basePoints[4] = ofPoint(x, a + ofGetHeight()/f + ofGetHeight() * c * sin(x * d + g * ofGetFrameNum() * e), shiftZ + a);
        basePoints[5] = ofPoint(x, a + ofGetHeight()/f + ofGetHeight() * c * sin(x * d + g * ofGetFrameNum() * e), shiftZ + -a);
        basePoints[6] = ofPoint(x + b, a + ofGetHeight()/f + ofGetHeight() * c * sin(x * d + g * ofGetFrameNum() * e), shiftZ + -a);
        basePoints[7] = ofPoint(x + b, a + ofGetHeight()/f + ofGetHeight() * c * sin(x * d + g * ofGetFrameNum() * e), shiftZ + a);
        
        int poly[4][6] = {{0, 1, 2, 0, 2, 3}, {4, 5, 6, 4, 5, 7}, {0, 3, 4, 3, 4, 7}, {1, 2, 5, 2, 5, 6}};
        //int poly[1][6] = {{0, 1, 3, 3, 3, 3}};
        
        for(int v = 0; v < 4; v++)
            
        {
            
            mesh.addVertex(basePoints[poly[v][0]]);
            mesh.addVertex(basePoints[poly[v][1]]);
            mesh.addVertex(basePoints[poly[v][2]]);
            mesh.addVertex(basePoints[poly[v][3]]);
            mesh.addVertex(basePoints[poly[v][4]]);
            mesh.addVertex(basePoints[poly[v][5]]);
            
        }
        
    }
    
    mesh.drawFaces();
}