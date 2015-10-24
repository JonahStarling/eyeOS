#pragma once

#include "ofMain.h"
#include "EyeButton.h"
#include "EyeCursor.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        int menuMain(int i);
        void menuABC(int i);
        void menuSuggestions(int i );
        void menuHIJ(int i);
        void menuOPQ(int i);
        void menuUVW(int i);
        void findSuggestions();
};
