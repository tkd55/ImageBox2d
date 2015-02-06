//
//  ImageRoi.h
//  emptyExample
//
//  Created by takeda on 2015/02/03.
//
//

#ifndef __emptyExample__ImageRoi__
#define __emptyExample__ImageRoi__

#include <stdio.h>
#include "ofMain.h"
#include "ofxOpenCv.h"
#include "ofxBox2d.h"

#define ROI_NUM 16
#define MOVIE_INPUT_WSIZE   480
#define MOVIE_INPUT_HSIZE   320

class ImageRoi{
    private:
        // variable
        vector<ofxCvColorImage> roiImges;
        ofRectangle setRoiData[ROI_NUM];        // 切り抜く画像の座標
        int shuffleArray[ROI_NUM];              // シャッフルした0~15までの値
    
        ofxBox2d box2d;                         // Box2Dのインスタンス
        vector <ofPtr<ofxBox2dRect> > rects;    // 切った画像を格納する動的配列
        
        ofVideoGrabber  vidGrabber;
        ofxCvColorImage colorImg;
    
        // Method
        void shuffle(int ary[],int size);
    
    public:
        ImageRoi();
        virtual ~ImageRoi();
        void init();
        void update(unsigned char* apImagesPixels);
        void draw();
};

#endif /* defined(__emptyExample__ImageRoi__) */
