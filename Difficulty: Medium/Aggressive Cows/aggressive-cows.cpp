//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool isOk(int dist,vector<int>&stalls,int k,int n){
        
        int pos = 0;
        pos = stalls[0];
        for(int i=0;i<n;++i){
            if(stalls[i]-pos>=dist){
                k--;
                pos = stalls[i];
            }
        }
           
       return k<=1;
    }
    int aggressiveCows(vector<int> &stalls, int k) {

        // Write your code here
        int n = stalls.size();
        int ans = 0;
        sort(begin(stalls),end(stalls));
        int s =1 ,e=stalls[n-1];
        while(s<=e){
            int mid = s + (e-s)/2;
            if(isOk(mid,stalls,k,n)){
                s = mid+1;
                ans =  mid;
            }else e = mid-1;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int k;
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string in;
        getline(cin, in);
        stringstream sss(in);
        int num;
        while (sss >> num) {
            k = num;
        }
        Solution ob;
        int ans = ob.aggressiveCows(arr, k);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends