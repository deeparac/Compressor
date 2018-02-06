#include "include/BaseCompressor.h"

BaseCompressor::BaseCompressor() : totalCharacters(0) {

}

BaseCompressor::~BaseCompressor() {

}

void BaseCompressor::filehandler(const std:string& inputFileName, const std:string& distributionFileName) {
    resetter();
    std::ifstream filestream;
    string line;
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
    codes.clear();
}

void BaseCompressor::encoding(const std::string& input_file) {

}

void BaseCompressor::decoding(const std:string& encoded_file) {

}
