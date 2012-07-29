#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	//we run at 60 fps!
	ofSetVerticalSync(true);
	ofSetFrameRate(60);

    //create the socket and bind to port 11999
    string bCastIPAddress = "142.104.211.255";
	udpConnection.Create();
    //udpConnection.BindMcast(const_cast<char*>(mCastIPAddress.c_str()), 11999);
	udpConnection.Bind(11999);
    udpConnection.SetEnableBroadcast(true);
	udpConnection.SetNonBlocking(true);
    udpConnection.SetEnableBroadcast(true);
	ofSetBackgroundAuto(false);
	ofBackground(255, 255, 255);
    val = 0;
    colour = 1;
}

//--------------------------------------------------------------
void testApp::update(){

//	char udpMessage[10];
//	udpConnection.Receive(udpMessage,10);
//	string message=udpMessage;
//    if (message!="") {
//        
//        recieved_val = atof(ofToString(message).c_str());
//        if (recieved_val < 256)  {
//            val = 2*recieved_val;
//        }
//        
//    }
    
    char udpMessage[1000];
    string message;
    string tempMessage;
    bool getNext = true;
    
    while (getNext) {
        udpConnection.Receive(udpMessage,1000);
        tempMessage=udpMessage;
        
        if (tempMessage=="") {
            getNext = false;
        }
        else {
            message = tempMessage;
        }
    }
    
    if(message!=""){
        recieved_val = atof(ofToString(message).c_str());
        if (recieved_val < 256)  {
            val = 2*recieved_val;
        }
    }

    
    
    
//	if(message!=""){
//        stroke.clear();
//		float x,y;
//		vector<string> receivedString = ofSplitString(message,"[/p]");
//		for(int i=0;i<receivedString.size();i++){
//            val = atof(receivedString[i].c_str());
////			vector<string> point = ofSplitString(strPoints[i],"|");
////			if( point.size() == 2 ){
////				x=atof(point[0].c_str());
////				y=atof(point[1].c_str());
////				stroke.push_back(ofPoint(x,y));
////			}
//		}
//	}

}

//--------------------------------------------------------------
void testApp::draw(){
    if (colour == 1) {
        ofBackground(val, val, val);
    }
    else if (colour == 2) {
        ofBackground(val, 0, 0);
    }
    else if (colour == 3) {
        ofBackground(0, val, 0);
    }
    else if (colour == 4) {
        ofBackground(0, 0, val);
    }
    else {
        ofBackground(val, val, val);
    }
    
    ofFill();
    //ofSetHexColor(0xFFFFFF);
    //ofRect(0,0,200,30);
	//ofSetHexColor(0x101010);
	//ofDrawBitmapString("udprecieve", 10, 20);
    //ofDrawBitmapString(ofToString(recieved_val), 30, 40);
//	for(int i=1;i<stroke.size();i++){
//		ofLine(stroke[i-1].x,stroke[i-1].y,stroke[i].x,stroke[i].y);
//	}
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if (key == '1') {
        colour = 1;
    }
    else if (key == '2') {
        colour = 2;
    }
    else if (key == '3') {
        colour = 3;
    }
    else if (key == '4') {
        colour = 4;
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

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

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
