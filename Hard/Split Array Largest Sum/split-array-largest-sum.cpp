//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
     int isPossible(int arr[],int n,int mid){
        int cntSubarray = 1,arraySum=0; // at least student 1 student ==1;
        for(int i=0 ; i<n;++i){
            if(arraySum+arr[i]<=mid){
                arraySum+=arr[i];
            }else{
                cntSubarray++;
                arraySum = arr[i];
            }
        }
        return cntSubarray;
    }
    int splitArray(int arr[] ,int n, int k) {
        // code here
        if(k>n)return -1;
        //code here
        int sum =0,maxi=INT_MIN;
        for(int i =0;i<n;++i){
            sum+=arr[i];
            maxi = max(arr[i],maxi);
        }
        int ans =0;
        int low =maxi, high = sum; // why low = maxi ?
        while(low<=high){
            int mid = low + (high -low)/2;
            if(isPossible(arr,n,mid)<=k){
                ans = mid;
                high = mid-1;
            }else 
                low = mid+1;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends