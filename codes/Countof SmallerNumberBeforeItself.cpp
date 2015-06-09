class Solution {
public:
    class SegmentTreeNode {  
        public:  
            int start, end, count;  
            SegmentTreeNode *left, *right;  
            SegmentTreeNode(int start, int end, int count) {  
                this->start = start;  
                this->end = end;  
                this->count = count;  
                this->left = this->right = NULL;  
            }  
    };  
   /**
     * @param A: An integer array
     * @return: Count the number of element before this element 'ai' is 
     *          smaller than it and return count number array
     */
    vector<int> countOfSmallerNumberII(vector<int> &A) {
        int size = A.size();
        vector<int> result(size, 0);
        if (0 == size) return result;
        SegmentTreeNode *root = new SegmentTreeNode(A[0], A[0], 1);
        for (int i = 1; i < size; i++) 
            result[i] = insert(root, A[i]);
    
        return result;
    }
private:
    SegmentTreeNode *buildLeft(int start, int end) {
        SegmentTreeNode *root = new SegmentTreeNode(start, end, 1);
        if (start == end) return root;
        
        root->left = new SegmentTreeNode(start, start, 1);
        root->right = new SegmentTreeNode(start + 1, end, 0);
        return root;
    }
    
    int insert(SegmentTreeNode *&root, int val) {
        if (root->start > val) {
            SegmentTreeNode *head = new SegmentTreeNode(val, root->end, root->count + 1);
            head->left = buildLeft(val, root->start - 1);
            head->right = root;
            root = head;
            return 0;
        }
        if (root->end < val) {
            int res = root->count;
            SegmentTreeNode *head = new SegmentTreeNode(root->start, val, root->count + 1);
            head->left = root;
            head->right = new SegmentTreeNode(root->end + 1, val, 1);
            root =  head;
            return res;
        }
        root->count += 1;
        
        if (root->left != NULL) {
            if (root->left->end < val) 
                return insert(root->right, val) + root->left->count;
            else 
                return insert(root->left, val);
        } else {
            root->left = new SegmentTreeNode(root->start, val, 1);
            root->right = new SegmentTreeNode(val + 1, root->end, root->count);
        }
        return 0;
    }
};

