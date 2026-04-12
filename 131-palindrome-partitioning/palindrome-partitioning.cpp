#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> result;

    bool isPalindrome(string &s, int start, int end) {
        while (start <= end) {
            if (s[start] != s[end]) return false;
            start++;
            end--;
        }
        return true;
    }

    void backtrack(string &s, int index, vector<string> &path) {
        if (index == s.size()) {
            result.push_back(path);
            return;
        }

        for (int i = index; i < s.size(); i++) {
            if (isPalindrome(s, index, i)) {
                path.push_back(s.substr(index, i - index + 1));
                backtrack(s, i + 1, path);
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> path;
        backtrack(s, 0, path);
        return result;
    }
};