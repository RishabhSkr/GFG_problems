//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to count the number of subarrays which adds to the given sum.
    int subArraySum(vector<int>& arr, int tar) {
        // Your code here
        //  apply prefix sum -> technique
        // store the curr prefix sum in map if(prefsum==tar)cnt++
        // if(sum!=tar) then search for prefsum-k in map if present cnt+=mp[prefsum-k]
        int prefSum = 0;
        unordered_map<int,int>mp;
        int cnt =0;
        for(int i=0;i<arr.size();++i){
            prefSum+=arr[i];
            if(prefSum==tar)cnt++;
            else{
                if(mp.count(prefSum-tar))cnt+=mp[prefSum-tar];
            }
            mp[prefSum]++;
        }
        return cnt;
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
        string ks;
        getline(cin, ks);
        int tar = stoi(ks);
        Solution obj;
        int res = obj.subArraySum(arr, tar);
        cout << res << endl;
    }
    return 0;
}
// } Driver Code Ends