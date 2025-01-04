class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> leftCount(26, 0);     // Count of characters on the left
        vector<int> rightCount(26, 0);    // Count of characters on the right
        unordered_set<string> palindromes; // Store unique palindromes

        // Initialize the rightCount with the frequency of characters in the string
        for (char c : s) {
            rightCount[c - 'a']++;
        }

        for (int i = 0; i < s.size(); i++) {
            char current = s[i];

            // Decrement current character from rightCount
            rightCount[current - 'a']--;

            // Check for unique palindromes with `current` as the middle character
            for (int j = 0; j < 26; j++) {
                if (leftCount[j] > 0 && rightCount[j] > 0) {
                    // Form a palindrome: left -> current -> right
                    string palindrome = string(1, 'a' + j) + current + string(1, 'a' + j);
                    palindromes.insert(palindrome);
                }
            }

            // Increment current character in leftCount
            leftCount[current - 'a']++;
        }

        // Return the count of unique palindromes
        return palindromes.size();
    }
};
