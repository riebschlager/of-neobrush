#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetVerticalSync(true);
    ofBackground(0, 0, 0);
    isDebugOn = false;
    src.loadImage("src1.jpg");
    //src.resize(1920, 1080);
    src.resize(src.width * 2, src.height * 2);
    ofSetWindowShape(src.width, src.height);
    canvas.allocate(width, height, GL_RGBA32F_ARB);
    canvas.begin();
    ofClear(0, 0, 0, 0);
    ofBackgroundGradient(ofColor(20,20,20), ofColor(0,0,0), OF_GRADIENT_CIRCULAR);
    canvas.end();
    
    gui.setup();
    gui.add(numberOfVerticesMin.setup("numberOfVerticesMin", 5, 1, 500));
    gui.add(numberOfVerticesMax.setup("numberOfVerticesMax", 100, 1, 500));
    gui.add(numberOfLines.setup("numberOfLines", 200, 1, 500));
    gui.add(easeMin.setup("easeMin", 0.01f, 0.001f, 0.99f));
    gui.add(easeMax.setup("easeMax", 0.25f, 0.001f, 0.99f));
    gui.add(speedMin.setup("speedMin", 0.25f, 0.001f, 0.99f));
    gui.add(speedMax.setup("speedMax", 0.5f, 0.001f, 0.99f));
    gui.add(lineWeight.setup("lineWeight", 1.0f, 0.001f, 10.0f));
    gui.add(lineAlpha.setup("lineAlpha", 1, 1, 255));
    
    width = ofGetWidth();
    height = ofGetHeight();
}

//--------------------------------------------------------------
void testApp::update(){
    render();
}

void testApp::render(){
    canvas.begin();
    ofNoFill();
    ofSetLineWidth(lineWeight);
    ofEnableBlendMode(OF_BLENDMODE_ALPHA);
    for (int i = 0; i < lines.size(); i++) {
        lines[i].update();
        lines[i].render(&src, lineAlpha);
    }
    ofClearAlpha();
    canvas.end();
}

//--------------------------------------------------------------
void testApp::draw(){
    ofBackground(0, 0, 0);
    ofSetColor(255, 255, 255);
    canvas.draw(0, 0);
    if(isDebugOn) gui.draw();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    switch (key) {
        case 'd':
            isDebugOn = !isDebugOn;
            break;
        case ' ':
            canvas.begin();
            ofClear(0, 0, 0, 0);
            ofBackgroundGradient(ofColor(20, 20, 20), ofColor(0, 0, 0), OF_GRADIENT_CIRCULAR);
            canvas.end();
            break;
        case 's':
            int w = canvas.getWidth();
            int h = canvas.getHeight();
            unsigned char* pixels = new unsigned char[w*h*3];
            ofImage screenGrab;
            screenGrab.allocate(w,h,OF_IMAGE_COLOR);
            screenGrab.setUseTexture(false);
            canvas.begin();
            glPixelStorei(GL_PACK_ALIGNMENT, 1);
            glReadPixels(0, 0, canvas.getWidth(), canvas.getHeight(), GL_RGB, GL_UNSIGNED_BYTE, pixels);
            screenGrab.setFromPixels(pixels, canvas.getWidth(), canvas.getHeight(), OF_IMAGE_COLOR);
            screenGrab.saveImage("output_" + ofToString(ofGetFrameNum()) + ".png", OF_IMAGE_QUALITY_BEST);
            canvas.end();
            break;
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    for (int i = 0; i < numberOfLines; i++) {
        lines.push_back(SketchLine(numberOfVerticesMin, numberOfVerticesMax, easeMin, easeMax, speedMin, speedMax, ofGetMouseX(), ofGetMouseY()));
    }
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    lines.clear();
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){
    
}
