
// https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/

// Subset Sum Problem

class Solution{   
public:

    bool solve(vector<int> &arr,int n,int sum,vector<vector<int>> &memo){
        if(sum ==0) return true;
        if(n<=0) return false;
       
        if(memo[n][sum] !=-1) return memo[n][sum];
        if(arr[n-1]<=sum){
            return memo[n][sum]= (solve(arr,n-1,sum-arr[n-1],memo) || solve(arr,n-1,sum,memo));
        }else{
            return memo[n][sum]=solve(arr,n-1,sum,memo);
        }
    }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        
        int n = arr.size();
        vector<vector<int>> memo(n+1,vector<int>(sum+1,-1));
        solve(arr,n,sum,memo);
        return memo[n][sum];
    }
};
