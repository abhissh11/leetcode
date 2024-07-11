class Solution {
public:
    string reverseParentheses(string s) {
       // Traverse a string by using pointer
    //If we found '(' then we simply push this into stack.
    //Else if we found ')' then we will match it with '(' which is top element of a stack.
    //We initialize 2 pointers namely "start" and "end" of string which are inside paranthesis and 
    //we will reverse it using reverse() function of c++
    //If still there are brackets in our string then we will declare a new string "ans" which is intially null.
//We will again traverse whole string and if we found "(" or ")" then we will simply skip it and other charchters will be pushed into string.
    //We will return ans string as a final solution.
        stack<int>st;
       
       for(int i=0;i<s.size();i++){
           
            if(s[i]=='(') st.push(i);
            else if(s[i]==')'){
                int start=st.top()+1;
                int end=i;
                reverse(s.begin()+start, s.begin()+end);
                st.pop();
            }
       }

       //if still brackets in the string
       string ans="";
       for(int i=0;i<s.size();i++){
        if(s[i]=='(' || s[i]==')') continue;
        ans.push_back(s[i]);
       }
       return ans;
    }
};