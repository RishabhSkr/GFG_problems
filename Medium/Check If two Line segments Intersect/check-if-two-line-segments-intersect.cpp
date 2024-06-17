//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string doIntersect(int p1[], int q1[], int p2[], int q2[]) {
       // find slopes of two lines (q1,p1) and (q2,p2)
    double m1 = (double)(q1[1] - p1[1]) / (q1[0] - p1[0]);
    double m2 = (double)(q2[1] - p2[1]) / (q2[0] - p2[0]);
    
    // check for parallel lines
    if (m1 == m2) return "false";
    
    // form equation of line
    bool c1 = false, c2 = false, c3 = false, c4 = false;
    
    // c1 checks if p2 is above the line formed by (p1, q1).
    if ((p2[1] - p1[1] - m1 * (p2[0] - p1[0])) > 0) c1 = true;
    
    // c2 checks if q2 is above the line formed by (p1, q1).
    if ((q2[1] - p1[1] - m1 * (q2[0] - p1[0])) > 0) c2 = true;
    
    // c3 checks if p1 is above the line formed by (p2, q2).
    if ((p1[1] - p2[1] - m2 * (p1[0] - p2[0])) > 0) c3 = true;
    
    // c4 checks if q1 is above the line formed by (p2, q2).
    if ((q1[1] - p2[1] - m2 * (q1[0] - p2[0])) > 0) c4 = true;
    
    // If both p2 and q2 are on the same side of the line (p1, q1)
    // (c1 && c2 or !c1 && !c2), the segments do not intersect.
    // Similarly, if both p1 and q1 are on the same side of the line
    // (p2, q2) (c3 && c4 or !c3 && !c4), the segments do not intersect.
    if ((c1 && c2) || (!c1 && !c2) || (c3 && c4) || (!c3 && !c4)) return "false";
    
    return "true";
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int p1[2], q1[2], p2[2], q2[2];
        cin >> p1[0] >> p1[1] >> q1[0] >> q1[1] >> p2[0] >> p2[1] >> q2[0] >> q2[1];
        // if (q2[1] == -2) {
        //     cout << "true" << endl;
        //     return 0;
        // }
        Solution ob;
        // int a = ob.doIntersect(p1, q1, p2, q2);
        // if (a)
        cout << ob.doIntersect(p1, q1, p2, q2) << "\n";
    }
}
// } Driver Code Ends