#include "include/Huffman.h"

Node::Node(char d, int f) {
    data = d;
    frequency = f;
    left = nullptr;
    right = nullptr;
}

bool compare::operator()(const Node* lhs, const Node* rhs) const {
    return lhs -> frequency > rhs -> frequency;
}

Huffman::Huffman() : root(nullptr), curr(nullptr) {}

void Huffman::buildHuffmanTree(const std::string& inputFileName) {
    string distributionFileName = "dist_" + inputFileName;
    filehandler(inputFileName, distributionFileName);

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

void Huffman::generateCodes(const std::string& codes_file) {
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

void Huffman::generator(Node* p, std::string& str, const std::ofstream& os) {
    if (p == nullptr) {
        return;
    }

    if (p -> data != '#') {
        os << p -> data << ": " << str << endl;
        encodes[str] = p -> data;
        decodes[p -> data] = str;
    }

    generator(p -> left, str + "0", os);
    generator(p -> right, str + "1", os);
}

std::string encoding(const std::string& input_file) {
    std::string encoded_string = "";
    std::string line;
    std::ifstream fstream;

    buildHuffmanTree(input_file);
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
        outstream << encoded_string << std::endl;
        outstream.close();
    } catch (std::ofstream::failure e) {
        std::cerr << "Exception occurs writing encoded file.\n";
    }
    std::cout << "Finished writing encoded file." << std::endl;

    return encoded_string;
}

std::string Huffman::decoding(const std:string& encoded_file) {
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
