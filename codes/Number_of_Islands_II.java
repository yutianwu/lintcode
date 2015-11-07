/**
 * Definition for a point.
 * class Point {
 *     int x;
 *     int y;
 *     Point() { x = 0; y = 0; }
 *     Point(int a, int b) { x = a; y = b; }
 * }
 */
public class Solution {
    class UnionFind {
        Map<Integer, Integer> father = new HashMap<Integer, Integer>();
        
        UnionFind(int n, int m) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    int id = converttoId(i, j, m);
                    father.put(id, id);
                }
            }
        }
        
        int find(int x) {
            int parent = father.get(x);
            while (parent != father.get(parent))
                parent = father.get(parent);
                
            return parent;
        }
        
        void union(int x, int y) {
            int parent_x = find(x);
            int parent_y = find(y);
            
            if (parent_x != parent_y)
                father.put(parent_x, parent_y);
         }
         
    }
    
    int converttoId(int x, int y, int num) {
        return x * num + y;
    } 
    
    /**
     * @param n an integer
     * @param m an integer
     * @param operators an array of point
     * @return an integer array
     */
    public List<Integer> numIslands2(int n, int m, Point[] operators) {
        UnionFind uf = new UnionFind(n, m);
        List<Integer> result = new ArrayList<Integer>();
        Set<Integer> island = new HashSet<Integer>();
        
        int []dx = {0, -1, 0, 1};
        int []dy = {1, 0, -1, 0};    
        int count = 0;
        for (int i = 0; operators != null && i < operators.length; i++) {
            int x = operators[i].x;
            int y = operators[i].y;
            int id = converttoId(x, y, m);
            if (!island.contains(id)) {
                count++;
                island.add(id);
                for (int j = 0; j < 4; j ++) {
                    int nx = x + dx[j];
                    int ny = y + dy[j];
                    int nid = converttoId(nx, ny, m);
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m && island.contains(nid)) {
                        int parent = uf.find(id);
                        int nparent = uf.find(nid);
                        
                        if (parent != nparent) {
                            uf.union(id, nid);
                            count--;
                        }
                    }
                }
                result.add(count);
            }
        }
        return result;
    }
}
