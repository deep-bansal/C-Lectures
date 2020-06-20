#include <bits/stdc++.h>
/**I AM VERY BUSY SPOJ
You are actually very busy man.
You have a big schedule of activities. Your aim is to do as much as activities as possible.
In the given figure, if you go to date with crush, you cannot participate in the coding contest and you can’t watch the movie.
Also if you play DotA, you can’t study for the exam.
If you study for the exam you can’t sleep peacefully.
The maximum number of activities that you can do for this schedule is 3.
Either you can watch movie, play DotA and sleep peacefully (or)
date with crush, play DotA and sleep peacefully**/
using namespace std;
int maxActivities(vector<pair<int,int> >timings,int n)
{
    int noOfActivities=1;
    int lastActivityEndtime=timings[0].first;
    for(int i=1;i<n;i++)
    {
        if(timings[i].second>=lastActivityEndtime)
        {
            noOfActivities++;
            lastActivityEndtime=timings[i].first;
        }
    }
    return noOfActivities;

}

int main()
{
    int testcases;
    cin>>testcases;
    while(testcases--)
    {
        int n;
        cin>>n;
        vector<pair<int,int> >timings;
        for(int i=0;i<n;i++)
        {
            int startTime,endTime;
            cin>>startTime>>endTime;
            timings.push_back(make_pair(endTime,startTime));
        }
        sort(timings.begin(),timings.end());
        cout<<maxActivities(timings,n)<<endl;
    }

    return 0;
}
