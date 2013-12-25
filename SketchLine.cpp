#include "SketchLine.h"

SketchLine::SketchLine(int _vertMin, int _vertMax, float _easeMin, float _easeMax, float _speedMin, float _speedMax, float _x, float _y){
    numberOfVertices = ceil(ofRandom(_vertMin, _vertMax));
    easeFactor = ofRandom(_easeMin, _easeMax);
    speedFactor = ofRandom(_speedMin, _speedMax);
    for (int i = 0; i < numberOfVertices; i++) {
        curveVertices.push_back(ofVec2f(_x, _y));
        distances.push_back(ofVec2f::zero());
        endPoints.push_back(ofVec2f::zero());
    }
}

void SketchLine::update() {
    for (int i = 0; i < curveVertices.size(); i++) {
        distances[i].x = (i == 0) ? ofGetMouseX() - curveVertices[0].x : curveVertices[i - 1].x - curveVertices[i].x;
        distances[i].y = (i == 0) ? ofGetMouseY() - curveVertices[0].y : curveVertices[i - 1].y - curveVertices[i].y;
        distances[i] *= easeFactor;
        endPoints[i] += distances[i];
        curveVertices[i] += endPoints[i];
        endPoints[i] *= speedFactor;
    }
}

void SketchLine::render(ofImage * _src, float _alpha) {
    ofSetPolyMode(OF_POLY_WINDING_ODD);
    ofBeginShape();
    for (int i = 0; i < curveVertices.size(); i++) {
        int x = 0;
        int y = 0;
        if (curveVertices[i].x > 0 && curveVertices[i].y < ofGetWidth() && curveVertices[i].y > 0 && curveVertices[i].y < ofGetHeight()) {
            x = curveVertices[i].x;
            y = curveVertices[i].y;
        }
        ofSetColor(_src->getColor(x, y), _alpha);
        ofCurveVertex(curveVertices[i].x, curveVertices[i].y);
    }
    ofEndShape();
}