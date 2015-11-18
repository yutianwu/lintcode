public class WordDictionary {
    class TrieNode {
        boolean isWord;
        Map<Character, TrieNode> nodes;

        TrieNode() {
            isWord = false;
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
        }
    }

    private Trie root;

    // Adds a word into the data structure.
    public void addWord(String word) {
        if (root == null)
            root = new Trie();

        root.insert(word);
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    public boolean search(String word) {
        if (root == null) return false;
        
        return search(word, 0, root.root);
    }

    public boolean search(String word, int pos, TrieNode root) {
        if (root == null) return false;

        if (pos == word.length() && root.isWord)
            return true;
        else if (pos == word.length())
            return false;

        boolean result = false;
        Character cur = word.charAt(pos);
        ArrayList<TrieNode> candidates = new ArrayList<TrieNode>();
        if (cur == '.') {
            for (TrieNode node : root.nodes.values()) {
                candidates.add(node);
            }
        } else {
            if (root.nodes.get(cur) != null)
                candidates.add(root.nodes.get(cur));
        }

        for (TrieNode node : candidates) {
            result |= search(word, pos + 1, node);
            if (result)
                return result;
        }

        return result;
    }
}

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary = new WordDictionary();
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
