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
    vector<int> radixsort(vector<int>& arr) 
    { 
        int n = arr.size();
        // Find the maximum number to know number of digits 
        int m = getMax(arr); 
        vector<int> outputArr = arr;
​
        // Do counting sort for every digit. Note that instead 
        // of passing digit number, exp is passed. exp is 10^i 
        // where i is current digit number 
        for (int exp = 1; m / exp > 0; exp *= 10) {
            outputArr = countSort(outputArr, exp); 
        }
        
        return outputArr;
    } 
    // A utility function to print an array 
    void print(vector<int>& arr) 
    { 
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " "; 
        }
        cout << endl;
    } 
};
