class Solution {
public:
    int minOperations(vector<string>& logs) {
        // create stack then simple checking for two conditions , 
        //If log == "../" (go back): pop the current child
        //at the last return the size of stack .
        //If log == "./" (stay put): ignore this entry as it doesn't change the depth.
        //If log is a directory name (go down): Push "+" onto the stack.
        stack<string> st;

        for(auto it: logs){
            if(it == "../"){
                if(!st.empty()){
                    st.pop();   //child is removed if exist
                }
            }
            else if(it != "./"){
                st.push("+");   //new child added
            }
        }
        return st.size();
    }
};