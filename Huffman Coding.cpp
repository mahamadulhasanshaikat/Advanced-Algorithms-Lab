#include <bits/stdc++.h>
using namespace std;

// Node structure for Huffman Tree
struct Node {
    char ch;
    int freq;
    Node *left, *right;
    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = NULL;
    }
};

// Compare for priority queue (min-heap)
struct compare {
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq;
    }
};

// Traverse tree and store Huffman Codes
void storeCodes(Node* root, string str, unordered_map<char, string> &huffmanCode) {
    if (!root) return;

    // If it's a leaf node (character found)
    if (!root->left && !root->right) {
        huffmanCode[root->ch] = str;
    }

    storeCodes(root->left, str + "0", huffmanCode);
    storeCodes(root->right, str + "1", huffmanCode);
}

// Build Huffman Tree
Node* buildHuffmanTree(string text) {
    unordered_map<char, int> freq;
    for (char ch : text) freq[ch]++;

    priority_queue<Node*, vector<Node*>, compare> minHeap;

    // Create a leaf node for each character
    for (auto pair : freq) {
        minHeap.push(new Node(pair.first, pair.second));
    }

    // Merge nodes until one tree remains
    while (minHeap.size() != 1) {
        Node* left = minHeap.top(); minHeap.pop();
        Node* right = minHeap.top(); minHeap.pop();

        Node* merged = new Node('\0', left->freq + right->freq);
        merged->left = left;
        merged->right = right;
        minHeap.push(merged);
    }
    return minHeap.top();
}

// Encode the input text
string encodeText(string text, unordered_map<char, string> &huffmanCode) {
    string encoded = "";
    for (char ch : text) {
        encoded += huffmanCode[ch];
    }
    return encoded;
}

// Decode encoded string
string decodeText(Node* root, string encoded) {
    string decoded = "";
    Node* curr = root;
    for (char bit : encoded) {
        if (bit == '0') curr = curr->left;
        else curr = curr->right;

        if (!curr->left && !curr->right) {
            decoded += curr->ch;
            curr = root;
        }
    }
    return decoded;
}

// Main function
int main() {
    string text = "this is a test string for huffman coding";

    // Step 1: Build Huffman Tree
    Node* root = buildHuffmanTree(text);

    // Step 2: Generate Huffman Codes
    unordered_map<char, string> huffmanCode;
    storeCodes(root, "", huffmanCode);

    cout << "Huffman Codes:\n";
    for (auto pair : huffmanCode) {
        cout << pair.first << ": " << pair.second << "\n";
    }

    // Step 3: Encode text
    string encoded = encodeText(text, huffmanCode);
    cout << "\nEncoded Data:\n" << encoded << "\n";

    // Step 4: Decode text
    string decoded = decodeText(root, encoded);
    cout << "\nDecoded Data:\n" << decoded << "\n";

    return 0;
}
