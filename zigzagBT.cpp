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
 *

Solution : Keep Two stacks
Push into the s1 initially the root .
Pop the stack and add the left and right to s2.
If s1 gets empty assign s1 to s2.
Keep a bool variable that toggles at each level and inserts right and left or left and right alternatively.
Loop till s1 becomes empty
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) return result;
        stack<TreeNode *> s1;
        stack<TreeNode *> s2;
        int level = 0;
        bool reverse = true;
        s1.push(root);
        while(!s1.empty()) {
            vector<int> currLevel;
        while(!s1.empty()) {
            TreeNode *currNode = s1.top();
            if (currNode)
                currLevel.push_back(currNode->val);
            if (!reverse) {
                if (currNode && currNode->right)
                    s2.push(currNode->right);
                if (currNode && currNode->left)
                    s2.push(currNode->left);
            } else {
                if (currNode && currNode->left)
                    s2.push(currNode->left);
                if (currNode && currNode->right)
                    s2.push(currNode->right);
            }
            s1.pop();
            
        }
        result.push_back(currLevel);
        stack<TreeNode*> temp;
            temp = s1;
            s1 = s2;
            s2 = temp;
        reverse = !reverse;
        }
        return result;
    }
    
};
