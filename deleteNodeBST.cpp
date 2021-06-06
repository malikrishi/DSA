/*

Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

Search for a node to remove.
If the node is found, delete the node.


Solution : 
Search the left subtree and the right subtree
if the node is the leaf node i.e it doesn't have any child, just delete it and return NULL
if the node has left or right child, delete node and return the left or right child.
if the node has both left and right child, find the min of the right subtree and replace it with current node val and call the delete for the max.
*/
#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int min(TreeNode *root) {
    if ( root->left == nullptr) return root->val;
    return min(root->left);
}

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return root;

        root->left = deleteNode(root->left, key);
        root->right = deleteNode(root->right, key);

        if (root->val == key) {
            if(root->left != nullptr && root->right != nullptr) {
                //Find the min of right subtree
                int min1 = min(root->right);
                root->right = deleteNode(root->right, min1);
                root->val=min1;
                return root;
            }
            else if (root->left != nullptr && root->right == nullptr) {
                TreeNode *left = root->left;
                delete root;
                return left;    
            }
            else if (root->right != nullptr && root->left == nullptr) {
                TreeNode *right = root->right;
                delete root;
                return right;   
            }
            else {
                delete root;
                return nullptr;
            }
        }
        return root;
    }

int main() {
   return 0;
}
