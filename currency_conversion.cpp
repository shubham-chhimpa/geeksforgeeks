// Online C++ compiler to run C++ program online
#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;
/*

We are a currency exchange website. Given a list of exchange rates between two currencies, compute the value of the amount provided in one currency into the other currency.

USD INR 76.29
USD GBP 0.76
JPY INR 0.63
GBP EUR 1.2

USD --> GBP --> EUR
USD --> INR --> JPY

(10 * 76.29 ) / 0.63

        JPY
         |
USD ---INR
|
|
GBP

Input-1
10 USD EUR

Output-1
9.12

Input-2
10 USD JPY

Output-2
1210.95

*/



class Graph {
    public : 
    unordered_map<string,vector<pair<string,float>>> adj;
    float ans = -1;
    Graph(){
        
        
    }
    void insert(string from_curr,string to_curr,float val){
        adj[from_curr].push_back({to_curr,val});
        adj[to_curr].push_back({from_curr,1/val});
    }
    
    void dfs(pair<string,float> source,string target,float val,unordered_set<string> &vis){
        if(source.first == target){
            ans =   val * source.second;
            return;
        };
        vis.insert(source.first);
        for(auto neighbour : adj[source.first]){
            if(vis.find(neighbour.first) == vis.end()){
               dfs(neighbour,target,val* source.second,vis);
            }
        }
    }
    
    float convert(string from_curr,string to_curr,float amount){
        ans = -1;
        unordered_set<string> vis;
        dfs({from_curr,1},to_curr,amount,vis);
        return ans;
    }
    
};


int main(){

    
    Graph g;
    g.insert("USD","INR",76.29);
    g.insert("USD", "GBP", 0.76);
    g.insert("JPY" ,"INR", 0.63);
    g.insert("GBP", "EUR", 1.2);
 
 
    cout<<g.convert("US","EUR",10)<<"\n";
    cout<<g.convert("USD","JPY",10)<<"\n";
}
