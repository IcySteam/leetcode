/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *      struct Data;
 *      Data* data;
 *      Iterator(const vector<int>& nums);
 *      Iterator(const Iterator& iter);
 *
 *      // Returns the next element in the iteration.
 *      int next();
 *
 *      // Returns true if the iteration has more elements.
 *      bool hasNext() const;
 *  };
 */
​
class PeekingIterator : public Iterator {
public:
    bool just_peeked;
    int peek_value;
    bool peek_hasNext;
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        // Initialize any member here.
        // **DO NOT** save a copy of nums and manipulate it directly.
        // You should only use the Iterator interface methods.
        just_peeked = false;
        peek_value = nums[0];
    }
    
    // Returns the next element in the iteration without advancing the iterator.
    int peek() {
        if (just_peeked) {return peek_value;}
        else {
            peek_hasNext = Iterator::hasNext();
            peek_value = Iterator::next();
            just_peeked = true;
            return peek_value;
        }
    }
    
    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next() {
        if (just_peeked) {
            just_peeked = false;
            return peek_value;
        }
        else {
            return Iterator::next();
        }
    }
    
    bool hasNext() const {
        if (just_peeked) {
            return peek_hasNext;
        }
        else {
            return Iterator::hasNext();
        }
    }
};
