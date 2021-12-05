//by Sultan
//normalization.cpp

#include "normalization.h"

//Finds the largest value in the data
float Normalization::findMaxVal(std::vector<float> data, float largestValue){
	for(unsigned int i = 0; i < data.size(); i++){
        if(largestValue < data[i]){
            largestValue = data[i];
        }
    }
	return largestValue;
}
float Normalization::findMultiplier(float largestValue, float multiplier){
    multiplier = 1 / largestValue;
    return multiplier;
}
//Dvides all the values in the data by the largest value to Normalize the data
std::vector<float> Normalization::normalizeData(std::vector<float> data, float multiplier){
	std::vector<float> modifiedData;
	for(unsigned int i = 0; i < data.size(); i++){
		modifiedData[i] = data[i] * multiplier;
	}
	return modifiedData;
}