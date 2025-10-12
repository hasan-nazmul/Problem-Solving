#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map <int, int> mp;
        vector <int> indexes;
        for(int i = 0; i < (int) nums.size(); i++)
        {
            mp[nums[i]] = i;
        }
        for(int i = 0; i < (int) nums.size(); i++)
        {
            if(mp[target - nums[i]] && mp[target - nums[i]] != i)
            {
                indexes.push_back(i);
                indexes.push_back(mp[target - nums[i]]);
                break;
            }
        }
        return indexes;
    }
};