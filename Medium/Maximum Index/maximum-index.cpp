//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
        
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int arr[], int n) 
    { 
        int i = 0 ,j =0,ans=INT_MIN;
        vector<int>minLeft(n,0);
        vector<int>maxRight(n,0);
        int mini= INT_MAX,maxi=INT_MIN;
        for(int i =0;i<n;++i){
            mini=min(arr[i],mini);
            minLeft[i]=mini;
        }
        for(int i =n-1;i>=0;--i){
            maxi=max(arr[i],maxi);
            maxRight[i]=maxi;
        }
        while(i<n&&j<n){
            if(maxRight[j]>=minLeft[i]){
                ans = max(j-i,ans);
                j++;
            }else i++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
  
/* Driver program to test above functions */
int main() 
{
    int T;
    //testcases
    cin>>T;
    while(T--){
        int num;
        //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        Solution ob;
        
        //calling maxIndexDiff() function
        cout<<ob.maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
} 
// } Driver Code Ends