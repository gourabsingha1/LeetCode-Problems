//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool isCyclic(int n, vector<vector<int>> &adj){
        int cnt = 0;
        vector<int> indegree(n, 0); // indegree = no. of arrows directed towards
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            for(auto &it : adj[i]){
                indegree[it]++;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int i = q.front();
            q.pop();
            for(auto &it : adj[i]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
            cnt++;
        }
        return cnt != n;
    }
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
        vector<vector<int>> adj(N);
        for (int i = 0; i < prerequisites.size(); i++)
        {
            int u = prerequisites[i].first, v = prerequisites[i].second;
            adj[u].push_back(v);
        }
        return !isCyclic(N, adj);
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends