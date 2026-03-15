#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;

    void backtrack(vector<int>& nums, vector<int>& temp, int start) {
        result.push_back(temp);

        for(int i = start; i < nums.size(); i++) {
            if(i > start && nums[i] == nums[i-1]) 
                continue;

            temp.push_back(nums[i]);
            backtrack(nums, temp, i + 1);
            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<int> temp;
        backtrack(nums, temp, 0);

        return result;
    }
};