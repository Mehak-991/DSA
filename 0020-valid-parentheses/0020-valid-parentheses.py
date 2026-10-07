class Solution:
    def isValid(self, s: str) -> bool:
        stack = []

        pairs = {
            ')': '(',
            ']': '[',
            '}': '{'
        }

        for bracket in s:
            if bracket in "([{":
                stack.append(bracket)

            else:
                # No opening bracket available
                if not stack:
                    return False

                # Check if brackets match
                if stack.pop() != pairs[bracket]:
                    return False

        # Stack should be empty if everything was closed
        return len(stack) == 0
        