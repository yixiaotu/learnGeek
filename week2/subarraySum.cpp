class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //��ʦ�������������д�l��r���Ӷεĺͣ�������ǰ׺������õ�����pre[r]-pre[l-1]
        //�̶��Ҷ�r���ƶ����l
        //pre[r]-pre[l-1]=k���Ƴ�pre[l-1]=pre[r]-k
        //����һ���̶����Ҷ�r��˵���м���pre[l-1]=pre[r]-k�����м�����rΪֹ�ĺ�Ϊk������������
        //�ù�ϣ���¼ÿ��pre[i]���ֵĴ���
        vector<int> pre(nums.size()+1,0);//ǰ׺�����飬pre[0]=0
        for(int i=0;i<nums.size();i++)
        {
            pre[i+1] = pre[i] + nums[i];
        }
        
        unordered_map<int,int> hashMap;//key:pre[i],value:pre[i]���ֵĴ���
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