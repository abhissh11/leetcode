class Solution {
    void func(int n, int k, int i, vector<int> &temp, vector<vector<int>> &ans){
        if(temp.size() == k){
            ans.push_back(temp);
            return;

        }
        for(int j = i; j<=n; j++){
            temp.push_back(j);
            func(n, k, j+1, temp, ans);
            temp.pop_back();
        }
        return;
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;
        func(n, k, 1, temp, ans);
        return ans;
    }
};