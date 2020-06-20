#include <iostream>
#include<vector>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    vector<int>v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(50);
    v.push_back(40);
    v.push_back(50);
    v.push_back(40);
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<endl;
    }
    cout<<endl;
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<endl;
    }
    cout<<endl;
    v.erase(v.begin(),v.begin()+1);
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<endl;
    }
     cout<<endl;
     cout<<v.capacity()<<endl;
     cout<<endl;

     ///accessing and entering values in pair
     pair<int,string>p;
     p=make_pair(10,"abc");
     cout<<p.first<<" "<<p.second<<endl;
     p.first=4000;
     vector<pair<int,string> >v1;
     v1.push_back(p);
     v1.push_back(make_pair(70,"aaaa"));
     for(int i=0;i<v1.size();i++)
     {
         cout<<v1[i].first<<" "<<v1[i].second<<endl;
     }













    return 0;
}
