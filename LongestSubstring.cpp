#include <unordered_set>

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        // 'dict' is used to store the last index where each character was seen
        vector<int> dict(256, -1);

        // 'maxLen' keeps track of the maximum length of substring without repeating characters
        int maxLen = 0;

        // 'start' is the starting index of the current substring without repeating characters
        int start = -1;

        for (int i = 0; i != s.length(); i++)
        {
            // The dictionary is a vector of integers, so ascii characters are given integer representations
            // This means that when "a" is added to the vector it becomes "97" and the 97 place becomes i
            // When we check to see if the character is there we check if it is still -1 or not
            // If the dict position is > -1 then the start becomes that position
            // Then finally the max length is updated by seeing whether the previous max length is longer or the point in the
            // string subtracted by start
            if (dict[s[i]] > start) start = dict[s[i]];

            // Update the last index of the current character
            dict[s[i]] = i;

            // Update 'maxLen' with the maximum length so far
            maxLen = max(maxLen, i - start);
        }

        return maxLen;
    }
};
