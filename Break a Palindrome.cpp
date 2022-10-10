class Solution
{
public:
    string breakPalindrome(string palindrome)
    {
        if (palindrome.length() == 1)
            return "";
        int flag = 0, n = palindrome.length();
        string str = palindrome;
        for (int i = 0; i < n / 2; i++)
        {
            if (str[i] != 'a')
            {
                str[i] = 'a';
                flag = 1;
                break;
            }
        }

        //flag will be zero only when all the characters except the middle one will be 'a'.
        if (flag == 0)
        {
            str[n - 1] = 'b';
        }
        return str;
    }
};