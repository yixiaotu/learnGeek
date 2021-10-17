class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //老师讲过，求数组中从l到r的子段的和，可以用前缀和相减得到，即pre[r]-pre[l-1]
        //固定右端r，移动左端l
        //pre[r]-pre[l-1]=k，推出pre[l-1]=pre[r]-k
        //对于一个固定的右端r来说，有几个pre[l-1]=pre[r]-k，就有几个到r为止的和为k的连续子数组
        //用哈希表记录每个pre[i]出现的次数
        vector<int> pre(nums.size()+1,0);//前缀和数组，pre[0]=0
        for(int i=0;i<nums.size();i++)
        {
            pre[i+1] = pre[i] + nums[i];
        }
        
        unordered_map<int,int> hashMap;//key:pre[i],value:pre[i]出现的次数
        hashMap[pre[0]] = 1;
        int ans=0;
        for(int j=1;j<pre.size();j++)
        {
            if(hashMap.count(pre[j]-k) != 0)
            {
                ans += hashMap[pre[j]-k];
            }
            hashMap[pre[j]]++;
        }
        return ans;
    }
};