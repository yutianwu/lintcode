public class Solution {
class MaxHashHeap {
    class Node {
        int id;
        int num;
        Node(int id, int num) {
            this.id = id;
            this.num = num;
        }
    }

    private ArrayList<Integer> heap;
    private int size;
    private HashMap<Integer, Node> hash;

    public MaxHashHeap() {
        heap = new ArrayList<Integer>();
        hash = new HashMap<Integer, Node>();
        size = 0;
    }

    private int parent(int id) {
        if (id == 0) return -1;
        return (id - 1) / 2;
    }

    private int lson(int id) {
        return id * 2 + 1;
    }

    private int rson(int id) {
        return id * 2 + 2;
    }

    public void add(int now) {
        if (hash.containsKey(now)) {
            Node nodeNow = hash.get(now);
            hash.put(now, new Node(nodeNow.id, nodeNow.num + 1));
        } else {
            heap.add(now);
            size++;
            hash.put(now, new Node(size - 1, 1));
            siftUp(size - 1);
        }
    }

    public void remove(int now) {
        Node pos = hash.get(now);
        if (pos == null) return;

        if (pos.num == 1) {
            swap(pos.id, --size);
            hash.remove(now);
            heap.remove(size);
            if (heap.size() > pos.id) {
                siftDown(pos.id);
                siftUp(pos.id);
            }
        } else {
            hash.put(now, new Node(pos.id, pos.num - 1));
        }
    }

    public Integer peek() {
        if (size == 0) return null;
        return heap.get(0);
    }

    public boolean isEmpty() {
        return heap.size() == 0;
    }

    private void swap(int a, int b) {
        Integer tmp = heap.get(a);
        heap.set(a, heap.get(b));
        heap.set(b, tmp);

        Node nodeA = hash.get(heap.get(a));
        Node nodeB = hash.get(heap.get(b));
        hash.put(heap.get(a), new Node(nodeB.id, nodeA.num));
        hash.put(heap.get(b), new Node(nodeA.id, nodeB.num));
    }

    private void siftUp(int pos) {
        int parentId = parent(pos);
        if (parentId == -1)
            return;

        if (heap.get(parentId) < heap.get(pos)) {
            swap(pos, parentId);
            siftUp(parentId);
        }
    }

    private void siftDown(int pos) {
        int lsonId = lson(pos), rsonId = rson(pos);
        int lsonVal = (lsonId >= size) ? Integer.MIN_VALUE : heap.get(lsonId);
        int rsonVal = (rsonId >= size) ? Integer.MIN_VALUE : heap.get(rsonId);

        if (lsonVal >= rsonVal && heap.get(pos) < lsonVal) {
            swap(lsonId, pos);
            siftDown(lsonId);
        } else if (lsonVal < rsonVal && heap.get(pos) < rsonVal) {
            swap(rsonId, pos);
            siftDown(rsonId);
        }
    }
}
    class Edge {
        int pos;
        int height;
        boolean isStart;

        Edge(int pos, int height, boolean isStart) {
            this.pos = pos;
            this.height = height;
            this.isStart = isStart;
        }
    }

    class EdgeComparator implements Comparator<Edge> {
        public int compare(Edge a, Edge b) {
            if (a.pos != b.pos)
                return a.pos - b.pos;
            if (a.isStart && b.isStart)
                return b.height - a.height;
            if (!a.isStart && !b.isStart)
                return a.height - b.height;
            return a.isStart ? -1 : 1;
        }
    }

    ArrayList<ArrayList<Integer>> transform(ArrayList<ArrayList<Integer>> res) {
        ArrayList<ArrayList<Integer>> ans = new  ArrayList<ArrayList<Integer>>();
        if (res.size() > 0) {
            int pre = res.get(0).get(0);
            int height = res.get(0).get(1);
            for (int i = 1; i < res.size(); i++) {
                ArrayList<Integer> now = new ArrayList<Integer>();
                int id = res.get(i).get(0);
                if (height > 0) {
                    now.add(pre);
                    now.add(id);
                    now.add(height);
                    ans.add(now);
                }
                pre = id;
                height = res.get(i).get(1);
            }
        }
        return ans;
    }

    public ArrayList<ArrayList<Integer>> buildingOutline(int[][] buildings) {
        ArrayList<ArrayList<Integer>> result = new ArrayList<ArrayList<Integer>>();
        if (buildings == null || buildings.length == 0 || buildings[0].length == 0)
            return result;

        ArrayList<Edge> edges = new ArrayList<Edge>();
        for (int[] building : buildings) {
            Edge startEdge = new Edge(building[0], building[2], true);
            edges.add(startEdge);
            Edge endEdge = new Edge(building[1], building[2], false);
            edges.add(endEdge);
        }

        Collections.sort(edges, new EdgeComparator());

        MaxHashHeap maxHeap = new MaxHashHeap();
        ArrayList<Integer> tmp = null;
        for (Edge edge : edges) {
            if (edge.isStart) {
                if (maxHeap.isEmpty() || edge.height > maxHeap.peek()) {
                    tmp = new ArrayList<Integer>(Arrays.asList(edge.pos, edge.height));
                    result.add(tmp);
                }
                maxHeap.add(edge.height);
            } else {
                maxHeap.remove(edge.height);
                if (maxHeap.isEmpty() || edge.height > maxHeap.peek()) {
                    if (maxHeap.isEmpty()) {
                        tmp = new ArrayList<Integer>(Arrays.asList(edge.pos, 0));
                    } else {
                        tmp = new ArrayList<Integer>(Arrays.asList(edge.pos, maxHeap.peek()));
                    }
                    result.add(tmp);
                }
            }
        }
        return transform(result);
    }
}
