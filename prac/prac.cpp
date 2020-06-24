#include <bits/stdc++.h> 
#include <iostream> 
using namespace std; 
  
class circle { 
public:
    int start, end; 
}; 

bool comp(circle a, circle b) 
{ 
    if (a.end == b.end) 
        return a.start < b.start; 
    return a.end < b.end; 
} 
 
void CountCircles(vector<int> c,vector<int> r, int n) 
{ 
 
    circle diameter[n]; 
  
    for (int i = 0; i < n; ++i) { 
        diameter[i].start = c[i] - r[i]; 
  
        diameter[i].end = c[i] + r[i]; 
    } 
    sort(diameter, diameter + n, comp); 
  

    int count = 0; 
  
     
    int cur = diameter[0].end; 
    for (int i = 1; i < n; ++i) { 

        if (diameter[i].start > cur) { 
            cur = diameter[i].end; 
        } 

        else
            count++; 
    } 
  
    cout << count << endl; 
} 

int main() 
{ 
	int n;
	cin>>n;
	vector<int>c;
	vector<int>r;
	for (int i = 0; i < n; ++i)
	{
		int ce,ri;
		cin>>ce;
		c.push_back(ce);
		cin>>ri;
		r.push_back(ri);
	}
    
   
  
    CountCircles(c, r, n); 
  
    return 0; 
} 