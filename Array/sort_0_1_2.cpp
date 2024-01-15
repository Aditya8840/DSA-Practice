/*
Using constant space 
keep count of 0,1 and 2's and then overwrite
*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        map<int, int> mp;

        for(auto i: nums){
            mp[i]++;
        }

        int k = 0;
        for(auto i:mp){
            for(int n =  k;n < i.second+k; n++){
                // cout<<n<<" "<<k<<" ";
                nums[n] = i.first;
            }
            k+=i.second;
        }
    }
};