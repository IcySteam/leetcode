class Solution {
public:
    static bool myComparator(const vector<int>& v1, const vector<int>& v2) {
        return (v1.front() < v2.front());
    }
    
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {
        unordered_map<int, int> used_freq;
        vector<vector<int>> vals_labels;
        int num_used = 0;
        int output = 0;
        for (int i = 0; i < values.size(); i++) {
            vector<int> current;
            current.push_back(values[i]);
            current.push_back(labels[i]);
            vals_labels.push_back(current);
        }
        sort(vals_labels.begin(), vals_labels.end(), myComparator);
        for (int i = 0; i < labels.size(); i++) {
            used_freq[labels[i]] = 0;
        }
        while (num_used < num_wanted) {
            if (vals_labels.empty()) {break;}
            else if (used_freq[vals_labels.back().back()] < use_limit) {
                used_freq[vals_labels.back().back()]++;
                output += vals_labels.back().front();
                num_used++;
                vals_labels.pop_back();
            }
            else {
                vals_labels.pop_back();
            }
        }
        return output;
    }
};
