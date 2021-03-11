class Solution {
public:
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
            if(pos > length)
                length = pos;
        }
        
        //Generate LIS by traversing parent array
        vector<int> LIS(length);
        int k = increasingSub[length];
        for(int j = length - 1; j >= 0; j--)
        {
            LIS[j] = nums[k];
            k = parent[k];
        }
        
        cout << "parent: ";
        for (int i = 0; i < nums.size(); i++) {
            cout << parent[i] << " ";
        }
        cout << endl;
        cout << "increasingSub: ";
        for (int i = 0; i < nums.size() + 1; i++) {
            cout << increasingSub[i] << " ";
        }
        cout << endl;
        
        return LIS;
    }
    
    
    int minimumMountainRemovals(vector<int>& nums) {
        vector<int> lis = genLIS(nums);
        cout << "LIS: ";
        for (int i = 0; i < lis.size(); i++) {
            cout << lis[i] << " ";
        }
        cout << endl;
        
        vector<int> incParentIndexes(nums.size());
        vector<int> incIncreasingSubEndIndexes(nums.size() + 1);
        vector<int> incSubLens(nums.size());
        int incLongestLen = 0;
        for (int i = 0; i < nums.size(); i++) {
            int pos = myBinSearch(nums, incIncreasingSubEndIndexes, 1, incLongestLen, nums[i]);
            incParentIndexes[i] = incIncreasingSubEndIndexes[pos - 1];
            incIncreasingSubEndIndexes[pos] = i;
            incLongestLen = max({incLongestLen, pos});
            incSubLens[i] = pos;
        }
        
        vector<int> decParentIndexes(nums.size());
        vector<int> decIncreasingSubEndIndexes(nums.size() + 1);
        vector<int> decSubLens(nums.size());
        int decLongestLen = 0;
        for (int i = nums.size() - 1; i >= 0; i--) {
            int pos = myBinSearch(nums, decIncreasingSubEndIndexes, 1, decLongestLen, nums[i]);
            decParentIndexes[i] = decIncreasingSubEndIndexes[pos - 1];
            decIncreasingSubEndIndexes[pos] = i;
            decLongestLen = max({decLongestLen, pos});
            decSubLens[i] = pos;
        }
