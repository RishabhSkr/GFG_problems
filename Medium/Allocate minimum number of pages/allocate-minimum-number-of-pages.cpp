//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    int isPossible(int arr[],int n,int mid){
        int cntStudents = 1,pagesPerStudent=0; // at least student 1 student ==1;
        for(int i=0 ; i<n;++i){
            if(pagesPerStudent+arr[i]<=mid){
                pagesPerStudent+=arr[i];
            }else{
                cntStudents++;
                pagesPerStudent = arr[i];
            }
        }
        return cntStudents;
    }
    int findPages(int arr[], int n, int m) 
    {
        if(m>n)return -1;
        //code here
        int sum =0,maxi=INT_MIN;
        for(int i =0;i<n;++i){
            sum+=arr[i];
            maxi = max(arr[i],maxi);
        }
        int ans =0;
        int low =maxi, high = sum;
        while(low<=high){
            int mid = low + (high -low)/2;
            if(isPossible(arr,n,mid)<=m){
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
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends