class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        //��ϣ��left��right��counter
        //key:nums[i]
        //value:nums[i]��һ�γ��ֶ�Ӧ���±꣬nums[i]���һ�γ��ֶ�Ӧ���±꣬nums[i]���ֵĴ���
        unordered_map<int,int> left, right, counter;
        int degree = 0;//����Ķ�
        int length = nums.size();//��Ϊdegree���������������ĳ���
        //����nums�����������ϣ���������Ķ�degree
        for(int i=0; i<nums.size(); i++)
        {
            if(left.count(nums[i]) == 0)//��һ��ɨ�赽nums[i]
            {
                counter[nums[i]] = 1;
                left[nums[i]] = i;
                right[nums[i]] = i;
            }
            else//���ǵ�һ��ɨ�赽nums[i]
            {
                counter[nums[i]]++;
                right[nums[i]] = i;
            }
            degree = max(degree,counter[nums[i]]);     
        }
        //������ϣ��counter���ҳ����г��ִ�������degree�ļ�¼
        //������Щ��¼��key������ϣ��left��right�����length
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