class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_map<int, int> mp;
        stack<int> st;
        int n1 = nums1.size(), n2 = nums2.size();

        for(int i = n2-1; i>=0; i--){
            while(!st.empty() && nums2[i] > st.top()) st.pop();
            if(!st.empty()) mp[nums2[i]] = st.top();
            else mp[nums2[i]] = -1;

            st.push(nums2[i]);
        }

        vector<int> res;
        for(int i=0; i<n1; i++){
            res.push_back(mp[nums1[i]]);
        }

        return res;
    }
};