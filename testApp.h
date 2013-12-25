#pragma once

#include "ofMain.h"
#include "SketchLine.h"
#include <vector>
#include "ofxGui.h"
#include "ofxGaussianBlur.h"

class testApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    void render();
    
    vector<SketchLine> lines;
    ofImage src;
    
    ofxFloatSlider lineWeight;
    ofxIntSlider lineAlpha;
    ofxIntSlider imageAlpha;
    ofxFloatSlider easeMin;
    ofxFloatSlider easeMax;
    ofxFloatSlider speedMin;
    ofxFloatSlider speedMax;
    ofxIntSlider numberOfLines;
    ofxIntSlider numberOfVerticesMin;
    ofxIntSlider numberOfVerticesMax;
    ofFbo canvas;
    ofxPanel gui;
    ofxGaussianBlur blur;
    
    int width, height;
    bool isDebugOn;
};
