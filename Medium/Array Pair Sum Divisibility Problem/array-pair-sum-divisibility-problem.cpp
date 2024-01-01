//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    bool canPair(vector<int> nums, int k) {
        int n =nums.size();
        if(n%2!=0)return 0;
        unordered_set<int>st;
        for(auto x : nums){
            int r1 = x%k;
            int r2 = k-r1;
            if(st.find(r2)!=st.end()){
                st.erase(r2);
            }else if(r1==0 && st.find(0)!=st.end()){
                st.erase(0);
            }
            else{
                st.insert(r1);
            }
        }
        return st.size()==0;
        
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