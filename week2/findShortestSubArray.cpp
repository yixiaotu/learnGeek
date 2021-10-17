class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        //哈希表left，right，counter
        //key:nums[i]
        //value:nums[i]第一次出现对应的下标，nums[i]最后一次出现对应的下标，nums[i]出现的次数
        unordered_map<int,int> left, right, counter;
        int degree = 0;//数组的度
        int length = nums.size();//度为degree的最短连续子数组的长度
        //遍历nums，填充三个哈希表并求出数组的度degree
        for(int i=0; i<nums.size(); i++)
        {
            if(left.count(nums[i]) == 0)//第一次扫描到nums[i]
            {
                counter[nums[i]] = 1;
                left[nums[i]] = i;
                right[nums[i]] = i;
            }
            else//不是第一次扫描到nums[i]
            {
                counter[nums[i]]++;
                right[nums[i]] = i;
            }
            degree = max(degree,counter[nums[i]]);     
        }
        //遍历哈希表counter，找出所有出现次数等于degree的记录
        //根据这些记录的key关联哈希表left和right，求出length
        for(auto &count:counter)
        {
            if(count.second == degree)
            {
                length = min(length,right[count.first] - left[count.first] + 1);
            }
        }
        return length;
    }
};