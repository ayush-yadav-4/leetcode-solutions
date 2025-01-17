class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
      deque<int>q; vector<int>ans;
       for(int i = 0 ; i<k-1;i++){
          if(q.empty()) q.push_back(i);
          else{ while(!q.empty() && nums[i]>= nums[q.back()]){
            q.pop_back();
           }
           q.push_back(i);}
       }

       for(int i=k-1;i<nums.size();i++){
       
        while(!q.empty() && nums[i]>= nums[q.back()]){
            q.pop_back();
           }
             q.push_back(i);
          
         
        if(q.front()<= (i-k)){ q.pop_front();}
          ans.push_back(nums[q.front()]);
       }
       return ans;
    }
};