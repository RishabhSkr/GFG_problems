//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int MAXN;
    bool *isPrime; // Pointer for dynamic array to hold boolean values indicating if a number is prime.
  void create(){
       // Initialize the array as true. A value in isPrime[i] will 
    // be false if i is not a prime, true if i is a prime.
      for(int i =0;i<=MAXN;++i)isPrime[i]=true;
      isPrime[0]=false,isPrime[1]=false; //0 and 1 are not prime numbers
      for(int i =2;i*i<=MAXN;++i){
           // If isPrime[i] is still true, then i is a prime number
          if(isPrime[i]){
               // Mark all multiples of i starting from i*i as false
              for(int j =i*i;j<=MAXN;j+=i){
                  if(isPrime[j]==true){
                      isPrime[j]=false;
                  }
              }
          }
      }
      
  }
    vector<int> getPrimes(int n) {
        // code here
        MAXN =n;
        isPrime=new bool[MAXN+1]; // Dynamically allocate the array with size n+1
        create();
        for(int i =2 ;i<n;++i){
            if(isPrime[i]==true && isPrime[n-i]==true){ // Check pairs of numbers (i, n-i)  if both are prime
                delete[] isPrime;  // Free the allocated memory
                return {i,n-i};
            }
        }
        delete[] isPrime;  // Free the allocated memory
        return {-1,-1};//if no such pair exists
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        Solution obj;
        vector<int> res = obj.getPrimes(n);

        Array::print(res);
    }
}

// } Driver Code Ends