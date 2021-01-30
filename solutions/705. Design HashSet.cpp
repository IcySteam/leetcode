class MyHashSet {
public:
    /** Initialize your data structure here. */
    char* nums;
    int size = 1000001;
        
    MyHashSet() {
        nums = new char[size];
        for (int i = 0; i < size; i++) {
            nums[i] = 0;
        }
    }
    
    void add(int key) {
        nums[key] = 1;
    }
    
    void remove(int key) {
        nums[key] = 0;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return nums[key] == 1? true : false;
    }
    
    ~MyHashSet() {
        delete[] nums;
    }
};
​
/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
