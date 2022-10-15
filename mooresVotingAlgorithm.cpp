 class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int c=1,e=nums[0];
        for(int i=1; i<nums.size(); i++){
            if(nums[i]==e)c++;
            else c--;
            if(c==0){
                c=1;
                e=nums[i];
            }
        }
        return e;
    }
};
