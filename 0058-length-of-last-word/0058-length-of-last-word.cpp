class Solution {
public:
    int lengthOfLastWord(string s) {
        string str="";
        vector<string> v;
        
        for(int i=0; i<s.length(); i++){
            if(s[i] != ' '){
                str+=s[i];
            }
            if(s[i] == ' ' && str.length()>0){
                v.push_back(str);
                str="";
            }
        }
        if(str.length() > 0)
        v.push_back(str);
        return v[v.size()-1].length();
    }
};