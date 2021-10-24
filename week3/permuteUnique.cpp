class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        n = nums.size();
        visted = vector<bool>(n, false);
        dfs(nums, 0);
        return ans;
    }
private:
    //�������������������
    void dfs(vector<int>& nums, int i) {
        if(i == n) { //��������Ҷ�ӽ�㣬��¼�𰸣��ݹ鷵��
            ans.push_back(seq);
            return;
        }
        for(int k = 0; k < n; k++) {
            //ȥ�أ����ظ����1��1���ٹ涨һ��˳�򣬱������ȵ�һ��1��������ѡ��2��1
            if(k >0 && nums[k] == nums[k-1] && visted[k-1] == false) continue;
            if(visted[k] == false) {
                seq.push_back(nums[k]);
                visted[k] = true;
                dfs(nums, i+1);
                //���²㷵�غ󣬻ָ��ֳ�
                visted[k] = false;
                seq.pop_back();
            }
        }
    }
    vector<bool> visted;
    int n;
    vector<int> seq;
    vector<vector<int>> ans;
};