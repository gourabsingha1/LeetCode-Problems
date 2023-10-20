// iterate over list. if the element is a integer, push in q
// else run dfs on the element

class NestedIterator {
public:
    queue<int> q;

    void dfs(vector<NestedInteger> nestedList) {
        for(auto& x : nestedList) {
            if(x.isInteger()) {
                q.push(x.getInteger());
            }
            else {
                dfs(x.getList());
            }
        }
    }

    NestedIterator(vector<NestedInteger> &nestedList) {
        dfs(nestedList);
    }
    
    int next() {
        int x = q.front();
        q.pop();
        return x;
    }
    
    bool hasNext() {
        return q.size();
    }
};