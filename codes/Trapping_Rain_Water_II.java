public class Solution {
    class Cell {
        int x;
        int y;
        int height;

        Cell(int x, int y, int height) {
            this.x = x;
            this.y = y;
            this.height = height;
        }
    }

    class CellComparator implements Comparator<Cell> {

        @Override
        public int compare(Cell a, Cell b) {
            return a.height - b.height;
        }
    }

    /**
     * @param heights: a matrix of integers
     * @return: an integer
     */
    public int trapRainWater(int[][] heights) {
        int[] dx = {1, -1, 0, 0};
        int[] dy = {0, 0, 1, -1};
        if (heights.length == 0) return 0;

        int rows = heights.length;
        int cols = heights[0].length;
        int[][] visit = new int[rows][cols];

        PriorityQueue<Cell> cells = new PriorityQueue<Cell>(1, new CellComparator());

        for (int i = 0; i < rows; i++) {
            cells.offer(new Cell(i, 0, heights[i][0]));
            cells.offer(new Cell(i, cols - 1, heights[i][cols - 1]));
            visit[i][0] = 1;
            visit[i][cols - 1] = 1;
        }

        for (int i = 0; i < cols; i++) {
            cells.offer(new Cell(0, i, heights[0][i]));
            visit[0][i] = 1;
            cells.offer(new Cell(rows - 1, i, heights[rows - 1][i]));
            visit[rows - 1][i] = 1;
        }

        int result = 0;
        while (!cells.isEmpty()) {
            Cell cur = cells.poll();

            for (int i = 0; i < 4; i++) {
                int nx = cur.x + dx[i];
                int ny = cur.y + dy[i];

                if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && visit[nx][ny] == 0) {
                    int curHeight = heights[nx][ny];
                    cells.add(new Cell(nx, ny, Math.max(cur.height, curHeight)));
                    visit[nx][ny] = 1;
                    result += Math.max(0, cur.height - curHeight);
                }
            }
        }

        return result;
    }
}