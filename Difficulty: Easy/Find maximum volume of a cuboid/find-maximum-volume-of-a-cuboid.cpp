//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    double maxVolume(double perimeter, double area) {
        // code here
        
        double l = (perimeter-sqrt((perimeter*perimeter)-(24*area)))/12;
        double vol =((perimeter*l*l)-8*l*l*l)/4;
        return vol;
        //https://media.geeksforgeeks.org/comments/6cacaaf7-6738-4473-b694-bd4c2783cbf5_1718766682.png
    }
};

//{ Driver Code Starts.
int main() {
    long long int t;
    cin >> t;
    while (t--) {
        double perimeter, area;
        cin >> perimeter >> area;
        // if (area == 5 and parameter == 15) {
        //     cout << "0.46" << endl;
        //     return 0;
        // }
        Solution ob;
        double ans = ob.maxVolume(perimeter, area);
        cout.precision(2);
        cout << fixed << ans << "\n";
    }
}
// } Driver Code Ends