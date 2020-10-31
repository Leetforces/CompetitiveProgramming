#include <bits/stdc++.h>
using namespace std;
void solve()
{
   int arr[]={ 1,2,3,3,3,3,5,6,8};
   int n=sizeof(arr)/sizeof(arr[0]);
   
   vector<int> v(arr,arr+n);
   sort(v.begin(),v.end());


   bool find3= binary_search(v.begin(),v.end(),3);
   if(find3)
    cout<<"3 is present"<<"\n";
   else
    cout<<"3 is not present"<<"\n";
   
   vector<int>::iterator low,up;
   
   // return iterator pointing to  just >=3
   low=lower_bound(v.begin(),v.end(),3);

   //return iterator pointing to just >3
   up=upper_bound(v.begin(),v.end(),3);
   
   
   cout<<"Lower Bound Index: "<<lower_bound(v.begin(),v.end(),3)-v.begin()<<"\n";
   cout<<"Upper Bound Index: "<<upper_bound(v.begin(),v.end(),3)-v.begin()<<"\n";
   
   // Directly access index without using any iterator
   //    cout<<"Lower Bound Index: "<<low-v.begin()<<"\n";
   //    cout<<"Upper Bound Index: "<<up-v.begin()<<"\n";
}
 /*
   output
   -------
   3 is present
   Lower Bound Index: 2
   Upper Bound Index: 6

*/

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
