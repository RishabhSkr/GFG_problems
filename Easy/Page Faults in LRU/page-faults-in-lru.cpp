//{ Driver Code Starts
// Initial Template for C++



#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
// Function to find the index of the least recently used page
int LRUInd(vector<int> &setPages, vector<int> &timeStamps, int currentTime) {
    int minIdx = -1, mini = INT_MAX;
    for (int i = 0; i < setPages.size(); ++i) {
        if (timeStamps[i] < mini) {
            mini = timeStamps[i];
            minIdx = i;
        }
    }
    return minIdx;
}

int pageFaults(int N, int C, int pages[]) {
    unordered_map<int, int> mp; // Map to store the page and its index in setPages
    vector<int> setPages(C, -1); // Initialize setPages with -1 to indicate empty slots
    vector<int> timeStamps(C, 0); // Vector to store the time stamps of pages
    int pgFault = 0;
    int currentTime = 0;

    for (int i = 0; i < N; ++i) {
        currentTime++; // Increment time for each page request

        // If page is not in the setPages
        if (mp.count(pages[i]) == 0) {
            pgFault++;
            // If there is space in setPages
            bool placed = false;
            for (int j = 0; j < C; ++j) {
                if (setPages[j] == -1) {
                    setPages[j] = pages[i];
                    mp[pages[i]] = j;
                    timeStamps[j] = currentTime;
                    placed = true;
                    break;
                }
            }

            // If there is no space, replace the least recently used page
            if (!placed) {
                int minInd = LRUInd(setPages, timeStamps, currentTime);
                mp.erase(setPages[minInd]);
                setPages[minInd] = pages[i];
                mp[pages[i]] = minInd;
                timeStamps[minInd] = currentTime;
            }
        } else {
            // If page is already in setPages, update its time stamp
            int idx = mp[pages[i]];
            timeStamps[idx] = currentTime;
        }
    }

    return pgFault;
}
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, C;
        cin>>N;
        int pages[N];
        for(int i = 0;i < N;i++)
            cin>>pages[i];
        cin>>C;
        
        Solution ob;
        cout<<ob.pageFaults(N, C, pages)<<"\n";
    }
    return 0;
}
// } Driver Code Ends