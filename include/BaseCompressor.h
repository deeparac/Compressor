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
    std::unordered_map<char, int> distributions;
    std::unordered_map<char, std::string> encodes;
    std::unordered_map<std::string, char> decodes;
    int totalCharacters;
public:
    BaseCompressor();
    ~BaseCompressor();

    // setter & getter
    void resetter();
    void setEncodes(char key, std::string val);
    void setDecodes(std::string key, char val);
    std::string getEncodes(char key);
    char getDecodes(std::string key);
    bool decodesContain(std::string key);
    std::unordered_map<char, int> getDistributions();

    // generic file reader
    void filehandler(const std::string& inputFileName, const std::string& distributionFileName);

    // need to be overided
    virtual std::string encoding(std::string& input_file, const std::string& codes_file) = 0;
    virtual std::string decoding(std::string& encoded_file) = 0;
    virtual void generateCodes(const std::string& codes_file) = 0;
};

#endif
