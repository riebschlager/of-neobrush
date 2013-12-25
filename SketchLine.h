//
//  SketchLine.h
//  ofNeoBrush
//
//  Created by Chris Riebschlager on 12/14/13.
//
//

#ifndef __ofNeoBrush__SketchLine__
#define __ofNeoBrush__SketchLine__

#include "ofMain.h"
#include <vector>

class SketchLine {
public:
    
    SketchLine(int _vertMin, int _vertMax, float _easeMin, float _easeMax, float _speedMin, float _speedMax, float _x, float _y);
    void update();
    void render(ofImage * _src, float _alpha);
    
    int numberOfVertices;
    vector <ofVec2f> curveVertices;
    vector <ofVec2f> distances;
    vector <ofVec2f> endPoints;
    float easeFactor;
    float speedFactor;
    
};

#endif /* defined(__ofNeoBrush__SketchLine__) */
