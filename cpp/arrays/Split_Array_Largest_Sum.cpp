class Solution {
public:
    int sumcount(vector<int>& nums, int a)
    {
        int sum=0;
        int n=nums.size();
        int subarray=1;
        for(int i=0;i<n;i++)
        if(sum+nums[i]<=a)
        {
             sum+=nums[i];
        }
        else
        {
            subarray++;
            sum=nums[i];
        }
        return subarray;
    }
    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(),nums.end()),high=accumulate(nums.begin(),nums.end(),0);
        while(low<=high)
        {
            int mid=(high+low)/2;
            int s=sumcount(nums,mid);
            if(s<=k)
            {
                high=mid-1;
            }
            else
            {
                                low=mid+1;

            }
    }
    return low;
    }
};
