class MedianFinder {
public:
    /** initialize your data structure here. */
    multiset<int> myMSet;
    multiset<int>::iterator med_lo;
    multiset<int>::iterator med_hi;
    MedianFinder() {
        myMSet.clear();
    }
    
    void addNum(int num) {
        if (myMSet.size() == 0) {
            myMSet.insert(num);
            med_lo = myMSet.begin();
            med_hi = myMSet.begin();
        }
        else {
            if (myMSet.size() % 2 != 0) {
                myMSet.insert(num);
                if (num >= *med_hi) {
                    med_hi++;
                }
                else if (num < *med_hi) {med_lo--;}
            }
            else {
                myMSet.insert(num);
                if (num > *med_lo && num < *med_hi) {
                    med_lo++;
                    med_hi--;
                }
                else if (num >= *med_hi) {
                    med_hi = ++med_lo; // IMPORTANT
                }
                else if (num <= *med_lo) {
                    med_lo = --med_hi; // IMPORTANT
                }
            }
        }
    }
    
    double findMedian() {
        return (double)(*med_lo + *med_hi)/2;
    }
};
​
/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
