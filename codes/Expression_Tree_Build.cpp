/**
 * Definition of ExpressionTreeNode:
 * class ExpressionTreeNode {
 * public:
 *     string symbol;
 *     ExpressionTreeNode *left, *right;
 *     ExpressionTreeNode(string symbol) {
 *         this->symbol = symbol;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param expression: A string array
     * @return: The root of expression tree
     */
    ExpressionTreeNode* build(vector<string> &expression) {
        if (expression.size() == 0) return NULL;
        
        vector<string> postfix;
        infixToPostfix(expression, postfix);
        
        stack<ExpressionTreeNode *> nodeStack;
        for (int i = 0; i < postfix.size(); i++) {
            string cur = postfix[i];
            ExpressionTreeNode *node = new ExpressionTreeNode(cur);
            if (isDigit(cur)) {
                nodeStack.push(node);
            } else {
                node->right = nodeStack.top();
                nodeStack.pop();
                node->left = nodeStack.top();
                nodeStack.pop();
                nodeStack.push(node);
            }
        }
        return nodeStack.empty() ? NULL : nodeStack.top();
    }
    
    void infixToPostfix(vector<string> &infix, vector<string> &postfix) {
        stack<string> operators;
        
        for (int i = 0; i < infix.size(); i++) {
            string cur = infix[i];
            if (isDigit(cur)) {
                postfix.push_back(cur);
            } else if (cur == "(") {
                operators.push("(");
            } else if (cur == ")") {
                while (!operators.empty()) {
                    string top = operators.top();
                    operators.pop();
                    if (top == "(") 
                        break;
                        
                    postfix.push_back(top);
                }
            } else {
                while (!operators.empty()) {
                    string top = operators.top();
                    if (comparePriority(cur, top) || top == "(") 
                        break;
                    
                    operators.pop();
                    postfix.push_back(top);
                }
                operators.push(cur);
            }
        }
        
        while (!operators.empty()) {
            string top = operators.top();
            operators.pop();
            postfix.push_back(top);
        }
    }
    
    bool comparePriority(string cur, string top) {
        if ((cur == "*" || cur == "/")  && (top == "+" || top == "-"))
            return true;
        else 
            return false;
    }
    
    bool isDigit(string s) {
        if (s == "+" || s == "-" || s == "*" || s == "/" || s == "(" || s == ")")
            return false;
        else 
            return true;
    }
};
