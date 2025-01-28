class Solution(object):
    def longestCommonSubsequence(self, text1, text2):
        """
        :type text1: str
        :type text2: str
        :rtype: int
        """
        dp = [0] * len(text1)
        longe = 0
        for c in text2:
            cur_len = 0
            for i,val in enumerate(dp):
                if cur_len < val:
                    cur_len = val
                elif c == text1[i]:
                    dp[i] = cur_len + 1
                    longe = max(longe,cur_len+1)
        return longe

        