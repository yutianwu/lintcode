/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */
class MySegmentTreeNode {
public:
    int start, end;
    long long max;
    MySegmentTreeNode *left, *right;
    MySegmentTreeNode(int start, int end) {
        this->start = start, this->end = end;
        this->left = this->right = NULL;
    }
};

class Solution { 
public:
    /**
     *@param A, queries: Given an integer array and an query list
     *@return: The result list
     */
    vector<long long> intervalSum(vector<int> &A, vector<Interval> &queries) {
        vector<long long> res;
        if (A.size() == 0) return res;
        
        Interval init = Interval(0, A.size() - 1);
        MySegmentTreeNode *root = buildSegmentTree(A, init);
        for (int i = 0; i < queries.size(); i++) {
            long long tmp = query(root, queries[i]);
            res.push_back(tmp);
        }
        return res;
    }
    
    MySegmentTreeNode *buildSegmentTree(vector<int> &A, Interval &inter) {
        if (inter.start > inter.end) return NULL;
        
        MySegmentTreeNode *root = new MySegmentTreeNode(inter.start, inter.end);
        if (inter.start == inter.end) {
            root->max = A[inter.start];
            return root;
        }
        
        int mid = inter.start + (inter.end - inter.start)/2;
        Interval left = Interval(inter.start, mid);
        root->left = buildSegmentTree(A, left);
        Interval right = Interval(mid + 1, inter.end);
        root->right = buildSegmentTree(A, right);
        root->max = (root->left == NULL ? 0 : root->left->max) + (root->right == NULL ? 0 : root->right->max);
        return root;
    }
    
    long long query(MySegmentTreeNode *root, Interval &inter) {
        if (root == NULL) return 0;
        if (root->start == inter.start && root->end == inter.end) return root->max;
        
        int mid = root->start + (root->end - root->start)/2;
        long long res = 0;
        if (inter.end <= mid) {
            res = query(root->left, inter);
        } else if (inter.start > mid) {
            res = query(root->right, inter);
        } else {
            Interval left = Interval(inter.start, mid);
            res += query(root->left, left);
            Interval right = Interval(mid + 1, inter.end);
            res += query(root->right, right);
        }
        return res;
    }
};