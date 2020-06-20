#include <bits/stdc++.h>

using namespace std;
bool mycompare(pair<double,pair<int,int> >a,pair<double,pair<int,int> >b)
{
    return a.first>b.first;
}
int fractionalKanpsack(int* wt,int*price,int items,int Weight)
{
    vector<pair<double,pair<int,int> > >v;
    int totalprice=0;
    for(int i=0;i<items;i++)
    {
        pair<double,pair<int,int> >p;
        p=make_pair(price[i]/wt[i],make_pair(wt[i],price[i]));
        v.push_back(p);
    }
    sort(v.begin(),v.end(),mycompare);
    int i=0;
    while(Weight>0 && i<items)
    {
        int currwt=v[i].second.first;
        if(currwt<=Weight)
        {
            Weight-=currwt;
            totalprice+=v[i].second.second;
        }
        else
        {
            ///fill whole bag
            totalprice+=(v[i].first*Weight);
            Weight=0;
        }
        i++;
    }
    return totalprice;
}

int main()
{
    int wt[10]={2,10,5,2,1,1};
    int price[6]={30000,3000,2000,500,1000,2000};
    int items=6;
    int Weight=13;
    cout<<fractionalKanpsack(wt,price,items,Weight)<<endl;
    return 0;
}
