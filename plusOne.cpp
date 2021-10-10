class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int>::iterator v = digits.begin();
        digits.insert(v,0);
        int len = digits.size();
        vector<int> ret(len,0);//结果
        int add = 1;//每一位要加的数
        int res = 0;//res = digit[i]+add
        for(int i=len-1,j=0;i>=0;i--)
        {
            res = digits[i]+add;
            if(res == 10)
            {
                ret[j++] = 0;
                add = 1;
            }
            else
            {
                ret[j++] = res;
                add = 0;
            }
        }
        //将ret逆序
        int left = 0;
        int right = ret.size()-1;
        if(ret[right] == 0)
        {
            ret.pop_back();
            right--;
        }
        int temp;
        while(left<right)
        {
            temp = ret[left];
            ret[left] = ret[right];
            ret[right] = temp;
            left++;
            right--;
        }
        return ret;
    }
};