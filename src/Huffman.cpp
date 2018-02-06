#include "Huffman.h"

Node::Node(char d, int f) {
    data = d;
    frequency = f;
    left = nullptr;
    right = nullptr;
}

bool compare::operator()(const Node* lhs, const Node* rhs) const {
    return lhs -> frequency > rhs -> frequency;
}

Huffman::Huffman() : root(nullptr) {}

void Huffman::buildHuffmanTree(std::string input_file) {
    string distributionFileName = "dist_" + input_file;
    filehandler(input_file, distributionFileName);

    std::priority_queue<Node*, std::vector<Node*>, compare> heap;
    for (const auto& p : distributions) {
        heap.push(new Node(p.first, p.second));
    }

    // start building huffman tree
    while (heap.size() != 1) {
        Node* left = heap.top(); heap.pop();
        Node* right = heap.top(); heap.pop();

        Node* superSymbol = new Node(
            '#',
            left -> frequency + right -> frequency;
        )
        superSymbol -> left = left;
        superSymbol -> right = right;

        heap.push(superSymbol);
    }

    root = heap.top(); heap.pop();
    curr = root;
    try {
        assert(heap.empty());
        std::cout << "Finished encoding, and Huffman Tree is built!" << std::endl;
    } catch {
        std::cout << "Failed building, please try again." << std::endl;
    }
}

void Huffman::generateCodes(std::string codes_file) {
    Node* curr = root;
    std::ofstream codestream;
    try {
        codestream.open(codes_file);
        generator(curr, "", codestream);
        outstream.close();
    } catch (std::ofstream::failure e) {
        std::cerr << "Exception opening/reading/closing codes file.\n";
    }
    std::cout << "Finished generating codes file." << std::endl;
}

void Huffman::generator(Node* p, std::string str, std::ofstream os) {
    if (p == nullptr) {
        return;
    }

    if (p -> data != '#') {
        os << p -> data << ": " << str << endl;
        codes[p -> data] = str;
    }

    generator(p -> left, str + "0", os);
    generator(p -> right, str + "1", os);
}

std::string encoding(std::string input_file) {
    std::string coded_string = "";
    std::string line;

    std::ifstream fstream;
    try {
        fstream.open(input_file);
        if (fstream.is_open()) {
            while (getline(fstream, line)) {
                for (const char& c : line) {
                    coded_string += codes[c];
                }
            }
            fstream.close();
        }
    } catch (std::ifstream::failure e) {
        std::cerr << "Exception occurs during encoding.\n";
    }
    std::cout << "Finished encoding." << std::endl;

    std::string output_file = "coded_" + input_file;
    std::ofstream outstream;
    try {
        outstream.open(output_file);
        outstream << coded_string << std::endl;
        outstream.close();
    } catch (std::ofstream::failure e) {
        std::cerr << "Exception occurs writing encoded file.\n";
    }
    std::cout << "Finished writing encoded file." << std::endl;
}

std::string Huffman::decoding(std:string encoded_file) {

}
