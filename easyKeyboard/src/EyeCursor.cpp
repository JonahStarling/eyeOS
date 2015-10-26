//
//  EyeCursor.cpp
//  easyKeyboard
//
//  Created by Jonah Starling on 9/30/15.
//
//

#include "EyeCursor.h"

EyeCursor::EyeCursor():
    x(0),
    y(0),
    size(10),
    opa(155),
    clicking(false)
{
    //
}

EyeCursor::EyeCursor(float mouseX, float mouseY):
    x(mouseX),
    y(mouseY),
    size(10),
    opa(155),
    clicking(false)
{
    //
}

#define FRAME_RATE_DELAY 100

void EyeCursor::redrawObject(float mouseX, float mouseY) {
    if (size >= FRAME_RATE_DELAY) {
        clicking = false;
    }
	if (clicking && size < FRAME_RATE_DELAY) {
        size += 0.1;
        opa += 1;
    } else if (size > 10) {
        size -= 0.5;
        opa -= 5;
    }
    ofSetColor(200,200,200,opa);
    ofFill();
    ofCircle(mouseX,mouseY,size);
}

void EyeCursor::setClicking(bool state) {
    clicking = state;
}

bool EyeCursor::checkClicked() {
	if (size > FRAME_RATE_DELAY) {
        return true;
    } else {
        return false;
    }
}