class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        unordered_map<int, int> earliestStarts;
        unordered_map<int, int> latestEnds;
        for (int i = 0; i < clips.size(); ++i) {
            vector<int> truncClip = clips[i];
            truncClip[1] = min({time, truncClip[1]});
            if (earliestStarts.find(truncClip[1]) == earliestStarts.end()) {
                earliestStarts[truncClip[1]] = truncClip[0];
            }
            else {
                earliestStarts[truncClip[1]] = min({earliestStarts[truncClip[1]], truncClip[0]});
            }
            if (latestEnds.find(truncClip[0]) == latestEnds.end()) {
                latestEnds[truncClip[0]] = truncClip[1];
            }
            else {
                latestEnds[truncClip[0]] = max({latestEnds[truncClip[0]], truncClip[1]});
            }
        }
        
        list<vector<int>> finalists;
        for (int i = 0; i <= time; ++i) {
            if (latestEnds.find(i) != latestEnds.end()) {
                if (i == earliestStarts[latestEnds[i]]) {
                    finalists.push_back({i, latestEnds[i]});
                }
            }
        }
        
        // printList(finalists.begin(), finalists.end());
        unordered_map<int, int> coverage;
        
        while (narrowDownCount != 0) {
            narrowDown(finalists, coverage, finalists.begin(), finalists.end());
        }
        
//         cout << "------------\n";
//         printList(finalists.begin(), finalists.end());
        
        bool allCovered = true;
        for (int i = 0; i < time; ++i) {
            if (coverage.find(i) == coverage.end()) {
                allCovered = false;
                break;
            }
            if (coverage[i] == 0) {
                allCovered = false;
                break;
            }
        }
        return allCovered? finalists.size() : -1;
    }
    
    void printList(list<vector<int>>::iterator begin, list<vector<int>>::iterator end) {
        for (auto it = begin; it != end; ++it) {
            cout << (*it)[0] << " " << (*it)[1] << endl;
