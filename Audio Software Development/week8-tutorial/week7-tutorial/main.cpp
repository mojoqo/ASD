/*
 Welcome to the week 8 seminar...

 I have now completed the audio read/write functions for you.
 Please read through them to see if you understand the code.
 All of the code is based on the tutorial in weeks 6/7

 Please take the time this week to finish the remining functions.
 - void printSamples(float* inputSignal, int numSamplesToPrint);
 - void scaleSignal(float* inputSignal, int numSamples, float scalingFactor);
 - void reverseSignal(float* inputSignal, int numSamples);
 
 */
#include <iostream>
#include "audioIO.hpp"
#include <stdio.h>
#include "analytics.hpp"
#include "Audio effects.hpp"
using namespace std;

int main()
{
    string homeDir = getenv("HOME");
    string inputFile = homeDir + "/Desktop/nobody.wav";
    string outputFile = homeDir + "/Desktop/nobody_processed.wav";
    
    
    
    
    // use the audioFile class
    AudioFile audio;
    audio.read(inputFile);
    audio.describe();
    audio.write(outputFile);
    audio.print();
    audio.scale();
    audio.reverse();
    audio.setnumSamplesToPrint(5);
    audio.setScalingFactor(0.5);
    
 
    
    
    
    
    
    
    
    // find the audio file on the desktop
    
   
    
    
    //len holds the length, samplerate and number of channels
 
    
    // audioread() returns a pointer to an array of floating point audio samples
    // if all goes well, you won't see any errors printed out to console
    // make sure you call wavread like this:
   
    
    // ==========================================================================
    // ======== These are the functions that you need to finish =================
    // ==========================================================================
    
    // let's check everything worked by printing some of the samples
   
    
    //cout << "Mean: " << mean(inputSignal, numSamples) << endl;
    //cout << "RMS: " << rms(inputSignal, numSamples) << endl;
    
    
    //scale the entire signal down by half
    //float scalingFactor = 0.5;
    //scaleSignal(inputSignal, numSamples, scalingFactor);

    // let's check again by printing the same audio samples (did they double in value?)
    //printSamples(inputSignal, numValuesToPrintOut);

    // let's finish by reversing our audio signal so it sounds cool
    //reverseSignal(inputSignal, numSamples);
    
    // ==========================================================================
    //int delaySamples = 0.2 * fs;
    //double* delaySignal = delay(inputSignal, numSamples, delaySamples);
    
    //int delaySignalSamples = numSamples + delaySamples;
    
   //int N = 10000;
    
    //double* filterSignal = filter(inputSignal,numSamples, N);
    
    
    
    
    
    return 0;
}
