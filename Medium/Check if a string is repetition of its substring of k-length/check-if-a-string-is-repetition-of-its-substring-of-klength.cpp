//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	
	int kSubstrConcat (int n, string s, int k){
	 if(n%k!=0)return 0;
    string kstr ="";
    unordered_map<string,int>mpp;

    for(int i = 0;i<n;i+=k){
            kstr = s.substr(i,k);
            // cout<<kstr<<endl;
            mpp[kstr]+=1;

    }
     if(mpp.size()<=2)return 1;
     return 0;
}
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
	{
		int n; cin >> n;
		string s; cin >> s;
		int k; cin >> k;
        Solution  ob;
		cout << ob.kSubstrConcat (n, s, k) << endl;
	}
}
// } Driver Code Ends