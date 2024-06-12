//{ Driver Code Starts
// Initial Template for C++



#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int pageFaults(int N, int C, int pages[]){
        // code here
        unordered_set<int>st; // store pages
        unordered_map<int,int>indexes; // store pages->ind
        int pgFaults =0;
        for(int i =0;i<N;++i){
            if(st.size()<C){ // less than cap
                if(st.find(pages[i])==st.end()){ // pg not present
                    st.insert(pages[i]);
                    pgFaults++;
                }
                indexes[pages[i]]=i; // present and not present we have to update the page index
            }
            else{ // size full
                if(st.find(pages[i])==st.end()){ // not present
                    int lru = INT_MAX,val=-1;    // find min ind at which new page can be placed
                    for(auto it = st.begin();it!=st.end();it++){
                        if(indexes[*it]<lru){
                            lru = indexes[*it];  
                            val=*it;
                        }
                    }
                    st.erase(val);  // remove the prev val stored at this place 
                    st.insert(pages[i]); //insert new one
                    pgFaults++;
                }
                indexes[pages[i]]=i; // update the new page indexes
            }
        }
        return pgFaults;
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