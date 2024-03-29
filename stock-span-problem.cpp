
//https://practice.geeksforgeeks.org/problems/stock-span-problem-1587115621/1/
//stock-span-problem
class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       vector<int> ans;
       stack<pair<int,int>> st;
       for(int i=0;i<n;i++){
           while(!st.empty() && st.top().first <= price[i]){
               st.pop();
           }
           
           if(st.empty()){
               ans.push_back(i- (-1));
           }else{
               ans.push_back(i- st.top().second);
           }
           
           st.push({price[i],i});
       }
       
       return ans;
    }
};
