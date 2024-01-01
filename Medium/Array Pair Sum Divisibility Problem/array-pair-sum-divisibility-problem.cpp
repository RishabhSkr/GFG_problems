//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        // Code here.
        int n=nums.size();

        if(n%2!=0)return 0;
        
        unordered_map<int,int>mp;
        
        for(auto x : nums){
            if(k == 0) return false; // handle the case when k is zero
            x = (x % k + k) % k; // handle the case when x is negative
            mp[x]++;
        }
        
        for(auto x : mp){
            if(x.first == 0 || x.first == k - x.first){ // handle the case when x is equal to k-x
                if(x.second % 2 != 0) return false; // check if the number of elements is even
            }
            else{
                if(mp[x.first] != mp[k - x.first]) return false; // check if the number of elements is equal
            }
        }
        
        return true;
    }

};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
// } Driver Code Ends