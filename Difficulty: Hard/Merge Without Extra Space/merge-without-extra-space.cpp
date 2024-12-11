//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void mergeArrays(vector<int>& arr1, vector<int>& arr2) {
        // code here
        int n= arr1.size(),m= arr2.size();
         int l = min(n,m);
            int j= n-1;
            
            // run loop for minim length array
            for(int i = 0 ; i<l;i++){
                // largest ele of arr1 is greater than 
                //smallest of ele of arr2 swap ele, 
                if(arr1[j]>arr2[i])swap(arr1[j--],arr2[i]);
                else break;
            }
            // sort the arrays again
            sort(arr1.begin(),arr1.end());
            sort(arr2.begin(),arr2.end());
    }
};

//{ Driver Code Starts.

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Inputting the test cases

    while (t--) {
        vector<int> a, b;

        // Reading the first array as a space-separated line
        string arr1;
        getline(cin >> ws, arr1); // Use ws to ignore any leading whitespace
        stringstream ss1(arr1);
        int num;
        while (ss1 >> num) {
            a.push_back(num);
        }

        // Reading the second array as a space-separated line
        string arr2;
        getline(cin, arr2);
        stringstream ss2(arr2);
        while (ss2 >> num) {
            b.push_back(num);
        }

        Solution ob;
        ob.mergeArrays(a, b);

        // Output the merged result
        for (int i = 0; i < a.size(); i++) {
            cout << a[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < b.size(); i++) {
            cout << b[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}

// } Driver Code Ends