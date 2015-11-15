class Solution {
public:
    /**
     * @param expression: a vector of strings;
     * @return: an integer
     */
    int evaluateExpression(vector<string> &expression) {
        if (expression.size() == 0) return 0;
        
        vector<string> postfix;
        infixToPostfix(expression, postfix);
        
        stack<int> result;
        for (int i = 0; i < postfix.size(); i++) {
            string cur = postfix[i];
            if (isDigit(cur)) {
                result.push(convertString(cur));
                continue;
            }
            int rightOperand = result.top();
            result.pop();
            int leftOperand = result.top();
            result.pop();
            
            int tmp = 0;
            if (cur == "+") {
                tmp = leftOperand + rightOperand;
            } else if (cur == "-") {
                tmp = leftOperand - rightOperand;
            } else if (cur == "*") {
                tmp = leftOperand * rightOperand;
            } else if (cur == "/") {
                tmp = leftOperand / rightOperand;
            }
            result.push(tmp);
        }
        
        return result.top();
    }
    
    int convertString(string s) {
        int result = 0;
        int size = s.size();
        for (int i = 0; i < size; i++) {
            int num = s[i] - '0';
            result += num * pow(10, size - i - 1);
        }
        return result;
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
