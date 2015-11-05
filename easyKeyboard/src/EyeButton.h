//
//  EyeButton.h
//  easyKeyboard
//
//  Created by Jonah Starling on 9/28/15.
//
//

#ifndef __easyKeyboard__EyeButton__
#define __easyKeyboard__EyeButton__

#include <stdio.h>
#include <string>
#include "ofMain.h"

using namespace std;

class EyeButton {
private:
    float x;
    float y;
    float height;
    float width;
    string value;
    bool clicked;
	ofColor buttonColor;
    ofTrueTypeFont buttonLabel;
public:
    //Constructors
    EyeButton();
    EyeButton(float x, float y, float width, float height, string value, ofColor color);
    //Get
    float getX();
    float getY();
    float getWidth();
    float getHeight();
    string getValue();
    bool getClicked();
	ofColor getColor();
    //Set
    void setX(float x);
    void setY(float y);
    void setWidth(float width);
    void setHeight(float height);
    void setValue(string value);
    void setClicked(bool clicked);
	void setColor(ofColor buttonColor);
    //Other Functions
    void redrawObject();
    bool eyeOnButton(float eyeX, float eyeY);
};

#endif /* defined(__easyKeyboard__EyeButton__) */
