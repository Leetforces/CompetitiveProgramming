
 //Question Link : https://www.spoj.com/problems/SEQ/
 // Time complexity: k^3 log(N)gi
#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000000
int64_t **temp;
void multiply(int64_t **mat,int64_t **p,int k)
{
    int tempmat[k][k];
    for(int i=0;i<k;i++)
    for(int j=0;j<k;j++)
    {
        tempmat[i][j]=0;
        for(int l=0;l<k;l++)
        {
            tempmat[i][j]=(tempmat[i][j]+(mat[i][l]*p[l][j])%MOD)%MOD;
        }
    }
    for(int i=0;i<k;i++)
    for(int j=0;j<k;j++)
    mat[i][j]=tempmat[i][j];
}
void power(int64_t **mat,int x,int k){
    if(x<=1)
    return ;
    power(mat,x/2,k);
    multiply(mat,mat,k);
    if(x&1){

        multiply(mat,temp,k);
    }
}
void solve()
{
    // f(n)= a*f(n-1)+b*f(n-2)+c*f(n-3)+ ... + __* f(n-k) 
    /*
          | f(n)    |                     f(n-1)
          | f(n-1)  |                     f(n-2)
          | f(n-2)  |                       .
          |    .    |  = k*k matrix         .
          |    .    |                       .
          | f(n-k)  |                       .
 

    */
   int k;
   cin>>k;

   int64_t f[k];
   for(int i=0;i<k;i++)
   cin>>f[i];

   int64_t **mat=new  int64_t*[k];
   for(int i=0;i<k;i++)
   mat[i]=new int64_t[k];

    temp=new  int64_t*[k];
   for(int i=0;i<k;i++)
   temp[i]=new int64_t[k];

   for(int i=0;i<k;i++)
   cin>>mat[0][i],temp[0][i]=mat[0][i];

   for(int i=1;i<k;i++)
   for(int j=0;j<k;j++)
   {
       if(i-j==1)
       mat[i][j]=temp[i][j]=1;
       else
       mat[i][j]=temp[i][j]=0;

   }
   
   

   int n;cin>>n;
   if(n<=k)
   cout<<f[n-1]<<"\n";
   else{
       power(mat,n-k,k);
       int64_t ans=0;  
       for(int i=0;i<k;i++)
       {
           ans=(ans+(f[k-i-1]*mat[0][i])%MOD)%MOD;
         
       }
       cout<<ans<<"\n";
   }
}
int main()
 {
	ios_base::sync_with_stdio(false);
          cin.tie(NULL);

	#ifndef ONLINE_JUDGE
	freopen("./../input.txt", "r", stdin);
	freopen("./../output.txt", "w", stdout);
	#endif
    int t;cin>>t;
    while(t--)
	solve();
    
	return 0;
}
/*

 
SEQ - Recursive Sequence
#recursion
Sequence (ai) of natural numbers is defined as follows:

   ai = bi (for i <= k)
   ai = c1ai-1 + c2ai-2 + ... + ckai-k (for i > k)

where bj and cj are given natural numbers for 1<=j<=k. Your task is to compute an for given n and output it modulo 109.

Input
On the first row there is the number C of test cases (equal to about 1000).
Each test contains four lines:

k - number of elements of (c) and (b) (1 <= k <= 10)
b1,...,bk - k natural numbers where 0 <= bj <= 109 separated by spaces
c1,...,ck - k natural numbers where 0 <= cj <= 109 separated by spaces
n - natural number (1 <= n <= 109)

Output
Exactly C lines, one for each test case: an modulo 109

Example
Input:
3 
3 
5 8 2 
32 54 6 
2 
3 
1 2 3 
4 5 6 
6 
3 
24 354 6 
56 57 465 
98765432

Output:
8 
714 
257599514



*/