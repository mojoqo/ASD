//
//  analytics.cpp
//  week7-tutorial
//
//  Created by Morgan Quarless-Oates on 28/03/2019.
//  Copyright © 2019 ASD. All rights reserved.
//

#include "analytics.hpp"
double mean(double *samples, int numSamples) {
    
    
    double sum=0, mean;
    
    for (int i=0; i<numSamples; i++)
    {
        sum += samples[i];
    }
    
    
    mean = sum/(double)numSamples;
    return mean;
    




}


double rms(double *samples, int numSamples){
    
    
    float sum=0, mean, rms;
    
    for (int i=0; i<numSamples; i++)
    {
        sum = sum+(samples[i]*samples[i]);
    }
    
    mean = sum/(float)numSamples;
    rms = sqrt(mean);
    return rms;
}
