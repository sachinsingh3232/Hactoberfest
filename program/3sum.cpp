class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      //sort the given func
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>temp;
      //for traversing a
        for(int i=0;i<nums.size();i++){
            //condition to opt a 
            if(i==0 || i>0 && nums[i]!=nums[i-1]){
                int lo=i+1,hi=nums.size()-1,sum=0-nums[i];//target-a
                while(lo<hi){
                    if(nums[lo]+nums[hi]==sum){
                        
                        temp.push_back(nums[lo]);
                        temp.push_back(nums[hi]);
                        temp.push_back(nums[i]);
                        ans.push_back(temp);
                        temp.clear();
                    while(lo<hi && nums[lo]==nums[lo+1])lo++;
                        while(lo<hi && nums[hi]==nums[hi-1])hi--;
                        lo++;
                        hi--;
                    }
                    else
                        if(nums[lo]+nums[hi]<sum){
                            lo++;
                        }
                    else
                        hi--;
                }
            }
        }
        return ans;
    }
};