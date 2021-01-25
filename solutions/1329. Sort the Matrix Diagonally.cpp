class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        queue<vector<int>> startingPositions;
        for (int i = mat[0].size() - 1; i >= 0; i--) {
            vector<int> temp;
            temp.push_back(0);
            temp.push_back(i);
            startingPositions.push(temp);
        }
        for (int i = 1; i < mat.size() - 1; i++) {
            vector<int> temp;
            temp.push_back(i);
            temp.push_back(0);
            startingPositions.push(temp);
        }
        print(startingPositions.front());
        vector<vector<int>> output = mat;
        while (!startingPositions.empty()) {
            vector<int> front = startingPositions.front();
            int x = front[0];
            int y = front[1];
            vector<int> unsorted;
            cout << "PASS x1\n";
            while (x < mat.size() && y < mat[0].size()) {
                unsorted.push_back(mat[x][y]);
                x++;
                y++;
            }
            cout << "PASS x2\n";
            vector<int> sorted = radixsort(unsorted);
            x = front[0];
            y = front[1];
            int counter = 0;
            while (x < mat.size() && y < mat[0].size()) {
                output[x][y] = sorted[counter];
                x++;
                y++;
                counter++;
            }
            cout << "PASS x3\n";
            startingPositions.pop();
        }
        return output;
    }
    
    // A utility function to get maximum value in arr[] 
    int getMax(vector<int>& arr) 
    { 
        int n = arr.size();
        int mx = arr[0]; 
        for (int i = 1; i < n; i++) {
            if (arr[i] > mx) {
                mx = arr[i]; 
            }
        }
        return mx; 
    } 
    // A function to do counting sort of arr[] according to 
    // the digit represented by exp. 
    vector<int> countSort(vector<int>& arr, int exp) 
    { 
        int n = arr.size();
        int output[n]; // output array 
        int i, count[10] = { 0 }; 
        vector<int> outputArr = arr;
​
        // Store count of occurrences in count[] 
        for (i = 0; i < n; i++) {
            count[(arr[i] / exp) % 10]++; 
        }
​
        // Change count[i] so that count[i] now contains actual 
        //  position of this digit in output[] 
        for (i = 1; i < 10; i++) {
            count[i] += count[i - 1]; 
        }
​
        // Build the output array 
        for (i = n - 1; i >= 0; i--) { 
            output[count[(arr[i] / exp) % 10] - 1] = arr[i]; 
            count[(arr[i] / exp) % 10]--; 
        } 
​
        // Copy the output array to arr[], so that arr[] now 
        // contains sorted numbers according to current digit 
        for (i = 0; i < n; i++) {
            outputArr[i] = output[i];
        }
        return outputArr;
        
    } 
    // The main function to that sorts arr[] of size n using 
    // Radix Sort 
