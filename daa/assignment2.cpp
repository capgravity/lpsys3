#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

struct Node {
    int freq;
    int idx;            // original index (for leaves); smallest index in subtree (for internal nodes)
    Node *left, *right;

    // leaf
    Node(int f, int i) {
        freq = f;
        idx = i;
        left = right = nullptr;
    }

    // internal node
    Node(Node* l, Node* r) {
        freq = l->freq + r->freq;
        idx = min(l->idx, r->idx);
        left = l;
        right = r;
    }
};

// min-heap order: smaller freq first, tie -> smaller idx first
struct Compare {
    bool operator()(Node* a, Node* b) {
        if (a->freq != b->freq) return a->freq > b->freq;
        return a->idx > b->idx;
    }
};

// walk the tree: left adds '0', right adds '1'
void getCodes(Node* root, string curr, vector<string>& codes) {
    if (root->left == nullptr && root->right == nullptr) {
        codes[root->idx] = curr;
        return;
    }
    getCodes(root->left, curr + '0', codes);
    getCodes(root->right, curr + '1', codes);
}

void freeTree(Node* root) {
    if (root == nullptr) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

// returns codes in the same order as the input characters
vector<string> huffmanCodes(const string& s, const vector<int>& freq) {
    int n = s.size();

    if (n == 1) return {"0"};

    priority_queue<Node*, vector<Node*>, Compare> pq;
    for (int i = 0; i < n; i++)
        pq.push(new Node(freq[i], i));

    while (pq.size() > 1) {
        Node* l = pq.top(); pq.pop();
        Node* r = pq.top(); pq.pop();
        pq.push(new Node(l, r));
    }

    Node* root = pq.top();
    vector<string> codes(n);
    getCodes(root, "", codes);
    freeTree(root);
    return codes;
}

int main() {
    string s = "abcdef";
    vector<int> freq = {5, 9, 12, 13, 16, 45};

    vector<string> codes = huffmanCodes(s, freq);

    int total = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        cout << s[i] << " : " << codes[i] << "\n";
        total += freq[i] * codes[i].size();
    }
    cout << "Total bits: " << total << "\n";
    return 0;
}