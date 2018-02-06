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
    unordered_map<char, string> codes;
    int totalCharacters;
public:
    BaseCompressor();
    ~BaseCompressor();
    void filehandler(std:string inputFileName, std:string distributionFileName);
    void resetter();
    virtual void encoding(std::string input_file) = 0;
    virtual void decoding(std:string encoded_file) = 0;
};

#endif
