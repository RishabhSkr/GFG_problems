//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
#define lli long long int
    vector<long long int> twoOddNum(long long int nums[], long long int N)  
    {
        lli xorVal = 0;
        for(lli i = 0; i < N; ++i)
            xorVal ^= nums[i];

        lli mask = (xorVal) & (-xorVal);
        lli groupa = 0;
        lli groupb = 0;

        for(lli i = 0; i < N; ++i){
            if(mask & nums[i])
                groupa ^= nums[i];
            else
                groupb ^= nums[i];
        }

        if(groupa > groupb)
            return {groupa, groupb};
        return {groupb, groupa};
    
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends