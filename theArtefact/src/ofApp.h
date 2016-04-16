#pragma once

#include "ofMain.h"


//my own addons
#include "ofParticle.h"
#include "ofJelly.h"

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        float startY, endY, bezY1, bezY2, curveY1, curveY2, curveStart, curveEnd;
    
        const float limitMax = 100;
        const float limitMin = -100;
    
        bool fullScr = false;
        bool tiltFX = false;
    
        //setup scene
        ofEasyCam camera;

        vector<ofJelly> placeholders;
    
        float FOV = 18.0;

};
