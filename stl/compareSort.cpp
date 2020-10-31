#include <bits/stdc++.h>
using namespace std;
bool compare(int a,int b)
{
    // descending order
    return a>b;
}
void solve()
{
   int arr[] ={1,5,6,3,4,5,3,9};
   int n=sizeof(arr)/sizeof(int);
   
   //sort according to compare function
   sort(arr,arr+n,compare); 

   for(int i=0;i<n;i++)
   cout<<arr[i]<<" ";
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
	solve();
	return 0;
}