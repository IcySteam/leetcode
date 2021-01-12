// Initial solution O(n)
​
/*
class NumArray {
public:
    NumArray(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            my_array.push_back(nums[i]);
        }
    }
    
    vector<int> my_array;
    
    int sumRange(int i, int j) {
        int output = 0;
        for (int iter = i; iter <= j; iter++) {
            output += my_array[iter];
        }
        return output;
    }
};
*/
​
/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
​
    
// Advanced solution O(1)
    
class NumArray {
public:
    NumArray(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            my_array.push_back(nums[i]);
        }
        if (my_array.size() > 0) {sums.push_back(my_array[0]);}
        if (my_array.size() > 1) {
            for (int i = 1; i < my_array.size(); i++) {
                sums.push_back(sums[i-1] + my_array[i]);
            }
    }
    }
    
    vector<int> my_array;
    vector<int> sums;
    
    int sumRange(int i, int j) {
        int output;
        output = sums[j] - sums[i] + my_array[i];
        return output;
    }
};
