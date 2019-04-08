//
//  Audio effects.cpp
//  week7-tutorial
//
//  Created by Morgan Quarless-Oates on 28/03/2019.
//  Copyright © 2019 ASD. All rights reserved.
//

#include "Audio effects.hpp"


double* effects::delay()
{
    double *y = new double[numSamples + delayTime];
    if (y == NULL) {
        return NULL;
    }
    for (int i=0; i<(numSamples+delayTime); i++)
    {
        if(i<delayTime)
            y[i] = inputSamples[i];
        else if(i>=delayTime && i<numSamples)
            y[i] = inputSamples[i] + inputSamples[i-delayTime];
        else
            y[i] = inputSamples[i-delayTime];
        
    }
    
    return y;
    
    
    
}







double* delay(double *inputSamples, int numSamples, int delay) {
    
    double *y = new double[numSamples + delayTime];
    if (y == NULL) {
        return NULL;
    }
    for (int i=0; i<(numSamples+delayTime); i++)
    {
        if(i<delay)
            y[i] = inputSamples[i];
        else if(i>=delayTime && i<numSamples)
            y[i] = inputSamples[i] + inputSamples[i-delayTime];
        else
            y[i] = inputSamples[i-delayTime];

    }
    
    return y;
    
    
    
}

double* filter(double *inputSamples, int numSamples, int N) {
    
    
    double *y = new double[numSamples-(N-1)];
    
    for (int i=0; i<numSamples-(N-1); i++)
    {
        float sum = 0;
        for (int j=0; j<N; j++)
        {
            sum = sum + inputSamples[i+j];
        }
        y[i] = sum/N;
    }
    
    return y;

}
