#pragma once

#include "ofMain.h"

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
    
        ofSoundPlayer keyClick;
    
        string formatText();
        int getNumOfWords();
    
        string carriage = "|";
        int carriageVisible = -1;
    
        int maxLineLength = 64;
        string text = "THE FIVE BOXING WIZARDS JUMP QUICKLY";
    
        struct customKey{
            
            int id;
            char key;
            string replacement;
            
        };
    
        customKey map [26] = {{0, 'q', "A"}, {1, 'w', "B"}, {2, 'e', "C"}, {3, 'r', "D"}, {4, 't', "E"}, {5, 'y', "F"},
                              {6, 'u', "G"}, {7, 'i', "H"}, {8, 'o', "I"}, {9, 'p', "J"}, {10, 'a', "K"}, {11, 's', "L"},
                              {12, 'd', "M"}, {13, 'f', "N"}, {14, 'g', "O"}, {15, 'h', "P"}, {16, 'j', "Q"}, {17, 'k', "R"},
                              {18, 'l', "S"}, {19, 'z', "T"}, {20, 'x', "U"}, {21, 'c', "V"}, {22, 'v', "W"}, {23, 'b', "X"},
                              {24, 'n', "Y"}, {25, 'm', "Z"}};
    
};
