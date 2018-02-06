#include "../include/BaseCompressor.h"

BaseCompressor::BaseCompressor() : totalCharacters(0) {

}

BaseCompressor::~BaseCompressor() {

}

std::unordered_map<char, int> BaseCompressor::getDistributions() {
    return distributions;
}

void BaseCompressor::setEncodes(char key, std::string val) {
    encodes[key] = val;
}

void BaseCompressor::setDecodes(std::string key, char val) {
    decodes[key] = val;
}

std::string BaseCompressor::getEncodes(char key) {
    return encodes[key];
}
char BaseCompressor::getDecodes(std::string key) {
    return decodes[key];
}

bool BaseCompressor::decodesContain(std::string key) {
    return decodes.find(key) != decodes.end();
}

void BaseCompressor::filehandler(const std::string& inputFileName, const std::string& distributionFileName) {
    resetter();
    std::ifstream filestream;
    std::string line;
    try {
        filestream.open(inputFileName);
        if (filestream.is_open()) {
            while (getline(filestream, line)) {
                for (const char& c : line) {
                    distributions[c] += 1;
                    totalCharacters += 1;
                }
            }
            filestream.close();
        }
    } catch (std::ifstream::failure e) {
        std::cerr << "Exception opening/reading/closing input file.\n";
    }
    std::cout << "Finished handling file and built distributions." << std::endl;

    std::ofstream outstream;
    try {
        outstream.open(distributionFileName);
        for (const auto& p : distributions) {
            outstream << p.first << ": " << p.second << std::endl;
        }
        outstream.close();
    } catch (std::ofstream::failure e) {
        std::cerr << "Exception opening/reading/closing output file.\n";
    }
    std::cout << "Finished outputing distributions file." << std::endl;
}

void BaseCompressor::resetter() {
    totalCharacters = 0;
    distributions.clear();
    encodes.clear();
    decodes.clear();
}
