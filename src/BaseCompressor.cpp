#include "BaseCompressor.h"

BaseCompressor::BaseCompressor() {

}

BaseCompressor::~BaseCompressor() {

}

void BaseCompressor::filehandler(std:string inputFileName, std:string distributionFileName) {
    std::ifstream filestream;
    string line;
    try {
        filestream.open(inputFileName);
        if (filestream.is_open()) {
            while (getline(filestream, line)) {
                for (const char& c : line) {
                    distributions[c] += 1;
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

void BaseCompressor::encoding(std::string input_file) {

}

void BaseCompressor::decoding(std:string encoded_file) {

}