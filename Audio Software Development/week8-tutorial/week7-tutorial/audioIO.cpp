#include "audioIO.hpp"

using namespace std;

AudioFile::AudioFile()
{
    inputBuffer = NULL;
    len = 0;
    numChannels = 0;
    fs = 0;
    file = "";
   

}

AudioFile::~AudioFile()
{
    if (inputBuffer!=NULL)
    {
        delete []inputBuffer;
    }
}

void AudioFile::read(string fileName)
{
    file = fileName;

    SF_INFO fileInfo;
    SNDFILE *sndFile = sf_open(fileName.c_str(), SFM_READ, &fileInfo);

    if (sndFile == NULL)
    {
        cout << "Error reading this file..." << endl;

    }

    else
    {
        if(inputBuffer != NULL)
        {
            // do this incase you read a file in more than once
            delete [] inputBuffer;
        }
        
        inputBuffer = new double[fileInfo.frames];
        
        sf_readf_double(sndFile, inputBuffer, fileInfo.frames);
        
        // set the other audio file properties
        len         = (int)fileInfo.frames;
        fs          = fileInfo.samplerate;
        numChannels = fileInfo.channels;
    }
    sf_close(sndFile);

}


void AudioFile::write(string outputFileName)
{
    
    SF_INFO info;
    info.format = SF_FORMAT_WAV | SF_FORMAT_PCM_16;
    info.channels = numChannels;
    info.samplerate = fs;
    SNDFILE *sndFile = sf_open(outputFileName.c_str(), SFM_WRITE, &info);
    if (sndFile == NULL)
    {
        cout << "Error: Could not write this file "<<endl;
    }
    else
    {
        sf_writef_double(sndFile, inputBuffer, len);
    }
    sf_write_sync(sndFile);
    sf_close(sndFile);
}



void AudioFile::describe()
{
    if (inputBuffer != NULL)
    {
        cout << "FileName: " << file << endl;
        cout << "Length: " << (float)len/fs << "s" << endl;
        cout << "Samplerate: " << fs << endl;
        cout << "Channels: " << numChannels << endl;
    }
    else
    {
        cout << "Error, file not loaded" << endl;
    }
}

void AudioFile::print()
{
    if (inputBuffer != NULL)
    {
        for (int i=0; i<numSamplesToPrint; i++) {
            cout << i << " = " << inputBuffer[i] << endl;
            
        }
    }
        else
        {
            cout << "Error, file not loaded" << endl;
        }
    
}

void  AudioFile::scale()
{
    if (inputBuffer != NULL)
    {
        for (int i=0; i<numSamples; i++) {
            inputBuffer[i] *= scalingFactor;
            
        }
    }
         else
        {
         cout << "Error, file not loaded" << endl;
        }
    
}

void AudioFile::reverse()
{
      if (inputBuffer != NULL)
     {
         for (int i=0; i<numSamples/2; i++) {
             double tmp  = inputBuffer[i];
             int mirror = numSamples-1-i;
             
             inputBuffer[i] = inputBuffer[mirror];
             inputBuffer[mirror] = tmp;
         }
     }
         else
         {
             cout << "Error, file not loaded" << endl;
         }
         
     }
         
