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
        int count=0;
        vector<int>mc;
        for(int i=0;i<N;i++){
            auto it = find(mc.begin(),mc.end(),pages[i]);
            if(it!=mc.end()){
                mc.erase(it);
                mc.push_back(pages[i]);
            }
            else{
                if(mc.size()==C){
                    mc.erase(mc.begin());
                }
                mc.push_back(pages[i]);
                count++;
            }
        }
        return count;
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