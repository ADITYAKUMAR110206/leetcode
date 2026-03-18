#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<int, int> mp;
    int idx;

    TreeNode* build(vector<int>& postorder, int left, int right) {
        if (left > right) return NULL;

        int val = postorder[idx--];
        TreeNode* root = new TreeNode(val);

        int pos = mp[val];

        root->right = build(postorder, pos + 1, right);
        root->left = build(postorder, left, pos - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }
        idx = postorder.size() - 1;
        return build(postorder, 0, inorder.size() - 1);
    }
};