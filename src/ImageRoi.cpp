//
//  ImageRoi.cpp
//  emptyExample
//
//  Created by takeda on 2015/02/03.
//
//
#include "ImageRoi.h"

#define ROI_WSIZE   120
#define ROI_HSIZE   80

ImageRoi::ImageRoi(){
    init();
}

ImageRoi::~ImageRoi(){
    
}

void ImageRoi::init() {
    
    // 分割したデータの領域確保
    for(int cnt = 0; cnt < ROI_NUM; cnt++){
        ofxCvColorImage roi;
        roi.allocate(MOVIE_INPUT_WSIZE, MOVIE_INPUT_HSIZE);
        roiImges.push_back(roi);
    }
    
    // 切り抜く画像の座標情報の設定
    for(int cnt = 0; cnt < ROI_NUM; cnt++){
        setRoiData[cnt].x = (cnt % 4) * ROI_WSIZE;
        setRoiData[cnt].y = floor(cnt / 4) * ROI_HSIZE;
        setRoiData[cnt].width = ROI_WSIZE;
        setRoiData[cnt].height = ROI_HSIZE;
    }
    
    box2d.init();
    box2d.setFPS(60);
    box2d.setGravity(0, 1);
    box2d.createBounds(0, 0, ofGetWidth(), ofGetHeight());
    box2d.registerGrabbing();
    
    // Box2dRectの設定
    for(int cnt = 0; cnt < ROI_NUM; cnt++){
        ofPtr<ofxBox2dRect> rect = ofPtr<ofxBox2dRect>(new ofxBox2dRect);
        rect.get()->setPhysics(1.5, 1.08, 0.1);
        rect.get()->setup(box2d.getWorld(), setRoiData[cnt].x+100, setRoiData[cnt].y+100,
                                            setRoiData[cnt].width, setRoiData[cnt].height);
        rects.push_back(rect);
    }
}

bool bNewFrame = false;
void ImageRoi::update( unsigned char* apImagesPixels ){
    
    box2d.update();
    
    // 取り込んだフレームをピクセルデータに変換
    for(int cnt = 0; cnt < ROI_NUM; cnt++){
        roiImges[cnt].setFromPixels(apImagesPixels, 640, 480);
        // 切り抜き
        roiImges[cnt].setROI(setRoiData[cnt]);
    }
}

void ImageRoi::draw(){
    for(int cnt = 0; cnt < ROI_NUM; cnt++){
        
        ofPushMatrix();
            ofPoint pos = rects[cnt].get()->getPosition();
            pos.x -= 60;
            pos.y -= 40;
            float width = rects[cnt].get()->getWidth();
            float height = rects[cnt].get()->getHeight();
        
            ofTranslate(rects[cnt].get()->getPosition().x, rects[cnt].get()->getPosition().y, 0);
            ofRotate(rects[cnt].get()->getRotation());
            roiImges[cnt].drawROI(0, 0, width, height);
        ofPopMatrix();
    }
}

void ImageRoi::shuffle(int ary[],int size){
    for(int i=0;i<size;i++){
        int j = rand()%size;
        int t = ary[i];
        ary[i] = ary[j];
        ary[j] = t;
    }
}
