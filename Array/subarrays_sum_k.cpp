/*
Use prefix sum and map 

mp[0] = 1 is important

*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int, int> mp;
        int n = nums.size();
        vector<int> v(n);

        int sum = 0;
        int count = 0;
        mp[0] = 1;
        for (int n : nums) {
            sum += n;
            
            // cout<<mp[sum - k]<<endl;
            count += mp[sum - k];
            mp[sum]++;
        }
        // count += mp[k];

        return count;
    }
};