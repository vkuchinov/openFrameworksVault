#pragma once

#include "ofMain.h"
#include "ofxOMXPlayer.h"

//Camera HD 720p
//Resolution 1280x720
//ratio 1:0.5625

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
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        ofxOMXPlayer omxPlayer;
        //ofVideoPlayer footage;
    
        int cameraID = 0;
        ofVideoGrabber liveCam;
        ofPixels camInverted;
        ofTexture camTexture;
    
        //milliseconds
        int mills = 0;
	float pos;

        //time in milliseconds
        struct Milestone { int id; int time; bool cam; int x; int y; int camWidth; int camHeight; };

        int currentEvent = 0;
        Milestone events [4] { { 0,     0, false,    0,   0,     0,   0 },
                               { 1, 58200,  true,  -28,  20,   924, 520 },   //1:0.5625 ratio
                               { 2, 62120,  true,    0, -106, 1280, 720 },   //1:0.5625 ratio
                               { 3, 67580, false,    0,    0,    0,   0 }};
    
};
