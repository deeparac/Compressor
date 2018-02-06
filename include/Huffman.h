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
    void generator(Node* p, std::string&s str, const std::ofstream& os);
public:
    Huffman();
    void encoding(const std::string& input_file);
    std::string decoding(const std:string& encoded_file);
    std::string decodingFromExternalFile(const std:string& encoded_file, const std:string& encoded_file);
    void buildHuffmanTree(const std::string& input_file);
    void generateCodes(const std::string& codes_file);
};

#endif
