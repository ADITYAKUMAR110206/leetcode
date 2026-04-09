#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<string, vector<string>> memo;

    vector<string> solve(string s, unordered_set<string>& st) {
        if (memo.count(s)) return memo[s];

        vector<string> res;

        if (st.count(s)) res.push_back(s);

        for (int i = 1; i < s.size(); i++) {
            string left = s.substr(0, i);
            string right = s.substr(i);

            if (st.count(left)) {
                vector<string> temp = solve(right, st);
                for (string &t : temp) {
                    res.push_back(left + " " + t);
                }
            }
        }

        return memo[s] = res;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        return solve(s, st);
    }
};