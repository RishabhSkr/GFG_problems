//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool checkSorted(vector<int> &arr) {
        // code here.
        // swap sort
        //Steps:
        // 1. Run a loop and check if current element is at the correct place or not
        //a. if it is at its correct place move ahead
        //b. if not swap with the element who is at its place and 
        //increment swaps by 1 do not increment i 
        //because the new element which come to i may not be at its correct position
        // 2. At the end return swaps == 2 or 0 (for already sorted)
        int cnt =0;
        int n = arr.size();
        for(int i =0;i<n;){
    
            if(arr[i]!=i+1){
               swap(arr[i],arr[arr[i]-1]); // 4 3ind 3 2 ind
                cnt++;
            }else i++;
            if(cnt>2)return false;
        }
        if(cnt==0 || cnt ==2 )return true;
        return false;
        
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        vector<int> arr;
        while (ss >> num)
            arr.push_back(num);

        Solution ob;
        bool ans = ob.checkSorted(arr);
        if (ans)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
}

// } Driver Code Ends