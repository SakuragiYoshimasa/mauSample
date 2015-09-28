#include "ofApp.h"
unsigned char * data;
int imgW,imgH;
vector<ofColor *> colors;
int num = 0;
int preTime = 0;
void ofApp::setup(){
    img.loadImage("icon.jpg");

    img.resize(32, 32);
    data = img.getPixels();
    imgW = img.getWidth();
    imgH = img.getHeight();
    for(int x = 0; x < imgH * imgW * 3; x+=3){colors.push_back(new ofColor(data[x],data[x+1],data[x+2]));}
    num++;
    ofSetLineWidth(10);
}
void ofApp::update(){
    cout << "NUM:" << num << "\n" << "time" << ofGetElapsedTimeMillis() - preTime << endl;
    preTime = ofGetElapsedTimeMillis();
}

void ofApp::draw(){
    for(int n = 0; n < num; n++){
        for(int x = 0; x < imgW; x++){
            for(int y = 0; y < imgH; y++){
                ofSetColor(*colors.at(x + y * imgW + n * imgW * imgH));
                ofRect(x * 2 + 64 * n,  y * 2 , 1, 1);
            }
        }
    }
    ofPushStyle();
    ofSetColor(0, 255, 0);
    ofLine(ofGetWidth()/2,ofGetHeight()/2,
           ofGetWidth()/2 + 200 * sin((float)ofGetElapsedTimeMillis() / 100.0),
           ofGetHeight()/2  + 200 * cos((float)ofGetElapsedTimeMillis() / 100.0));
    ofPopStyle();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    num++;
    for(int x = 0; x < imgH * imgW * 3; x+=3){
        //string name = "icon" + ofToString(num % 5) + ".jpg";
        string name = "icon" + ofToString(num % 5) + ".jpg";
        img.loadImage(name);
        img.resize(32, 32);
        data = img.getPixels();
        colors.push_back(new ofColor(data[x],data[x+1],data[x+2]));
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
