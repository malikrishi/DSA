/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
/*
Problem : 
Two players play a turn based game on a binary tree.  We are given the root of this binary tree, and the number of nodes n in the tree.  n is odd, and each node has a distinct value from 1 to n.

Initially, the first player names a value x with 1 <= x <= n, and the second player names a value y with 1 <= y <= n and y != x.  The first player colors the node with value x red, and the second player colors the node with value y blue.

Then, the players take turns starting with the first player.  In each turn, that player chooses a node of their color (red if player 1, blue if player 2) and colors an uncolored neighbor of the chosen node (either the left child, right child, or parent of the chosen node.)

If (and only if) a player cannot choose such a node in this way, they must pass their turn.  If both players pass their turn, the game ends, and the winner is the player that colored more nodes.

You are the second player.  If it is possible to choose such a y to ensure you win the game, return true.  If it is not possible, return false. 
*/

/* Solution : 
The idea is to count the number of nodes in each node adjacent to the node that red player chooses. This blicks the re palyer to move in that subtree and we pick the max of each and see it is greater than remaining nodes + 1 that red chose.
    If the max of the number of nodes in the left subtree, right subtree and the other subtree of it's parent where the red node is not present is greater than n - calculted nodes , then second player wins.
*/
class Solution {
public:
    //To find the node that Player 1 has chosen
    TreeNode *searchNode(TreeNode *root, int val) {
        if (root == nullptr ) return nullptr;
        if(root->val == val) return root;
        //Search the left subtree
        TreeNode *nodeLeft = searchNode(root->left, val);
        //Search the left subtree
        TreeNode *nodeRight = searchNode(root->right, val);
        return (nodeLeft ? nodeLeft : nodeRight);
    }
    
    int countNodes(TreeNode *root) {
        if (root== nullptr) {
            return 0;
        }
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
    
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        int leftNodes = 0,  rightNodes = 0, parentNodes = 0;
        if (root == nullptr) return false;
        TreeNode *redNode = searchNode(root, x);
        //Count Nodes in left subtree
        leftNodes = countNodes(redNode->left);
        //Count Nodes in right subtree
        rightNodes = countNodes(redNode->right);
        int maxLR = max(leftNodes, rightNodes);
        //Count nodes in remaining tree if parent is chosen.
        if (redNode != root) {
            parentNodes = n - (leftNodes  + rightNodes + 1);
        }
        int maxNodes = max(parentNodes, maxLR);
        int redNodes = n - maxNodes;
        if (maxNodes > redNodes ) return true;
        return false;      
    }
};
