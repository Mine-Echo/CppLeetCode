#include <string>
using namespace std;

struct Node {
    Node* children[26]{};
    bool end = false;
};

class Trie {
    Node* root;

    void destroy(Node* node) {
        if (node == nullptr) {
            return;
        }
        for (Node* child : node->children) {
            destroy(child);
        }
        delete node;
    }

public:
    Trie() {
        root=new Node();
    }

    void insert(string word) {
        Node* node = root;
        for(char s:word){
            if(node->children[s-97]==nullptr){
                node->children[s-97] = new Node();
            }
            node = node->children[s-97];
        }
        node->end = true;
    }

    bool search(string word) {
        Node* node =root;
        for(char s:word){
            if(node->children[s-97]==nullptr){
                return false;
            }
            node = node->children[s-97];
        }
        if(node->end) return true;
        return false;
    }

    bool startsWith(string prefix) {
        Node* node =root;
        for(char s:prefix){
            if(node->children[s-97]==nullptr){
                return false;
            }
            node = node->children[s-97];
        }
        return true;
    }

    ~Trie() {
        destroy(root);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */