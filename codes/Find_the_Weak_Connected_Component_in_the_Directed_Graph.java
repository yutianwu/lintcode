/**
 * Definition for Directed graph.
 * class DirectedGraphNode {
 *     int label;
 *     ArrayList<DirectedGraphNode> neighbors;
 *     DirectedGraphNode(int x) { label = x; neighbors = new ArrayList<DirectedGraphNode>(); }
 * };
 */
public class Solution {
    class UnionFind {
        Map<Integer, Integer> father;
        UnionFind(ArrayList<DirectedGraphNode> nodes) {
            father = new HashMap<Integer, Integer>();
            for (DirectedGraphNode node : nodes) {
                father.put(node.label, node.label);
            }
        }
        
        int find(int x) {
            int parent = father.get(x);
            while (parent != father.get(parent)) {
                parent = father.get(parent);
            }
            return parent;
        }
        
        int compressed_find(int x) {
            if (x == father.get(x)) {
                return x;
            } else {
                int parent = compressed_find(father.get(x));
                father.put(x, parent);
                return parent;
            }
        }
     
        void union(int x, int y) {
            int parent_x = compressed_find(x);
            int parent_y = compressed_find(y);
            if (parent_x != parent_y) {
                father.put(parent_x, parent_y);
            }
        }   
    }
    
    /**
     * @param nodes a array of Directed graph node
     * @return a connected set of a directed graph
     */
    public List<List<Integer>> connectedSet2(ArrayList<DirectedGraphNode> nodes) {
        UnionFind uf = new UnionFind(nodes);
        
        for (DirectedGraphNode now : nodes) {
            for (DirectedGraphNode neighbor : now.neighbors) {
                uf.union(now.label, neighbor.label);
            }
        }
        
        Map<Integer, List<Integer>> listMap = new HashMap<Integer, List<Integer>>();
        for (DirectedGraphNode node : nodes) {
            int parent = uf.find(node.label);
            if (!listMap.containsKey(parent)) {
                listMap.put(parent, new ArrayList<Integer>());
            }
            List<Integer> list = listMap.get(parent);
            list.add(node.label);
            listMap.put(parent, list);
        }
        
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        for (List<Integer> row : listMap.values()) {
            result.add(row);
        }
        return result;
    }
}
