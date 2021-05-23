/*
Problem ::
Find the diamter of a binary tree.
Diamter is the maximum distance bewteen two leaf nodes of a tree.

Solution : 
The diamter can be max of :
    1. height of left sub tree + height of right subtree + 2
    2. Diameter of left subtree
    3 Diamter of right subtree
*/


#include <iostream>
#include <cstddef>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;

    TreeNode() {}
    TreeNode (int val) : val(val), left(0), right(0) {}
};


pair<int, int> findDia(TreeNode *root) {
    if (root == NULL) {
        return {0, 0};
    }
    pair<int,int> dl = findDia(root->left);
    pair<int,int> dr = findDia(root->right);

    
    int dia = max(max(dl.first, dr.first), (dl.second + dr.second + 1));
    return {dia, max(dl.second, dr.second) + 1};

}

int diameter(TreeNode *root) {

    pair<int, int> ret = findDia(root);
    return ret.first;

}


int main()
{
  
    /* Constructed binary tree is
            1
            / \
        2     3
        / \
    4     5
    */
    struct TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
     
    // Function Call
    cout << "Diameter of the given binary tree is " << diameter(root);
  
    return 0;
}
