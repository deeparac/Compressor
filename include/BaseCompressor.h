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
public:
    BaseCompressor();
    ~BaseCompressor();
    void filehandler(std:string inputFileName, std:string distributionFileName);
    void encoding(std::string input_file);
    void decoding(std:string encoded_file);
};

#endif
