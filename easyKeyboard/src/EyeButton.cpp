//
//  EyeButton.cpp
//  easyKeyboard
//
//  Created by Jonah Starling on 9/28/15.
//
//

#include "EyeButton.h"

//Constructors
EyeButton::EyeButton():
    x(0),
    y(0),
    width(0),
    height(0),
    value(""),
    clicked(false)
{
    //
}

EyeButton::EyeButton(float x, float y, float width, float height, string value, bool clicked):
    x(x),
    y(y),
    width(width),
    height(height),
    value(value),
    clicked(clicked)
{
    buttonLabel.loadFont("arial.ttf", 32);
}


//Get
float EyeButton::getX() {return x;}
float EyeButton::getY() {return y;}
float EyeButton::getWidth() {return width;}
float EyeButton::getHeight() {return height;}
string EyeButton::getValue() {return value;}
bool EyeButton::getClicked() {return clicked;}


//Set
void EyeButton::setX(float newX) {x = newX;}
void EyeButton::setY(float newY) {y = newY;}
void EyeButton::setWidth(float newWidth) {width = newWidth;}
void EyeButton::setHeight(float newHeight) {height = newHeight;}
void EyeButton::setValue(string newValue) {value = newValue;}
void EyeButton::setClicked(bool newClick) {clicked = newClick;}


//Other Functions
void EyeButton::redrawObject() {
	//self.height - boundingbox.height/2
	//self.width - boundingbox.width/2

    ofSetColor(200, 10, 200);
    ofFill();
    ofDrawPlane((x+(width/2)),(y+(height/2)),width,height);
    ofSetColor(255, 255, 255);
	//Center the string
	buttonLabel.drawString(value, ((x+(width/2)) - (buttonLabel.stringWidth(value)/2)), ((y+(height/2)) - (buttonLabel.stringHeight(value)/2)));
}

bool EyeButton::eyeOnButton(float eyeX, float eyeY) {
    if (eyeX > x && eyeX < x+width && eyeY > y && eyeY < y+height) {
        return true;
    } else {
        return false;
    }
}