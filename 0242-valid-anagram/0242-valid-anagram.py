class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False

        count = [0] * 26

        # Count characters in s
        for ch in s:
            count[ord(ch) - ord('a')] += 1

        # Remove characters according to t
        for ch in t:
            count[ord(ch) - ord('a')] -= 1

        # If all counts are 0, they are anagrams
        return all(value == 0 for value in count)