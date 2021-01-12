class NumArray {
public:
    NumArray(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            array.push_back(nums[i]);
        }
    }
    
    vector<int> array;
    
    int sumRange(int i, int j) {
        int output = 0;
        for (int iter = i; iter <= j; iter++) {
            output += array[iter];
        }
        return output;
    }
};
​
/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
