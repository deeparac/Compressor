#ifndef _SHANNON_H
#define _SHANNON_H

// ----------- INCLUDES -----------------------------------------------------
#include <cmath>
#include <queue>

// ----------- CLASS --------------------------------------------------------
class Shannon : public BaseCompressor {
private:
    std::unordered_map<char, int> codelength;
    std::priority_queue<pair<char, int>> queue_length;
    void codelengthProcessor(const std::string& inputFileName);
};

#endif
