#include <iostream>
#include <algorithm> // for std::max

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int treeHeight(TreeNode* root) {
    if (root == nullptr) {
        return -1; // Height in terms of edges
        // return 0; // Use this for height in terms of nodes
    }
    int leftHeight = treeHeight(root->left);
    int rightHeight = treeHeight(root->right);
    return 1 + std::max(leftHeight, rightHeight);
}

int main() {
    // Example tree:
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    std::cout << "Height of the tree: " << treeHeight(root) << std::endl;

    return 0;
}