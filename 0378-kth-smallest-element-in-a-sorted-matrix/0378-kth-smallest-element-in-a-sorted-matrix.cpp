class Solution {
public:


 // vector<pair<int,pair<int,int>>>temp;
        // for(int i=0;i<matrix.size();i++){
        //  temp.push_back(make_pair(matrix[i][0],make_pair(i,0)));
        // }
        // priority_queue<pair<int,pair<int,int>>>pq(temp.begin(),temp.end());

        // pair<int,pair<int,int>>element;
        // int ans,i=0,j=0;
        // while(k--){
        //  element = pq.top();
        //  pq.pop();
        //  ans = element.first;
        //  i = element.second.first;
        //  j = element.second.second;
        //  if((j+1)<matrix[0].size()){
        //     pq.push(make_pair(matrix[i][j+1],make_pair(i,j+1)));
        //  }
        // }
        // return ans;
    int count_elem(vector<vector<int>>& matrix, int elem){
        int count = 0;
          for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
              if(matrix[i][j] <= elem) count++;
              else if(matrix[i][j] > elem) break;
            }
          }
          return count;
    }    

    int kthSmallest(vector<vector<int>>& matrix, int k) {

       int start = matrix[0][0],end = matrix[matrix.size()-1][matrix[0].size()-1];   int ans=0;

       while(start < end){
          int mid = start + (end - start)/2;
          int small_elem = count_elem(matrix,mid);
          if(small_elem >= k){
            ans = mid;
            end = mid;
          }

          else{
            start = mid+1;
          }

       }
       return start;



    }
};