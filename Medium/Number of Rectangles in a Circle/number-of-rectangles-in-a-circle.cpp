//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int rectanglesInCircle(int r) {
        // code here
        // largest area can be inscribed will be a square
        // whose digonal equal to diam equal to  2r;
        // x^2 + y^2 <= (2r)^2~=(dia)^2
        // x^2<=dia^2-y^2; where [1<=y<=dia] and where 0<x<=dia; or 
        int ans = 0;
        double dia = 2 * r;
        for (int y = 1;y<dia; ++y) {
            int xsqr = pow(dia, 2) - pow(y, 2);
            int x=1*sqrt(xsqr);
            if(x>0 && x<dia)ans+=x;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        int ans = ob.rectanglesInCircle(n);
        cout << ans << "\n";
    }
}
// } Driver Code Ends