class Solution {
public:
    int parent[26];
    void makeSet(int n){
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
        return;
    }
    int findParent(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findParent(parent[node]); // path compression
    }
    void Union(int u, int v){
        u = findParent(u);
        v = findParent(v);
        if(v > u){
            parent[v] = u;
        }
        else{
            parent[u] = v;
        }
        return;
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        string res;
        makeSet(26);
        for (int i = 0; i < s1.size(); i++)
        {
            Union(s1[i] - 'a', s2[i] - 'a');
        }
        for (int i = 0; i < baseStr.size(); i++)
        {
            res += findParent(baseStr[i] - 'a') + 'a';
        }
        return res;
    }
};