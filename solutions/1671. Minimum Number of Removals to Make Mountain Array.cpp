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
        
        return LIS;
    }
    
    
    int minimumMountainRemovals(vector<int>& nums) {
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
        
        //cout << incLongestLen << " " << decLongestLen << endl;
        int output = 0;
        for (int i = 0; i < nums.size(); i++) {
            //cout << incSubLens[i] << " " << decSubLens[i] << endl;
            if (incSubLens[i] > 1 && decSubLens[i] > 1) {output = max({output, incSubLens[i] + decSubLens[i]});}
        }
        output = nums.size() - output + 1;
        return output;
    }
    
    int myBinSearch(const vector<int>& nums, const vector<int>& indexes, int start, int end, int target) {
        if (start > end) {return start;}
        int mid = (start + end) / 2;
        if (nums[indexes[mid]] < target) {return myBinSearch(nums, indexes, mid + 1, end, target);}
        else if (nums[indexes[mid]] > target) {return myBinSearch(nums, indexes, start, mid - 1, target);}
        else {return mid;}
    }
};     
