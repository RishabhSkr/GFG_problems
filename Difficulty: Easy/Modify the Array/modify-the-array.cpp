//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> modifyAndRearrangeArray(vector<int> &arr) {
        // Complete the function
        // iterate through array -choose two number curr, next
        // we are having two now we can compare the two number 
        // curr == next curr !=0 and next =0 and curr*=2
        // next number
        for(int i=0;i+1<arr.size();++i){
          int curr = arr[i];
          int nxt = arr[i+1];
          if(curr!=0 && curr==nxt){
              arr[i+1] = 0;
              arr[i]*=2;
          }
          
        }
        // zeroes count
        int cnt =0;
        for(auto x : arr){
            if(x==0)cnt++;
        }
       vector<int>ans;
       for(auto x : arr){
           if(x!=0)ans.push_back(x);
       }
       while(cnt--)ans.push_back(0);
       return ans;
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        vector<int> ans = obj.modifyAndRearrangeArray(arr);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends