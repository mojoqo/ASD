//
//  audioIO.hpp
//  week7-tutorial
//
//  Created by DMT Lab on 22/03/2018.
//  Copyright © 2018 ASD. All rights reserved.
//

#ifndef audioIO_hpp
#define audioIO_hpp

#include <iostream>
#include <sndfile.h>

using namespace std;

class AudioFile
{
    
public:
    AudioFile();
    ~AudioFile();
    
    void read(string inputFileName);
    void write(string fileNameOut);
    void describe();
    void print();
    void reverse();
    void scale();
    
    int getfs(){return fs;}
    float getScalingFactor(){return scalingFactor;}
    int getnumSamplesToPrint(){return numSamplesToPrint;}
    
    
    
    void setfs(int inputFs){fs = inputFs;}
    void setScalingFactor(float inputScalingFactor){scalingFactor = inputScalingFactor;}
    void setnumSamplesToPrint(int inputnumSamplesToPrint){numSamplesToPrint = inputnumSamplesToPrint;}
    

private:
    int len;
    int fs;
    int numChannels;
    double *inputBuffer;
    
    int numSamplesToPrint;
    int numSamples;
    float scalingFactor;
    string file;
};













#endif /* audioIO_hpp */
