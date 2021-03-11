class LISInt {
public:
    LISInt(int pInt) {
        val = pInt;
        parent = this;
    }
    int val;
    LISInt* parent;
};
​
class Solution {
public:
    // IcySteam's actual pointer implementation; ref: https://www.youtube.com/watch?v=1RpMc3fv0y4 (by IDeserve@YouTube)
    vector<int> myGenLIS(vector<int>& nums) {
        vector<LISInt*> tracking;
        tracking.push_back(new LISInt(nums[0]));
        for (int i = 1; i < nums.size(); i++) {
            int low = 0;
            int high = tracking.size();
            while (low < high) {
                int mid = floor((low + high) / 2);
                if (nums[i] > tracking[mid]->val) {
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }
            int pos = low;
            LISInt* newEle = new LISInt(nums[i]);
            if (pos > 0) {newEle->parent = tracking[pos - 1];}
            if (pos == tracking.size()) {tracking.push_back(newEle);}
            else {tracking[pos] = newEle;}
        }
        vector<int> output(tracking.size(), 0);
        LISInt* currentLISInt = tracking.back();
        for (int i = tracking.size() - 1; i >= 0; i--) {
            output[i] = currentLISInt->val;
            currentLISInt = currentLISInt->parent;
        }
        return output;
    }
    
    // see 300. Longest Increasing Subsequence
    vector<int> genLIS(vector<int>& nums) {
        vector<int> parent(nums.size(), 0); //Tracking the predecessors/parents of elements of each subsequence.
        vector<int> increasingSub(nums.size() + 1, 0); //Tracking ends of each increasing subsequence.
        int length = 0; //Length of longest subsequence.
        
        for(int i = 0; i < nums.size(); i++)
        {
            //Binary search
            int low = 1;
            int high = length;
            while (low <= high)
            {
                int mid = ceil((low + high) / 2);
                
                if (nums[increasingSub[mid]] < nums[i]) {
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }
            
            int pos = low;
            //update parent/previous element for LIS
            parent[i] = increasingSub[pos - 1];
            //Replace or append
            increasingSub[pos] = i;
            
            //Update the length of the longest subsequence.
