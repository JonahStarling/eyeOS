#include "ofApp.h"

//--------------------------------------------------------------
int screenWidth;
int screenHeight;
int currentGrid;
int posX;
int posY;
string wordToType;
string typedSoFar;
EyeCursor cursor;
EyeButton button;
vector<EyeButton> vectorOfButtons;
vector<string> wordsEN;
vector<string> menu0ButtonLabels;
vector<string> menu1ButtonLabels;
vector<string> menu2ButtonLabels;
vector<string> menu3ButtonLabels;
vector<string> menu4ButtonLabels;
vector<string> menu5ButtonLabels;
vector<string> menu6ButtonLabels;
vector<string> menu7ButtonLabels;
vector<string> menu8ButtonLabels;
vector<string> menu9ButtonLabels;
vector<vector<string> > vectorOfLabelArrays;

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFullscreen(true);
    ofHideCursor();
    ofBackground(50, 50, 50);
    string line;
    fstream myFile;
    ifstream info("wordsEN.txt");
    if(!info) {
        cout << "That file doesn't exist. Try again." << endl;
    } else {
        myFile.open("wordsEN.txt");
        if (myFile.bad()) {
            cout << "Your file is empty or the wrong format." << endl;
        } else {
            while(getline(myFile, line)) {
                wordsEN.push_back(line);
            }
        }
    }
    //Closes the file
    myFile.close();
    eyex.init(); // ***COMMENT OUT ON MAC***
    cursor = EyeCursor(0,0);
    screenWidth = ofGetScreenWidth();
    screenHeight = ofGetScreenHeight();
    //Menu 0 Labels
    menu0ButtonLabels.push_back("A B C D E F G");
    menu0ButtonLabels.push_back("Suggestions");
    menu0ButtonLabels.push_back("H I J K L M N");
    menu0ButtonLabels.push_back("Delete");
    menu0ButtonLabels.push_back("Hello easyKeyboard");
    menu0ButtonLabels.push_back("Other Characters");
    menu0ButtonLabels.push_back("O P Q R S T");
    menu0ButtonLabels.push_back("Typed so far...");
    menu0ButtonLabels.push_back("U V W X Y Z");
    vectorOfLabelArrays.push_back(menu0ButtonLabels);
    //Menu 1 Labels
    menu1ButtonLabels.push_back("A");
    menu1ButtonLabels.push_back("B");
    menu1ButtonLabels.push_back("C");
    menu1ButtonLabels.push_back("D");
    menu1ButtonLabels.push_back("E");
    menu1ButtonLabels.push_back("F");
    menu1ButtonLabels.push_back("Back");
    menu1ButtonLabels.push_back("G");
    menu1ButtonLabels.push_back("Back");
    vectorOfLabelArrays.push_back(menu1ButtonLabels);
    //Menu 2 Labels
    menu2ButtonLabels.push_back("");
    menu2ButtonLabels.push_back("");
    menu2ButtonLabels.push_back("");
    menu2ButtonLabels.push_back("");
    menu2ButtonLabels.push_back("");
    menu2ButtonLabels.push_back("");
    menu2ButtonLabels.push_back("");
    menu2ButtonLabels.push_back("");
    menu2ButtonLabels.push_back("");
    vectorOfLabelArrays.push_back(menu2ButtonLabels);
    //Menu 3 Labels
    menu3ButtonLabels.push_back("H");
    menu3ButtonLabels.push_back("I");
    menu3ButtonLabels.push_back("J");
    menu3ButtonLabels.push_back("K");
    menu3ButtonLabels.push_back("L");
    menu3ButtonLabels.push_back("M");
    menu3ButtonLabels.push_back("Back");
    menu3ButtonLabels.push_back("N");
    menu3ButtonLabels.push_back("Back");
    vectorOfLabelArrays.push_back(menu3ButtonLabels);
    //Menu 4 Labels
    menu4ButtonLabels.push_back("");
    menu4ButtonLabels.push_back("");
    menu4ButtonLabels.push_back("");
    menu4ButtonLabels.push_back("");
    menu4ButtonLabels.push_back("");
    menu4ButtonLabels.push_back("");
    menu4ButtonLabels.push_back("");
    menu4ButtonLabels.push_back("");
    menu4ButtonLabels.push_back("");
    vectorOfLabelArrays.push_back(menu4ButtonLabels);
    //Menu 5 Labels - Contains Nothing
    vectorOfLabelArrays.push_back(menu5ButtonLabels);
    //Menu 6 Labels
    menu6ButtonLabels.push_back("");
    menu6ButtonLabels.push_back("");
    menu6ButtonLabels.push_back("");
    menu6ButtonLabels.push_back("");
    menu6ButtonLabels.push_back("");
    menu6ButtonLabels.push_back("");
    menu6ButtonLabels.push_back("");
    menu6ButtonLabels.push_back("");
    menu6ButtonLabels.push_back("");
    vectorOfLabelArrays.push_back(menu6ButtonLabels);
    //Menu 7 Labels
    menu7ButtonLabels.push_back("O");
    menu7ButtonLabels.push_back("P");
    menu7ButtonLabels.push_back("Q");
    menu7ButtonLabels.push_back("R");
    menu7ButtonLabels.push_back("S");
    menu7ButtonLabels.push_back("T");
    menu7ButtonLabels.push_back("Back");
    menu7ButtonLabels.push_back("Back");
    menu7ButtonLabels.push_back("Back");
    vectorOfLabelArrays.push_back(menu7ButtonLabels);
    //Menu 8 Labels
    menu8ButtonLabels.push_back("");
    menu8ButtonLabels.push_back("");
    menu8ButtonLabels.push_back("");
    menu8ButtonLabels.push_back("");
    menu8ButtonLabels.push_back("");
    menu8ButtonLabels.push_back("");
    menu8ButtonLabels.push_back("");
    menu8ButtonLabels.push_back("");
    menu8ButtonLabels.push_back("");
    vectorOfLabelArrays.push_back(menu8ButtonLabels);
    //Menu 9 Labels
    menu9ButtonLabels.push_back("U");
    menu9ButtonLabels.push_back("V");
    menu9ButtonLabels.push_back("W");
    menu9ButtonLabels.push_back("X");
    menu9ButtonLabels.push_back("Y");
    menu9ButtonLabels.push_back("Z");
    menu9ButtonLabels.push_back("Back");
    menu9ButtonLabels.push_back("Back");
    menu9ButtonLabels.push_back("Back");
    vectorOfLabelArrays.push_back(menu9ButtonLabels);
    wordToType = "";
    //Row 1
    button = EyeButton(10, 10, (screenWidth-60)/3, (screenHeight-60)/3, "A B C D E F G", false);
    vectorOfButtons.push_back(button);
    button = EyeButton(10+(screenWidth/3), 10, (screenWidth-60)/3, (screenHeight-60)/3, "Suggestions", false);
    vectorOfButtons.push_back(button);
    button = EyeButton(10+((screenWidth/3)*2), 10, (screenWidth-60)/3, (screenHeight-60)/3, "H I J K L M N", false);
    vectorOfButtons.push_back(button);
    //Row 2
    button = EyeButton(10, 10+(screenHeight/3), (screenWidth-60)/3, (screenHeight-60)/3, "Delete", false);
    vectorOfButtons.push_back(button);
    button = EyeButton(10+(screenWidth/3), 10+(screenHeight/3), (screenWidth-60)/3, (screenHeight-60)/3, "Hello easyKeyboard", false);
    vectorOfButtons.push_back(button);
    button = EyeButton(10+((screenWidth/3)*2), 10+(screenHeight/3), (screenWidth-60)/3, (screenHeight-60)/3, "Other Characters", false);
    vectorOfButtons.push_back(button);
    //Row 3
    button = EyeButton(10, 10+((screenHeight/3)*2), (screenWidth-60)/3, (screenHeight-60)/3, "O P Q R S T", false);
    vectorOfButtons.push_back(button);
    button = EyeButton(10+(screenWidth/3), 10+((screenHeight/3)*2), (screenWidth-60)/3, (screenHeight-60)/3, "Typed so far...", false);
    vectorOfButtons.push_back(button);
    button = EyeButton(10+((screenWidth/3)*2), 10+((screenHeight/3)*2), (screenWidth-60)/3, (screenHeight-60)/3, "U V W X Y Z", false);
    vectorOfButtons.push_back(button);
}

//--------------------------------------------------------------
void ofApp::update(){
    posX = eyex.gazePoint.x; //***COMMENT OUT ON MAC***
    posY = eyex.gazePoint.y; //***COMMENT OUT ON MAC***
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int i = 0; i < vectorOfButtons.size(); i++) {
        vectorOfButtons[i].redrawObject();
        if (vectorOfButtons[i].eyeOnButton(mouseX, mouseY) && !vectorOfButtons[i].getClicked()) {
            cursor.setClicking(true);
            if (cursor.checkClicked()) {
                vectorOfButtons[i].setClicked(true);
                switch (currentGrid) {
                    case 0:
                        currentGrid = menuMain(i);
                        if (currentGrid == 2) {
                            findSuggestions();
                        }
                        if (currentGrid == 5) {
                            vectorOfLabelArrays[0][4] = "";
                            typedSoFar += wordToType + " ";
                            vectorOfLabelArrays[0][7] = typedSoFar;
                            wordToType = "";
                            currentGrid = 0;
                        }
                        break;
                    case 1:
                        menuABC(i);
                        currentGrid = 0;
                        vectorOfLabelArrays[0][4] = wordToType;
                        break;
                    case 2:
                        menuSuggestions(i);
                        currentGrid = 0;
                        vectorOfLabelArrays[0][4] = wordToType;
                        break;
                    case 3:
                        menuHIJ(i);
                        currentGrid = 0;
                        vectorOfLabelArrays[0][4] = wordToType;
                        break;
                    case 4:
                        currentGrid = 0;
                        break;
                    case 5:
                        // Will not be reached
                        break;
                    case 6:
                        currentGrid = 0;
                        break;
                    case 7:
                        menuOPQ(i);
                        currentGrid = 0;
                        vectorOfLabelArrays[0][4] = wordToType;
                        break;
                    case 8:
                        currentGrid = 0;
                        break;
                    case 9:
                        menuUVW(i);
                        currentGrid = 0;
                        vectorOfLabelArrays[0][4] = wordToType;
                        break;
                    default:
                        break;
                }
                for (int i = 0; i < vectorOfButtons.size(); i++) {
                    vectorOfButtons[i].setValue(vectorOfLabelArrays[currentGrid][i]);
                }
            }
        } else if (!vectorOfButtons[i].eyeOnButton(mouseX, mouseY) && vectorOfButtons[i].getClicked()) {
            vectorOfButtons[i].setClicked(false);
        }
    }
    //cursor.redrawObject(mouseX,mouseY); ***COMMENTED OUT - UNCOMMENT ON MAC AND COMMENT NEXT LINE***
    cursor.redrawObject(posX, posY);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    //Won't be used
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    //Won't be used
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    //Won't be used
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    //Won't be used
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    //Won't be used
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    //Won't be used
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    //Won't be used
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    //Won't be used
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 
    //Won't be used
}


//Menu Functions
//Main Menu - Menu #0
int ofApp::menuMain(int i) {
    int valToRet = i+1;
    return valToRet;
}

//ABC Menu - Menu #1
void ofApp::menuABC(int i) {
    switch (i+1) {
        case 1:
            wordToType += "a";
            break;
        case 2:
            wordToType += "b";
            break;
        case 3:
            wordToType += "c";
            break;
        case 4:
            wordToType += "d";
            break;
        case 5:
            wordToType += "e";
            break;
        case 6:
            wordToType += "f";
            break;
        case 8:
            wordToType += "g";
            break;
        default:
            break;
    }
}

//Suggestion Menu - Menu #2
void ofApp::menuSuggestions(int i) {
    if (i != 8) {
        wordToType = vectorOfLabelArrays[2][i];
    }
}

//HIJ Menu - Menu #3
void ofApp::menuHIJ(int i) {
    switch (i+1) {
        case 1:
            wordToType += "h";
            break;
        case 2:
            wordToType += "i";
            break;
        case 3:
            wordToType += "j";
            break;
        case 4:
            wordToType += "k";
            break;
        case 5:
            wordToType += "l";
            break;
        case 6:
            wordToType += "m";
            break;
        case 8:
            wordToType += "n";
            break;
        default:
            break;
    }
}

//Deletion Menu - Menu #4
//INSERT FUNCTION HERE

//Word Menu - Menu #5
//NOT NEEDED

//Extra Menu - Menu #6
//NOT NEEDED

//OPQ Menu - Menu #7
void ofApp::menuOPQ(int i) {
    switch (i+1) {
        case 1:
            wordToType += "o";
            break;
        case 2:
            wordToType += "p";
            break;
        case 3:
            wordToType += "q";
            break;
        case 4:
            wordToType += "r";
            break;
        case 5:
            wordToType += "s";
            break;
        case 6:
            wordToType += "t";
            break;
        default:
            break;
    }
}

//Typed Menu - Menu #8
//INSERT FUNCTION HERE

//UVW Menu - Menu #9
void ofApp::menuUVW(int i) {
    switch (i+1) {
        case 1:
            wordToType += "u";
            break;
        case 2:
            wordToType += "v";
            break;
        case 3:
            wordToType += "w";
            break;
        case 4:
            wordToType += "x";
            break;
        case 5:
            wordToType += "y";
            break;
        case 6:
            wordToType += "z";
            break;
        default:
            break;
    }
}

void ofApp::findSuggestions() {
    //Look for first word that contains the substring of what has been typed so far
    //Then put the first 8 words that contain the substring into the spots
    int numOfSuggestionsFound = 0;
    for (int k = 0; k < wordsEN.size(); k++) {
        if (numOfSuggestionsFound >= 8) {
            k = wordsEN.size();
        } else {
            if (wordsEN[k].substr(0, wordToType.size()) == wordToType) {
                vectorOfLabelArrays[2][numOfSuggestionsFound] = wordsEN[k];
                numOfSuggestionsFound++;
            }
        }
    }
    vectorOfLabelArrays[2][8] = "BACK";
}