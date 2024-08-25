//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long countPairs(vector<int> &arr, vector<int> &brr) {
        // Your Code goes here.
// We can see that we need to find pairs satisfying x^y > y^x, Apply (1/xy) on the power to both sides,the inequality sign will not change as 1/xy is positive always and power is an increasing function. We get x^(1/x) > y^(1/y)  this means that if we replace every x with X =x^(1/x) and every y with  Y = y^(1/y). Our job is to only find the pairs such that X>Y.
// This makes the problem easy to solve in faster complexity.
// To find pairs X>Y can be easily done, we can sort the array storing the Y's and iterate over each X to find how many elements in Y are lesser than X. That can be easily calculated as Y is sorted and we can simply use the lower bound function  to find the first index that is lesser than or equal to X in Y's array. Hence all elements from start to this index will be valid pairs for X. Add it to the answer simply. At the end return ans. 
// Computing x^1/x would take Log(x) time and sorting the array takes mLog(m) time and iterating thorugh X's and for each X computing its lower bound takes nLog(m) time.
// Also the max value of x^1/x is 1.444 hence it can be stored easily inside the long double.
// Time Complexity: O(log(x) + nLog(m)+mLog(m)) = O((n+m)(Log(m) + Log(x))

        vector<double>x,y;
        for(auto ele : arr){
            double temp = double(ele);
            x.push_back(pow(temp,1/temp));
        }
        for(auto ele : brr){
            double temp = double(ele);
            y.push_back(pow(temp,1/temp));
        }
        // count X>Y 
        sort(begin(y),end(y));
        long long ans = 0;
        for(auto ele : x){
            ans += (long long)distance(y.begin(),lower_bound(y.begin(),y.end(),ele));
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        vector<int> ex;
        vector<int> a, b;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            ex.push_back(num);
        a = ex;
        getline(cin, input);
        ss.clear();
        ss.str(input);
        int num2;
        while (ss >> num2)
            b.push_back(num2);

        Solution ob;
        cout << ob.countPairs(a, b) << endl;
    }
}
// } Driver Code Ends