class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> output;
        if (arr.empty()) {return output;}
        vector<int> sorted = arr;
        sort(sorted.begin(), sorted.end());
        unordered_map<int, int> ranks;
        int currentRank = 1;
        int currentVal = sorted[0];
        for (int i = 0; i < sorted.size(); i++) {
            if (sorted[i] > currentVal) {
                currentRank++;
                currentVal = sorted[i];
            }
            ranks[sorted[i]] = currentRank;
        }
        for (int i = 0; i < arr.size(); i++) {
            output.push_back(ranks[arr[i]]);
        }
        return output;
    }
};
