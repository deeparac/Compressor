#include "include/Shannon.h"

struct cmp {
    bool operator()(const std::pair<int, char>& lhs, std::pair<int, char>& rfhs) const {
        return lhs.first > rhs.first;
    }
}

void Shannon::codelengthProcessor(const std::string& inputFileName) {
    string distributionFileName = "dist_" + inputFileName;
    filehandler(inputFileName, distributionFileName);

    std::priority_queue<std::pair<int, char>, std::vector<std::pair<int, char>>, cmp> rst;
    for (const auto& p : distributions) {
        rst.push({floor((double)p.second / totalCharacters), p.first});
    }

    return rst;
}

void Shannon::generateCodes(const std::string& codes_file) {
    std::priority_queue<pair<char, int>> q(queue_length);
    string code = "";
    while (!q.empty()) {
        const auto p = q.top(); q.pop();
        if (q.empty()) {
            code = "";
            for (int i = 0; i < p.second; ++i) {
                code += "1";
            }
        } else {
            if (p.second == 1) {
                code = "0";
            } else {
                code = "";
                for (int i = 0; i < p.second - 1; ++i) {
                    code += "1";
                }
                code += "0";
            }
        }
        encodes[p.first] = code;
        decodes[code] = p.first;
    }

    std::ofstream codestream;
    try {
        codestream.open(codes_file);
        for (const auto& p : encodes) {
            std::cout << p.first << ": " << p.second << std::endl;
        }
        outstream.close();
    } catch (std::ofstream::failure e) {
        std::cerr << "Exception opening/reading/closing codes file.\n";
    }
    std::cout << "Finished generating codes file." << std::endl;
}

std::string Shannon::encoding(const std::string& input_file) {
    std::string encoded_string = "";
    std::string line;
    std::ifstream fstream;

    codelengthProcessor(input_file);
    // to be fixed.
    generateCodes();

    try {
        fstream.open(input_file);
        if (fstream.is_open()) {
            while (std::getline(fstream, line)) {
                for (const char& c : line) {
                    encoded_string += encodes[c];
                }
            }
            fstream.close();
        }
    } catch (std::ifstream::failure e) {
        std::cerr << "Exception occurs during encoding.\n";
    }
    std::cout << "Finished encoding." << std::endl;

    std::string encoded_file = "coded_" + input_file;
    std::ofstream outstream;
    try {
        outstream.open(encoded_file);
        outstream << coded_string << std::endl;
        outstream.close();
    } catch (std::ofstream::failure e) {
        std::cerr << "Exception occurs writing encoded file.\n";
    }
    std::cout << "Finished writing encoded file." << std::endl;

    return encoded_string;
}

std::string Shannon::decoding(const std:string& encoded_file) {
    std::string decoded_string = "";
    std::string code = "";
    char char_reader;

    std::ifstream fstream;
    try {
        fstream.open(encoded_file);
        if (fstream.is_open()) {
            while (fstream.get(char_reader)) {
                code += char_reader;
                if (decodes.find(code) != decodes.end()) {
                    decoded_string += decodes[code];
                    code = "";
                }
            }
            fstream.close();
        }
    } catch (std::ifstream::failure e) {
        std::cerr << "Exception occurs during encoding.\n";
    }
    std::cout << "Finished decoding." << std::endl;

    return decoded_string;
}
