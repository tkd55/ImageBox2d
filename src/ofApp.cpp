#include "ofApp.h"
#include "ImageRoi.h"

#define MOVIE_INPUT_WSIZE   480
#define MOVIE_INPUT_HSIZE   320

#define MOVIE_INPUT_WSIZE_640   640
#define MOVIE_INPUT_HSIZE_480   480

//#define ROI_WSIZE   480
//#define ROI_HSIZE   320

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0, 0, 0);
    
    
    windowWidth = ofGetWidth();
    windowHeight = ofGetHeight();
    // 検分器は重いので検出する画像は小さくする
    cam.initGrabber(MOVIE_INPUT_WSIZE, MOVIE_INPUT_HSIZE);
    
    colorImg.allocate(MOVIE_INPUT_WSIZE, MOVIE_INPUT_HSIZE);
}

//--------------------------------------------------------------
void ofApp::update(){
    // カメラ入力の更新
    cam.update();
    
    // 取り込んだフレームを画像としてキャプチャ
    colorImg.setFromPixels(cam.getPixels(), MOVIE_INPUT_WSIZE, MOVIE_INPUT_HSIZE);
    
    unsigned char* pImagesPixels = colorImg.getPixels();
    imageroi.update(pImagesPixels);
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    imageroi.draw();
}


//--------------------------------------------------------------
void ofApp::shuffle(int ary[],int size){
    for(int i=0;i<size;i++){
        int j = rand()%size;
        int t = ary[i];
        ary[i] = ary[j];
        ary[j] = t;
    }
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