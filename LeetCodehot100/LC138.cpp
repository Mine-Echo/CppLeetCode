#include <iostream>
#include <unordered_map>
using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};


class Solution {
public:

    // use hash table to store the mapping between original nodes and copied nodes
    // Node* copyRandomList(Node* head) {
    //     if (!head) return nullptr;

    //     unordered_map<Node*, Node*> node_map;
    //     Node* current = head;

    //     // First pass: create a copy of each node and store it in the map
    //     while (current) {
    //         node_map[current] = new Node(current->val);
    //         current = current->next;
    //     }

    //     // Second pass: assign next and random pointers
    //     current = head;
    //     while (current) {
    //         node_map[current]->next = current->next ? node_map[current->next] : nullptr;
    //         node_map[current]->random = current->random ? node_map[current->random] : nullptr;
    //         current = current->next;
    //     }

    //     return node_map[head];
    // }

    // O(1) space solution
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        // Step 1: Create a copy of each node and insert it between the original node and its next node
        Node* current = head;
        while (current) {
            Node* copy = new Node(current->val);
            copy->next = current->next;
            current->next = copy;
            current = copy->next;
        }
        // Step 2: Assign random pointers to the copied nodes
        current = head;
        while (current) {
            if (current->random) {
                current->next->random = current->random->next;
            }
            current = current->next->next;
        }
        // Step 3: Separate the original list and the copied list
        current = head;
        Node* copy_head = head->next;
        while (current) {
            Node* copy = current->next;
            current->next = copy->next;
            copy->next = copy->next ? copy->next->next : nullptr;
            current = current->next;
        }
        return copy_head;
    }
};