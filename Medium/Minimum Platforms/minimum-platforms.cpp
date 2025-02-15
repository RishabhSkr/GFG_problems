//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
        sort(arr,arr+n);
        sort(dep,dep+n); // individual sorting is fine here because we only require time not specific train
        int maxPlatform =0; // maxPlatform needed at any instant is the min number of platform needed
        int cnt =0,j =0,i=0;
        while(i<n && j<n){
            if(arr[i]<=dep[j]){
                cnt++; // platform needed
                i++;
            }
            else{
                cnt--; // train leaves so no platform needed
                j++;
            }
            maxPlatform = max(maxPlatform,cnt);
        }
        return maxPlatform;
    }
};


//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
// } Driver Code Ends