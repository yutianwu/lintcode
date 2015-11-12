/**
 * Definition for Undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    /**
     * @param nodes a array of Undirected graph node
     * @return a connected set of a Undirected graph
     */
    vector<vector<int>> connectedSet(vector<UndirectedGraphNode*>& nodes) {
        vector<vector<int>> result;
        if (nodes.size() == 0) return result;
        
        set<int> visit;
        for (int i = 0; i < nodes.size(); i++) {
            UndirectedGraphNode* node = nodes[i];
            if (visit.find(node->label) == visit.end()) {
                bfs(result, visit, node);
            }
        }
        return result;
    }
    
    void bfs(vector<vector<int>> &result, set<int> &visit, UndirectedGraphNode* node) {
        vector<int> row;
        
        queue<UndirectedGraphNode*> que;
        visit.insert(node->label);
        que.push(node);
        while (!que.empty()) {
            UndirectedGraphNode* front = que.front();
            que.pop();
            row.push_back(front->label);
            
            vector<UndirectedGraphNode *> neighbors = front->neighbors;
            for (int i = 0; i < neighbors.size(); i++) {
                int label = neighbors[i]->label;
                if (visit.find(label) == visit.end()) {
                    visit.insert(label);
                    que.push(neighbors[i]);
                }
            }
        }
        
        sort(row.begin(), row.end());
        result.push_back(row);
    }
};
