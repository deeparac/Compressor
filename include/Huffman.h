#ifndef _HUFFMAN_H
#define _HUFFMAN_H

// ----------- STRUCT --------------------------------------------------------
struct Node {
    string data;
    int frequency;
    Node* left;
    Node* right;

    enum TYPE {
        LEAF,
        NONLEAF
    };

    Node(string d, int f, TYPE t = leaf);
};

struct compare {
    bool operator()(const Node& lhs, const Node& rhs) const;
};

// ----------- CLASS --------------------------------------------------------
class Huffman : public BaseCompressor {

};

#endif
