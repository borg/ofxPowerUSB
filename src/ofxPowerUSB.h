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
1. Put libpowerusb.dylib & pwrusbcmd in binary app folder.
2. You might also need to add to Resource folder...ie.
BuildPhases>Copy files
libpowerusb.dylib
Destination Resources

3. But I had to remove it from Link with binary list

The expected paths for the dylib image behaved differently on different OSX systems


I tried to integrate their source code but got internal NSExceptions from their dynlib
I couldn't debug.

Removed pause to enter on pwrusbcmd to prevent getting stuck when not connected.



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
        //cout<<ofSystem(cmd);//this doesn't give output
        
      
        //convert shell command string to chars for system call
        //char *  shPathChar = new char[ cmd.length() + 1 ];
        //strcpy( shPathChar, cmd.c_str() );
        //execute the shell command
        system(cmd.c_str());
    };

    static void turnOffSocket(int i){
        ofxPowerUSB::socketStates[i] = 0;
        string cmd = "../../../pwrusbcmd";
        
        for(int i = 0;i<ofxPowerUSB::socketStates.size();i++){
            cmd+=" "+ofToString(ofxPowerUSB::socketStates[i]);
        }
        cout<<cmd<<endl;
        //cout<<ofSystem(cmd);
        //convert shell command string to chars for system call
        //char *  shPathChar = new char[ cmd.length() + 1 ];
        //strcpy( shPathChar, cmd.c_str() );
        //execute the shell command
        system(cmd.c_str() );
    };


};

#endif
