class Solution {
public:
    /**
     * @param expression: A string array
     * @return: The Reverse Polish notation of this expression
     */
    vector<string> convertToRPN(vector<string> &expression) {
        vector<string> result;
        stack<string> operators;
        
        for (int i = 0; i < expression.size(); i++) {
            string cur = expression[i];
            if (isDigit(cur)) {
                result.push_back(cur);
            } else if (cur == "(") {
                operators.push("(");
            } else if (cur == ")") {
                while (!operators.empty()) {
                    string top = operators.top();
                    operators.pop();
                    if (top == "(") 
                        break;
                        
                    result.push_back(top);
                }
            } else {
                while (!operators.empty()) {
                    string top = operators.top();
                    if (comparePriority(cur, top) || top == "(") 
                        break;
                    
                    operators.pop();
                    result.push_back(top);
                }
                operators.push(cur);
            }
        }
        
        while (!operators.empty()) {
            string top = operators.top();
            operators.pop();
            result.push_back(top);
        }
        
        return result;
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
