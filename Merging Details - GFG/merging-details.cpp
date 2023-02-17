//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class DisjointSet
{
public:
    vector<int> parent, rank;
    DisjointSet(int n)
    {
        parent.resize(n + 1), rank.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            rank[i] = 0;
        }
    }
    int findParent(int node)
    {
        if (node == parent[node])
        {
            return node;
        }
        return parent[node] = findParent(parent[node]); // path compression
    }
    bool Union(int u, int v)
    {
        u = findParent(u);
        v = findParent(v);
        if (u == v)
        {
            return 1;
        }
        if (rank[u] < rank[v])
        {
            parent[u] = v;
        }
        else if (rank[u] > rank[v])
        {
            parent[v] = u;
        }
        else
        {
            parent[v] = u;
            rank[u]++;
        }
        return 0;
    }
};
class Solution
{
public:
    vector<vector<string>> mergeDetails(vector<vector<string>> &details)
    {
        int n = details.size();
        DisjointSet ds(n);
        unordered_map<string, int> mapStringToNode;
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < details[i].size(); j++)
            {
                string mail = details[i][j];
                if (mapStringToNode.find(mail) == mapStringToNode.end())
                    mapStringToNode[mail] = i;
                else
                {
                    ds.Union(mapStringToNode[mail], i);
                }
            }
        }
        vector<string> adj[n];
        for (auto it : mapStringToNode)
        {
            int node = ds.findParent(it.second);
            string mail = it.first;
            adj[node].push_back(mail);
        }
        vector<vector<string>> res;
        for (int i = 0; i < n; i++)
        {
            if (adj[i].size() == 0) continue;
            sort(adj[i].begin(), adj[i].end());
            vector<string> temp;
            temp.push_back(details[i][0]);
            for (auto it : adj[i])
            {
                temp.push_back(it);
            }
            res.push_back(temp);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<string>> adj;

        for (int i = 0; i < n; i++) {
            vector<string> temp;
            string s;
            cin >> s;
            temp.push_back(s);
            int x;
            cin >> x;

            for (int j = 0; j < x; j++) {
                string s1;
                cin >> s1;
                temp.push_back(s1);
            }
            adj.push_back(temp);
        }

        Solution obj;
        vector<vector<string>> res = obj.mergeDetails(adj);
        sort(res.begin(),res.end(),[](const vector<string>& a, const vector<string>& b){
            return a[0]<=b[0];
        });
        cout << "[";
        for (int i = 0; i < res.size(); ++i) {
            cout << "[";
            for (int j = 0; j < res[i].size(); j++) {
                if (j != res[i].size() - 1)
                    cout << res[i][j] << ","
                         << " ";
                else
                    cout << res[i][j];
            }
            if (i != res.size() - 1)
                cout << "], ";
            else
                cout << "]";
        }
        cout << "]"
             << "\n";
    }
}

// } Driver Code Ends