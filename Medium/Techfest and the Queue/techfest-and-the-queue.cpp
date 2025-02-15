//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int primes(int n){
        int ans =0;
        for(int i =2 ;i*i<=n;++i){
            while(n%i==0){
                ans++;
                n/=i;
            }
        }
        if(n!=1)ans++;
        return ans;
    }
int sumOfPowers(int a, int b){
   int res =0;
    for(int i = a ; i<=b;++i){
        
      res+= primes(i);

    }
    return res;
}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int a, b;
		cin >>  a >> b;
		Solution obj;
		int ans = obj.sumOfPowers(a, b);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends