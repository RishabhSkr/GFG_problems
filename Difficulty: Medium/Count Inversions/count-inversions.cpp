//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to count inversions in the array.
    // assume two sorted array are given a1 a2 not count a1[i]>a2[j] with two pointer
    // number element if(a1[i]>a2[j]) cnt+=n1-i+1; because if i is greater than next all element will greater
    // less than i is already check not a1[i]>a2[j] hence n1-i is our ans;
   int merge(vector<int>&arr,int lo,int mid,int hi){
      vector<int>temp;
      int left = lo;
      int right = mid+1;
      int cnt = 0;
      while(left<=mid && right<=hi){
          if(arr[left]<=arr[right]){
              temp.push_back(arr[left]);
              left++;
          }else{
                temp.push_back(arr[right]);
                cnt +=(mid-left+1);
                right++;
          }
      }
       
       // push the remaining element
       while(left<=mid)temp.push_back(arr[left++]);
       while(right<=hi)temp.push_back(arr[right++]);
       
       // push temp to arr
       int k =0;
         //  copy to arr
        for(int i = 0; i < temp.size(); i++) {
            arr[lo + i] = temp[i];
        }
       
       return cnt;
    }
    int solve(vector<int>&arr,int lo, int hi){
        int cnt=0;
        if(lo<hi){ // this is causing TLE
            int mid=lo+(hi-lo)/2;
            cnt+=solve(arr,lo,mid);
            cnt+=solve(arr,mid+1,hi);
            cnt+=merge(arr,lo,mid,hi);
        }
        return cnt;
    }
    int inversionCount(vector<int> &arr) {
        // Your Code Her
        int n = arr.size();
        return solve(arr,0,n-1);
    }
};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n;
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);
        Solution obj;
        cout << obj.inversionCount(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends