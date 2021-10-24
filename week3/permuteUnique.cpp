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
    //深度优先搜索，排列树
    void dfs(vector<int>& nums, int i) {
        if(i == n) { //搜索到达叶子结点，记录答案，递归返回
            ans.push_back(seq);
            return;
        }
        for(int k = 0; k < n; k++) {
            //去重：给重复的项（1，1）再规定一个顺序，必须先先第一个1，才能再选第2个1
            if(k >0 && nums[k] == nums[k-1] && visted[k-1] == false) continue;
            if(visted[k] == false) {
                seq.push_back(nums[k]);
                visted[k] = true;
                dfs(nums, i+1);
                //从下层返回后，恢复现场
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