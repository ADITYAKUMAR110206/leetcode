#include <vector>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode() : val(0), left(nullptr), right(nullptr) {}
 * TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    void findPaths(TreeNode* node, int targetSum, vector<int>& currentPath, vector<vector<int>>& result) {
        if (!node) return;

        // Add current node to the path
        currentPath.push_back(node->val);

        // Check if it's a leaf node and the sum matches
        if (!node->left && !node->right && targetSum == node->val) {
            result.push_back(currentPath);
        } else {
            // Continue exploring left and right branches
            // We subtract the current value from targetSum for the next level
            findPaths(node->left, targetSum - node->val, currentPath, result);
            findPaths(node->right, targetSum - node->val, currentPath, result);
        }

        // Backtrack: remove the node before going back up the tree
        currentPath.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> currentPath;
        findPaths(root, targetSum, currentPath, result);
        return result;
    }
};