class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> mp;
        for(int i=0;i<arr.size();i++)
            mp[arr[i]]++;

        unordered_set<int> st;
        for(auto it:mp){
            int ocr = it.second;
            if(st.find(ocr) != st.end()){
                return false;
            }
            st.insert(ocr);
        }
        return true;
    }
};