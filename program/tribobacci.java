class Solution {
    public int tribonacci(int n) {

        if (n < 2)
            return n;
        if (n == 2)
            return 1;

        int prev = 1, prev2 = 1, prev3 = 0;

        for (int i = 3; i <= n; i++) {
            int curr = prev + prev2 + prev3;
            prev3 = prev2;
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
}