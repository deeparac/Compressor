#ifndef _SHANNON_H
#define _SHANNON_H

// ----------- INCLUDES -----------------------------------------------------
#include <cmath>
#include <queue>
#include <vector>
#include <string>
#include <unordered_map>
#include <utility>


struct cmp {
    bool operator()(const std::pair<int, char>& lhs, std::pair<int, char>& rhs);
};

// ----------- CLASS --------------------------------------------------------
class Shannon : public BaseCompressor {
private:
    std::unordered_map<char, int> codelength;
    std::priority_queue< std::pair<char, int>, cmp> queue_length;
    void codelengthProcessor(const std::string& inputFileName);
public:
    Shannon();
    ~Shannon();
    std::string encoding(const std::string& input_file, const std::string& codes_file);
    std::string decoding(const std::string& encoded_file);
    void generateCodes(const std::string& codes_file);
};

#endif
