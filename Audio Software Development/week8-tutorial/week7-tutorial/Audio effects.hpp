//
//  Audio effects.hpp
//  week7-tutorial
//
//  Created by Morgan Quarless-Oates on 28/03/2019.
//  Copyright © 2019 ASD. All rights reserved.
//

#ifndef Audio_effects_hpp
#define Audio_effects_hpp

#include <stdio.h>

class effects
{
    
public:
    effects();
    ~effects();
    
    double* delay();
    void filter();
    
    int getDelay(){return delayTime;}
    int getN(){return N;}
    
    void setDelay(int inputDelay){delayTime = inputDelay;}
    void setN(int inputN){N = inputN;}
    
private:
    double *inputSamples;
    int numSamples;
    int delayTime;
    int N;
    
    
    
};



#endif /* Audio_effects_hpp */
