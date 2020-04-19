class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        if (s.length() < 2)
            return s.length();
        
        int left = 0;
        int right = 0;
        vector<int> c(256,-1);
        int len = 0;
        while(right < s.length())
        {
            if (c[s[right]] == -1 || c[s[right]] <left)
            {
                c[s[right]] = right;
                right++;
            }
            else
            {
                len = max(len, right-left);
                left = c[s[right]] + 1;
            }
        }
        len = max(len, right-left);
        return len;
    }
};