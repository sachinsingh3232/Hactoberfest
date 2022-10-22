# leetcode problem link: https://leetcode.com/problems/generate-parentheses/
"""
This preoblem is all abot generating well-formed parentheses.
An interger, n, will be given as input.
Task is to generate all the combinations well-formed parentheses

Approach : BACKTRACKING
"""
from __future__ import annotations


def generateParentheses(o, c, curStr, ans) -> None:
    """
    if open == 0 and
    """
    if o == 0 and c == 0:
        ans.append(curStr)
        return
    
    """
    if open == close then we can only insert an open parenthesis,
    as there has to be at least one open parenthesis to be closed
    """
    if o == c:
        generateParentheses(o-1, c, curStr+'(', ans)
    
    elif o != 0 and o < c:
        # insert a open parenthesis
        generateParentheses(o-1, c, curStr+'(', ans)
        
        # insert a close parenthesis
        generateParentheses(o, c-1, curStr+')', ans)
        
    elif o == 0:
        generateParentheses(o, c-1, curStr+')', ans)
    
    return

def main() -> None:
    n = int(input())
    """
    o : total opening parentheses
    c : total closing parentheses
    ans : list[str] to store final answer
    curStr : will hold string on every call
    """
    o, c  = n, n
    ans = []
    curStr = ""
    generateParentheses(o, c, curStr, ans)
    
    print(ans)



if __name__ == "__main__":
    main()
