#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0, 0, 0);
    ofSetWindowShape(DISPLAYWIDTH, DISPLAYHEIGHT);
    ofSetFrameRate(30);
    
    kinect.setup();
    kinect.setRegister(true);
    kinect.setMirror(true);
    kinect.addDepthGenerator();
    kinect.addImageGenerator();
    kinect.addHandsGenerator();
    kinect.addAllHandFocusGestures();
    kinect.setMaxNumHands(1);
    
    
    kinect.start();
    
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    kinect.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    kinect.drawImage(0, 0, DISPLAYWIDTH, DISPLAYHEIGHT);

    ofSetColor(255, 0, 0);
    ofLine(0, threshold, ofGetWidth(), threshold);
    if (kinect.getNumTrackedHands() == 1) {
        ofxOpenNIHand hand = kinect.getTrackedHand(0);
        ofPoint handPoint = hand.getPosition();
        ofCircle(handPoint.x, handPoint.y, 20);
        
        if (handPoint.y < threshold) {
            static int bakuha = 0;
            bakuha++;
            
            cout << "超えたよ";
            cout <<bakuha << endl;
        }
    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
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
