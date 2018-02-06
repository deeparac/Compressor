#ifndef _HUFFMAN_H
#define _HUFFMAN_H

// ----------- INCLUDES --------------------------------------------------------
#include <queue>
#include <vector>
#include <string>
#include <unordered_map>
#include <cassert>
#include "../include/BaseCompressor.h"

// ----------- STRUCT --------------------------------------------------------
struct Node {
    enum TYPE {
        SYMBOL,
        SUPERSYMBOL
    };

    char data;
    int frequency;
    Node* left;
    Node* right;
    TYPE type;

    Node(char d, int f, TYPE t);
};

struct compare {
    bool operator()(const Node* lhs, const Node* rhs) const;
};

// ----------- CLASS --------------------------------------------------------
class Huffman : public BaseCompressor {
private:
    Node* root;
    void generator(Node* p, const std::string& str, std::ofstream& os);
    void buildHuffmanTree(const std::string& input_file);
public:
    Huffman();
    ~Huffman();
    std::string encoding(const std::string& input_file, const std::string& codes_file);
    std::string decoding(const std::string& encoded_file);
    void generateCodes(const std::string& codes_file);
    std::string decodingFromExternalFile(const std::string& encoded_file, const std::string& codes_file);
};

#endif
