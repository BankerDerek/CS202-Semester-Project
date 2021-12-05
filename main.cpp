#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <windows.h>
#include <stdio.h>
#include <ctype.h>

#include "AudioModule.h"
#include "LowPassFilter.h"
#include "GainAdjustment.h"

//#include "waveHeader.h"

using namespace std;


typedef struct waveHeader 
{
    // RIFF Header
    char riff_header[4];        // "RIFF"
    int wav_size;               // RIFF Chunk size 
    char wave_header[4];        // Wave Header 

    // Header information
    char fmt_header[4];         // "FMT"
    int fmt_chunk_size;         // FMT Chunk size
    short audio_format;         // Audio format: 1=PCM, 6=mulaw, 7=alaw, 257=IBM Mu-Law, 258=IBM A-Law, 259=ADPCM 
    short num_channels;         // Number of channels: 1=Mono 2=Sterio
    int sample_rate;            // Sampling Frequency
    int byte_rate;              // bytes per second: sample_rate * num_channels * bytes per sample
    short sample_alignment;     // num_channels * bytes per sample 
    short bit_depth;            // Number of bits per sample 

    // Data
    char data_header[4];        // 
    int data_bytes;             // 

} wav_header;
class FileIO
{
    private:
        vector<double> soundData;

        char* buffer;
        
        vector<string> metadata; 

        string filePath;


    public: 
        void importFile (string inputFilePath)
        {
            if (fileCheck(inputFilePath))
            {
                std::ifstream file(inputFilePath, std::ios::binary | std::ios::in);
                if (file.is_open())
                {
                    file.read((char*)&waveHeader, sizeof(wav_header));
                    buffer = new unsigned char[waveHeader.data_bytes];
                    file.read((char*)buffer, waveHeader.data_bytes);
                    file.close();
                }
            }
            else 
            {
                throw "File reading error";
            }
        }

        void exportFile (string filePath, vector<string> metaData)
        {

        }

        vector<double> getSoundData() 
        {
            return soundData;
        }

        void setSoundData (vector<double> inputData)
        {
            soundData.clear();
            soundData = inputData;
        }

         vector<string> getMetaData ()
        {

        }


    private:
        bool fileCheck(string inputFilePath)
        {
            std::ifstream infile(inputFilePath);
            return (infile.good() && inputFilePath.substr(inputFilePath.find_last_of(".") + 1) == "wav");
        }




}; 


    // Sultan
    class Normalization : AudioModule  
    {

    };

    // Derek
    class Echo : AudioModule  
    {

    };
    /*
    // Connor
    class GainAdjustment : AudioModule  
    {

    };

    // Connor
    class LowPassFilter : AudioModule  
    {

    };
    */

    // Sultan
    class Compression : AudioModule  
    {

    };
main(int argc, char *argv[])
{
    // Class inintalizations
    WavFileIO audioFile;
    
    
    // Intoduction
    cout << endl << "Initializing Audio Editor..." << endl;
    
    // Asks the user to open the menu or quit
    char* userInput;
    cout << "Type 'e' to exit the program. Type 'm' to go to the menu" << endl;
    while (true)
    {
        cout << "\tInput: ";
        cin >> userInput;

        if (userInput[0] == 'e')
        {
            cout << "\tExiting program..." << endl;
            return 0;
        }    
        if (userInput[0] == 'm')
        {
            cout << endl << "Entering Menu..." << endl;
            break;
        }
        cout << "\tInvalid input. Please try again" << endl;
    }

    // Asks for file and checks if valid
    cout << "Please provide the path of the file you wish to load." << endl;
    while (true)
    {
        cout << "\tFile path: ";
        cin >> userInput;
        // cout << "UserInput: \"" << userInput << "\"" << endl;
        if (audioFile.validateFile(userInput))
        {
            cout << "\tFile loaded successfully." << endl << endl;
            break;
        }
        cout << endl << "\tFile failed to load. Please try a different file." << endl;
    }
    
    // Module selection
    cout << "Input the number of the module you would like to apply." << endl;
    cout << "\t1 : Normalization" << endl;
    cout << "\t2 : Echo" << endl;
    cout << "\t3 : GainAdjustment" << endl;
    cout << "\t4 : LowPassFilter" << endl;
    cout << "\t5 : Compression" << endl;

    


    
}
