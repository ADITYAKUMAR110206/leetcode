class Solution {
public:
    vector<vector<int>> result;

    void backtrack(vector<int>& nums, vector<int>& temp, vector<bool>& visited) {
        if (temp.size() == nums.size()) {
            result.push_back(temp);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (!visited[i]) {
                visited[i] = true;
                temp.push_back(nums[i]);

                backtrack(nums, temp, visited);

                temp.pop_back();          // undo choice
                visited[i] = false;       // backtrack
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;
        vector<bool> visited(nums.size(), false);
        backtrack(nums, temp, visited);
        return result;
    }
};
