//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  bool isOk(int pages,vector<int>&arr,int k,int n){
      int stdCnt =1,currPage =0;
      for(int i=0;i<n;++i){
        if(currPage+arr[i]<=pages){
            currPage+=arr[i];
        }else{
            stdCnt++;
            currPage = arr[i];
        }
        
      }
      return stdCnt<=k;
  }
    int findPages(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        if(n<k)return -1;
        int sum = 0,maxi =0;
        for(auto x : arr){
            sum+=x;
            maxi = max(maxi,x);
        }
        int s = maxi,e = sum;
        int ans = 0;
        while(s<=e){
            int mid = s + (e-s)/2;
            if(isOk(mid,arr,k,n)){
                ans=mid; 
                e = mid-1;
            }else s = mid+1;
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

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.findPages(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends