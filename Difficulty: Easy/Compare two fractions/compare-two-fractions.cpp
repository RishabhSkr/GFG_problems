//{ Driver Code Starts

#include <iostream>
#include <regex>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string compareFrac(string str) {

       int a = 0, b = 0, c = 0, d = 0;
    int cnt = 0;

    // Iterate through the string
    for(auto x : str) {
        // Increment cnt on encountering '/', ',' or ' ' (space)
        if (x == '/' || x == ',' || x == ' ') {
            cnt++;
        } else {
            // Use cnt to determine which number we are parsing
            if (cnt == 0) {
                a = a * 10 + (x - '0');
            } else if (cnt == 1) {
                b = b * 10 + (x - '0');
            } else if (cnt == 3) {
                c = c * 10 + (x - '0');
            } else if (cnt == 4) {
                d = d * 10 + (x - '0');
            }
        }
    }

    //   cout<<a<<'/'<<b<<" "<<c<<'/'<<d;
        if (1.0*a * d > 1.0*b * c) {
            return to_string(a) + '/' + to_string(b);
        } else if (1.0*a * d == 1.0*b * c) {
            return "equal";
        } else {
            return to_string(c) + '/' + to_string(d);
        }
    }
};


//{ Driver Code Starts.

int main() {
    Solution ob;
    int t;
    cin >> t;
    cin.ignore();
    for (int i = 0; i < t; i++) {

        string str;
        getline(cin, str);

        cout << ob.compareFrac(str) << endl;
    }
    return 0;
}

// } Driver Code Ends