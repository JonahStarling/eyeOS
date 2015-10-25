//
//  EyeCursor.h
//  easyKeyboard
//
//  Created by Jonah Starling on 9/30/15.
//
//

#ifndef __easyKeyboard__EyeCursor__
#define __easyKeyboard__EyeCursor__

#include <stdio.h>
#include "ofMain.h"

class EyeCursor {
private:
    float x;
    float y;
    float size;
    int opa;
    bool clicking;
public:
    EyeCursor();
    EyeCursor(float mouseX, float mouseY);
    void redrawObject(float mouseX, float mouseY);
    void setClicking(bool state);
    bool checkClicked();
};

#endif /* defined(__easyKeyboard__EyeCursor__) */
