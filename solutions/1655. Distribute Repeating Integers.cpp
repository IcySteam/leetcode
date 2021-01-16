class Solution {
public:
    /* // WRONG SOLUTION, greedy approach
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        map<int, int> int_amount;
        map<int, set<int>> amount_ints;
        for (auto ele : nums) {
            if (int_amount.find(ele) == int_amount.end()) {int_amount[ele] = 1;}
            else {int_amount[ele]++;}
        }
        for (auto ele : int_amount) {
            amount_ints[ele.second].insert(int_amount[ele.first]);
        }
        for (int i = 0; i < quantity.size(); i++) {
            cout << "LOOP\n";
            int next_valid_amount = 0;
            int next_valid_integer; // important
            for (auto ele : int_amount) {
                if ((ele.second >= quantity[i] && next_valid_amount == 0) || (ele.second >= quantity[i] && ele.second < next_valid_amount)) {
                    next_valid_amount = ele.second;
                    next_valid_integer = ele.first;
                }
            }
            cout << next_valid_amount << endl;
            if (next_valid_amount == 0) {return false;}
            amount_ints[next_valid_amount - quantity[i]].insert(next_valid_integer);
            int_amount[next_valid_integer] -= quantity[i];
            amount_ints[next_valid_amount].erase(next_valid_integer); // using iterator in .erase() without dereferencing causes program to hang; using .first() can produce unpredictable results without next_valid_integer
            cout << "DONE LOOP\n";
        }
        cout << "EXIT\n";
        return true;
    }
    */
    
    bool can = false;
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        unordered_map<int, int> int_amount;
        for (auto ele : nums) {
            int_amount[ele]++;
        }
        sort(quantity.rbegin(), quantity.rend());
        vector<int> counts;
        for (auto& ele : int_amount) {
            counts.push_back(ele.second);
        }
        //sort(counts.rbegin(), counts.rend()); // unnecessary; see else {break;} below
        DFS(counts, quantity, 0);
        return can;
    }
    void DFS(vector<int>& counts, vector<int>& quantity, int iter) {
        if (can || iter == quantity.size()) { // "can ||" reduces runtime significantly by terminating unnecessary operations early in the stack frame
            can = true;
            return;
        }
        for (int i = 0; i < counts.size(); i++) {
            if (counts[i] >= quantity[iter]) {
                counts[i] -= quantity[iter];
                DFS(counts, quantity, iter + 1);
                counts[i] += quantity[iter];
            }
            //else {break;} // doesn't work because counts gets changes every iter and it is not guaranteed that greater elements always come before smaller ones
        }
    }
};
