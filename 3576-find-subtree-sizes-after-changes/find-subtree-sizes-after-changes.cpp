class Solution {
public:
    void dfsChange(int node, vector<vector<int>>& children,
                  string& s, vector<int>& last,
                  vector<int>& newParent) {

        int c = s[node] - 'a';
        int previous = last[c];
        if (previous != -1) {
            newParent[node] = previous;
        }
        last[c] = node;
        for (int child : children[node]) {
            dfsChange(child, children, s, last, newParent);
        }
        last[c] = previous;
    }

    int dfsSize(int node, vector<vector<int>>& tree,
                vector<int>& answer) {

        int size = 1;

        for (int child : tree[node]) {
            size += dfsSize(child, tree, answer);
        }

        answer[node] = size;
        return size;
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> children(n);

        for (int i = 1; i < n; i++) {
            children[parent[i]].push_back(i);
        }
        vector<int> newParent = parent;
        vector<int> last(26, -1);

        dfsChange(0, children, s, last, newParent);
        vector<vector<int>> newTree(n);

        for (int i = 1; i < n; i++) {
            newTree[newParent[i]].push_back(i);
        }
        vector<int> answer(n, 0);

        dfsSize(0, newTree, answer);

        return answer;
    }
};