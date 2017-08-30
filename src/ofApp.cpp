#include "ofApp.h"
#include "ImageRoi.h"


//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0, 0, 0);
    
    windowWidth = ofGetWidth();
    windowHeight = ofGetHeight();
    
    cam.initGrabber(640, 480);
    colorImg.allocate(640, 480);
}

//--------------------------------------------------------------
void ofApp::update(){
    cam.update();
    
    colorImg.setFromPixels(cam.getPixels().getData(), 640, 480);
    
    unsigned char* pImagesPixels = colorImg.getPixels().getData();
    imageroi.update(pImagesPixels);
}

//--------------------------------------------------------------
void ofApp::draw(){
    imageroi.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){
    
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
