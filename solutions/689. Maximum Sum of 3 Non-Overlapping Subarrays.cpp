//         for (int i = 0; i < nums.size() - k; i++) {
//             windowSum -= nums[i];
//             windowSum += nums[i + k];
//             mySet.insert(Cluster(windowSum, i + 1));
//             // cout << i + 1 << "\t" << windowSum << endl;
//         }
//         // for (auto it = mySet.begin(); it != mySet.end(); it++) {
//         //     cout << (*it).index << "\t" << (*it).val << endl;
//         // }
        
        
//         vector<int> output;
//         return output;
//     }
// };
​
// sliding window O(n)
class Solution {
 public:  
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        const int numWindows = 3;
        vector<int> currentWindowSums(numWindows);
        for (int i = 0; i < numWindows; i++) {
            currentWindowSums[i] = accumulate(nums.begin() + i * k, nums.begin() + i * k + k, 0);
            // cout << currentWindowSums[i] << " ";
        }
        vector<int> currentIndices;
        for (int i = 0; i < numWindows; i++) {
            currentIndices.push_back(i * k);
        }
        
        vector<vector<int>> bestIndices;
        bestIndices.push_back({currentIndices[0]});
        for (int i = 1; i < numWindows; i++) {
            vector<int> tmp = bestIndices[i - 1];
            tmp.push_back(currentIndices[i]);
            bestIndices.push_back(tmp);
        }
        vector<int> accuSums;
        accuSums.push_back(currentWindowSums[0]);
        for (int i = 1; i < numWindows; i++) {
            accuSums.push_back(accuSums[i - 1] + currentWindowSums[i]);
        }
        
        while (currentIndices[0] < nums.size() - numWindows * k) {
            for (int i = 0; i < numWindows; i++) {
                // cout << currentIndices[i] << endl;
                currentWindowSums[i] -= nums[currentIndices[i]];
                currentWindowSums[i] += nums[currentIndices[i] + k];
            }
            // cout << currentIndices[0] << " ";
            
            if (currentWindowSums[0] > accuSums[0]) {
                accuSums[0] = currentWindowSums[0];
                bestIndices[0][0] = currentIndices[0] + 1;
            }
            for (int i = 1; i < numWindows; i++) {
                if (currentWindowSums[i] + accuSums[i - 1] > accuSums[i]) {
                    accuSums[i] = currentWindowSums[i] + accuSums[i - 1];
                    bestIndices[i] = bestIndices[i - 1];
                    bestIndices[i].push_back(currentIndices[i] + 1);
                }
            }
            
            for (int i = 0; i < numWindows; i++) {currentIndices[i]++;}
        }
        
        return bestIndices[bestIndices.size() - 1];
    }
};
