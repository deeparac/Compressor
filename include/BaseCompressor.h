#ifndef _BASECOMPRESSOR_H
#define _BASECOMPRESSOR_H

// ---------- INCLUDES -------------------------------------------------------
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

// ----------- CLASS ---------------------------------------------------------
class BaseCompressor {
private:
    unordered_map<char, int> distributions;
    unordered_map<char, string> encodes;
    unordered_map<string, char> decodes;
    int totalCharacters;
public:
    BaseCompressor();
    ~BaseCompressor();
    void filehandler(const std:string& inputFileName, const std:string& distributionFileName);
    void resetter();
    virtual std::string encoding(std::string& input_file) = 0;
    virtual std::string decoding(std:string& encoded_file) = 0;
};

#endif
