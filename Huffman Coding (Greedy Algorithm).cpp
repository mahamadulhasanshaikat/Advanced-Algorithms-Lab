#include <bits/stdc++.h>
using namespace std;

// Node structure for Huffman Tree
struct Node {
    char ch;    // character
    int freq;   // frequency
    Node *left, *right;
    Node(char c, int f) : ch(c), freq(f), left(NULL), right(NULL) {}
};

// Comparator for min-heap
struct compare {
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq;
    }
};

// Function to print Huffman Codes
void printCodes(Node* root, string str){
    if(!root) return;
    if(!root->left && !root->right) 
        cout << root->ch << ": " << str << "\n"; // leaf node = character
    printCodes(root->left, str + "0"); // left = 0
    printCodes(root->right, str + "1"); // right = 1
}

// Huffman coding main function
void HuffmanCoding(vector<char> chars, vector<int> freq){
    priority_queue<Node*, vector<Node*>, compare> pq;

    // Push all chars into min-heap
    for(int i=0; i<chars.size(); i++)
        pq.push(new Node(chars[i], freq[i]));

    // Build tree
    while(pq.size() > 1){
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();
        Node* merged = new Node('$', left->freq + right->freq); // '$' = internal node
        merged->left = left;
        merged->right = right;
        pq.push(merged);
    }

    // Print final Huffman Codes
    printCodes(pq.top(), "");
}

int main(){
    vector<char> chars = {'a','b','c','d','e','f'};
    vector<int> freq = {5,9,12,13,16,45};
    HuffmanCoding(chars, freq);
}
