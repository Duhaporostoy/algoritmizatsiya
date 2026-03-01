#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

int findMax(Node* root) {
    if (root == nullptr) return INT_MIN;
    int leftMax  = findMax(root->left);
    int rightMax = findMax(root->right);
    return max({root->val, leftMax, rightMax});
}

int main() {
    

    Node* root = new Node(1);
    root->left  = new Node(3);
    root->right = new Node(5);
    root->left->left   = new Node(8);
    root->left->right  = new Node(10);
    root->right->left  = new Node(2);
    root->right->right = new Node(6);
    root->left->left->left   = new Node(14);
    root->left->left->right  = new Node(15);
    root->left->right->right = new Node(3);
    root->right->right->left  = new Node(0);
    root->right->right->right = new Node(1);

    cout << "Максимальная яркость: " << findMax(root) << endl;
   
    return 0;
}
