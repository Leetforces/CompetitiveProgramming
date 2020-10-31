#include <bits/stdc++.h>
using namespace std;

class comp{
 public:
   bool operator()(const int& a,const int& b) 
   {
       // it is descending order (by default priority_queue is maximum)
       return a<b;
   }
};
void solve()
{
   int arr[] ={1,5,6,3,4,5,3,9};
   int n=sizeof(arr)/sizeof(int);

   // ordering is decided by comp function
   priority_queue<int,vector<int>,comp> pq;
   
   // push all the elements
   for(int i=0;i<n;i++)
   pq.push(arr[i]);

   // print all the elements
   while(!pq.empty())
   {
       cout<<pq.top()<<" ";
       pq.pop();
   }
   cout<<"\n";
   

   /*
      Output
      ----------
       9 6 5 5 4 3 3 1 
   */

}
int main() {
	ios_base::sync_with_stdio(false);
       cin.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("./../input.txt", "r", stdin);
	freopen("./../output.txt", "w", stdout);
	#endif
	solve();
	return 0;
}