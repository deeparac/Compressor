#ifndef _HUFFMAN_H
#define _HUFFMAN_H

// ----------- INCLUDES --------------------------------------------------------
#include <queue>
#include <vector>
#include <string>
#include <unordered_map>

// ----------- STRUCT --------------------------------------------------------
struct Node {
    char data;
    int frequency;
    Node* left;
    Node* right;
    // TYPE type;
    //
    // enum TYPE {
    //     LEAF,
    //     NONLEAF
    // };

    Node(char d, int f);
};

struct compare {
    bool operator()(const Node& lhs, const Node& rhs) const;
};

// ----------- CLASS --------------------------------------------------------
class Huffman : public BaseCompressor {
private:
    Node* root;
    void generator(Node* p, std::string str, std::ofstream os);
public:
    Huffman();
    void encoding(std::string input_file);
    void decoding(std:string encoded_file);
    void buildHuffmanTree(std::string input_file);
    void generateCodes(std::string codes_file);
};

#endif
