class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> freq;

        for(char ch : s){
            freq[ch]++;
        }
        int length = 0;
        int hasOdd = false;

        for(auto& [ch, count]:freq ){
            if(count %2 == 0){
                length += count;
            }
            else{
                length += count-1;
                hasOdd = true;
            }
        }
        if(hasOdd){
            length += 1;
        }
        return length;

    }
};