#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int freq, index;
    Node* l;
    Node* r;
    Node(int f, int i){
        freq=f;
        index=i;
        l=nullptr;
        r=nullptr;
    }
    Node(Node* left, Node* right){
        freq= left->freq+ right->freq;
        index= min(left->index, right->index);
        l= left;
        r=right;
    }
};

struct Compare{
    bool operator()(Node* a, Node* b){
        if(a->freq!=b->freq){
            return a->freq>b->freq;
        }
        return a->index>b->index;
    }
};

void getCodes(Node* root, string s, vector<string>& codes){
    if(root->l==nullptr && root->r==nullptr){
        codes[root->index]= s;
        return;
    }
    getCodes(root->l, s+'0', codes);
    getCodes(root->r, s+'1', codes);
}

void freeNodes(Node* root){
    if(root==nullptr){
        return;
    }
    freeNodes(root->l);
    freeNodes(root->r);
    delete(root);
}
vector<string> huffmancodes(string& s, vector<int>& freq){
    if(s.size()==1){
        return {"0"};
    }
    priority_queue<Node*, vector<Node*>, Compare> pq;
    for(int i=0; i<freq.size(); i++){
        pq.push(new Node(freq[i], i));
    }
    while(pq.size()>1){
        Node* n1= pq.top(); pq.pop();
        Node* n2= pq.top(); pq.pop();
        Node* n3= new Node(n1, n2);
        pq.push(n3);
    }
    Node* root= pq.top();
    int n=s.size();
    vector<string>codes(n);
    getCodes(root, "", codes);
    return codes;
}

int main(){
    string s= "abcdef";
    vector<int>freq={5, 9, 12, 13, 16, 45};
    vector<string>codes;
    codes = huffmancodes(s, freq);
    // for(int i=0; i<codes.size(); i++){
    //     cout<<codes[i]<<endl;
    // }
    for(int i=0; i<freq.size(); i++){
        cout<<"character : "<<s[i]<<"\n";
        cout<<"code : "<<codes[i]<<endl;
    }
    return 0;
}
//remember priority queue needs to sort by freq, thats why we push freq into the queue first.
//check out the compare function
//also check what values u r passing to each function like getCodes etc.