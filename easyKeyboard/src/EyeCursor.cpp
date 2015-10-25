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

void EyeCursor::redrawObject(float mouseX, float mouseY) {
    if (size >= 20) {
        clicking = false;
    }
    if (clicking && size < 20) {
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
    if (size > 20) {
        return true;
    } else {
        return false;
    }
}