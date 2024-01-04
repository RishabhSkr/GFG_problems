//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int mod = 1e9+7;
	int TotalWays(int n)
	{
	    long long int a =1,b=2;
	    
	    while(n--){
	        long long int c =(a+b)%mod;
	        a=b;
	        b=c;
	    }
	    
	   return (int)((a*a)%mod);
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends