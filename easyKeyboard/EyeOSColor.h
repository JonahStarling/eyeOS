//
//  EyeOSColor.h
//  easyKeyboard
//
//  Created by Jonah Starling on 10/31/15.
//
//

#ifndef __easyKeyboard__EyeOSColor__
#define __easyKeyboard__EyeOSColor__

#include "ofMain.h"

using namespace std;

class EyeOSColor {
private:
	ofColor currentColor;
	ofColor lightBlue;
	ofColor lightTeal;
public:
	EyeOSColor(void);
	~EyeOSColor(void);
	void setColorValues();
};

#endif /* defined(__easyKeyboard__EyeButton__) */

