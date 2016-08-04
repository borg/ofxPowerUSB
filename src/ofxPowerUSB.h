// =============================================================================
//
// ofxPowerUSB.h
// PowerUSB
//
// Created by Andreas Borg on 8/1/16
//
// Copyright (c) 2015-2016 Andreas Borg LocalProjects
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
// =============================================================================

#ifndef _ofxPowerUSB
#define _ofxPowerUSB

#include "ofMain.h"

//http://www.pwrusb.com/powerUSB-basic.html

/*
Put libpowerusb.dylib & pwrusbcmd in binary app folder
I tried to integrate their source code but got internal NSExceptions from their dynlib
I couldn't debug
*/


class ofxPowerUSB {
	
  public:
	
	ofxPowerUSB(){};
    ~ofxPowerUSB(){};

    static vector<int>socketStates;
    
    static void turnOnSocket(int i){
        ofxPowerUSB::socketStates[i] = 1;

        string cmd = "../../../pwrusbcmd";
        for(int i = 0;i<ofxPowerUSB::socketStates.size();i++){
            cmd+=" "+ofToString(ofxPowerUSB::socketStates[i]);
        }
        cout<<cmd<<endl;
        ofSystem(cmd);
    };

    static void turnOffSocket(int i){
        ofxPowerUSB::socketStates[i] = 0;
        string cmd = "../../../pwrusbcmd";
        
        for(int i = 0;i<ofxPowerUSB::socketStates.size();i++){
            cmd+=" "+ofToString(ofxPowerUSB::socketStates[i]);
        }
        ofSystem(cmd);
    };


};

#endif
