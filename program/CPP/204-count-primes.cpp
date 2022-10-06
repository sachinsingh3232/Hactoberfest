class Solution {
public:
    int countPrimes(int n) {
        int count = 0;
        int arr[n + 1];
        if(n > 2) {
            count++;
            for(int i = 3; i < n; i+=2) {
                arr[i] = 0;
            }
            for(int j = 3; j < n; j+=2) {
                if(arr[j] == 0) {
                    count++;
                    for(int i = 2*j; i < n; i+=j) {
                        arr[i] = 1;
                    }
                }
            }
        }
        return count;
    }
};
