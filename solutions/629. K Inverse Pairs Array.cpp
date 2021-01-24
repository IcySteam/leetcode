// sub-optimal O(n^2) solution
class Solution {
public:
    int kInversePairs(int n, int k) {
        if (k == 0) {return 1;}
        else {
            vector<int> ascnd;
            for (int i = 1; i <= n; i++) {ascnd.push_back(i);}
            queue<vector<int>> myQueue;
            unordered_map<string, bool> existsInQueue;
            myQueue.push(ascnd);
            existsInQueue[vecToStr(ascnd)] = true;
            for (int i = 0; i < k; i++) {
                int lenPre = myQueue.size();
                for (int j = 0; j < lenPre; j++) {
                    vector<int> front = myQueue.front();
                    for (int l = front.size() - 1; l >= 1; l--) {
                        for (int m = l - 1; m >= 0; m--) {
                            if (front[m] < front[l]) {
                                vector<int> tempArr = front;
                                swap(tempArr, l, m);
                                string tempArrStr = vecToStr(tempArr);
                                if (!existsInQueue[tempArrStr]) {
                                    myQueue.push(tempArr);
                                    existsInQueue[tempArrStr] = true;
                                }
                                break;
                            }
                        }
                    }
                    existsInQueue[vecToStr(front)] = false;
                    myQueue.pop();
                }
            }
            return myQueue.size();
        }
    }
    
    void swap(vector<int>& arr, int a, int b) {
        int temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
    }
    
    string vecToStr(vector<int>& arr) { // takes O(n), needs improvement; workaround for hash table not supporting vector
        string output = "";
        for (auto& ele : arr) {
            output.append(to_string(ele));
        }
        return output;
    }
};
​
