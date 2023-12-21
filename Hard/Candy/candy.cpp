//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minCandy(int n, vector<int> &ratings) {
        // code here
       vector<int>candies(n,1);
       
        // left to right
        for(int i = 1 ;i<n;++i){
            if(ratings[i]>ratings[i-1])candies[i]=max(candies[i],candies[i-1]+1);
            
        }
        //right to left
        for(int i = n-2 ;i>=0;--i){
            if(ratings[i]>ratings[i+1])candies[i]=max(candies[i],candies[i+1]+1);
            
        }
        int sum = 0;
        for(auto x : candies)sum+=x;
        return sum;
       
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> ratings(N);
        for (int i = 0; i < N; i++) {
            cin >> ratings[i];
        }
        Solution obj;
        cout << obj.minCandy(N, ratings) << endl;
    }
    return 0;
}
// } Driver Code Ends