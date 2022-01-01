// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& v) {
        //code here
        vector<string>v2=v;
    map<string,int>m;
    for(int i=0;i<v.size();i++)
    {
        string s=v2[i];
        sort(s.begin(),s.end());
        v2[i]=s;
        m[s]++;
    }
    vector<vector<string>>res;
    vector<int>flag(v.size(),0);
    // for(auto i:v2)
    // {
    //     cout<<i<<" ";
    // }

    for(int i=0;i<v2.size();i++)
    {
        if(flag[i]!=1)
        {
        vector<string>ans;
        string s=v2[i];
        ans.push_back(v[i]);
        flag[i]=1;
        if(m[s]>1 ){
        for(int j=i+1;j<v.size();j++)
        {
            if(s==v2[j] )
            {
                ans.push_back(v[j]);
                // cout<<"v[j]: "<<v[j]<<endl;
                flag[j]=1;
            }
        }
        }
        res.push_back(ans);
        }
    }
    return res;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin>>string_list[i]; 
        Solution ob;
        vector<vector<string> > result = ob.Anagrams(string_list);
        sort(result.begin(),result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for(int j=0; j < result[i].size(); j++)
            {
                cout<<result[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}
  // } Driver Code Ends