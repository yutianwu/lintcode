public class Solution {
    class TrieNode {
        boolean isWord;
        String word;
        Map<Character, TrieNode> nodes;

        TrieNode() {
            isWord = false;
            word = "";
            nodes = new HashMap<Character, TrieNode>();
        }
    }

    class Trie {
        TrieNode root;

        Trie() {
            root = new TrieNode();
        }

        void insert(String s) {
            TrieNode now = root;
            for (int i = 0; i < s.length(); i++) {
                char ch = s.charAt(i);
                if (!now.nodes.containsKey(ch)) {
                    now.nodes.put(ch, new TrieNode());
                }
                now = now.nodes.get(ch);
            }
            now.isWord = true;
            now.word = s;
        }
    }

    public void search(char[][] board, int x, int y, TrieNode root, ArrayList<String> result) {
        if (root.isWord == true && !result.contains(root.word)) {
            result.add(root.word);
        }

        if (x < 0 || x >= board.length || y < 0 || y >= board[0].length || board[x][y] == 0 || root == null)
            return;

        int[] dx = {1, 0, -1, 0};
        int[] dy = {0, 1, 0, -1};
        if (root.nodes.containsKey(board[x][y])) {
            for(int i = 0; i < 4; i++) {
                char now = board[x][y];
                board[x][y] = 0;
                search(board, x + dx[i], y + dy[i], root.nodes.get(now), result);
                board[x][y] = now;
            }
        }
    }

    /**
     * @param board: A list of lists of character
     * @param words: A list of string
     * @return: A list of string
     */
    public ArrayList<String> wordSearchII(char[][] board, ArrayList<String> words) {
        Trie trie = new Trie();
        for (String word : words) {
            trie.insert(word);
        }

        ArrayList<String> result = new ArrayList<String>();
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[i].length; j++) {
                search(board, i, j, trie.root, result);
            }
        }
        return result;
    }
}
