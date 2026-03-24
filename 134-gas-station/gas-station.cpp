#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0;   // total gas - total cost
        int tank = 0;    // current tank
        int start = 0;   // starting index

        for (int i = 0; i < gas.size(); i++) {
            int diff = gas[i] - cost[i];
            total += diff;
            tank += diff;

            // If tank becomes negative, reset start
            if (tank < 0) {
                start = i + 1;
                tank = 0;
            }
        }

        // If overall gas is enough
        return (total >= 0) ? start : -1;
    }
};