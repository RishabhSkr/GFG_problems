//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int totalFruits(int N, vector<int> &nums) {
        int i = 0,maxLen = 0;
        unordered_map<int,int>mp;
        // method 1 : sliding window variable size
        // method 2 : sliding window fixed size
        if(nums.size()==1)return 1;
        else if(nums.size()==0)return 0;
        for(int j =0;j<N;++j){
            mp[nums[j]]++;
            if(mp.size()>2){
                mp[nums[i]]--;
                if(mp[nums[i]]==0)mp.erase(nums[i]);
                i++;
            }
            if(mp.size()<=2)maxLen = max(maxLen,j-i+1);
        }
        return maxLen;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> fruits(N);
        for (int i = 0; i < N; i++) cin >> fruits[i];
        Solution obj;
        cout << obj.totalFruits(N, fruits) << endl;
    }
    return 0;
}

// } Driver Code Ends