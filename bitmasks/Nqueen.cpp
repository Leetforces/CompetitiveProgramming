
// https://practice.geeksforgeeks.org/problems/n-queen-problem/0


#include<bits/stdc++.h>
using namespace std;

int MAX_N=1,n;
bool mat[11][11],flag=false;
int getColumn(int temp)
{
    // find the set bit position
    int ans=0;
    while(temp>0)
    {
        ans++;
        temp=temp>>1;
    }
    return ans;
}
void Nqueen(int row,int rowMask,int leftDig,int rightDig)
{
    if(rowMask==MAX_N) //same as if(row==n+1)
    {
        
        // print
        cout<<"[";
        for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        if(mat[i][j])
        cout<<j<<" ";
       
        cout<<"] ";
        flag=true;
        return ;
    }
    int unsafebits=rowMask|leftDig|rightDig;
    int safe= ~unsafebits;
     
     // removing extra bits 
     safe=MAX_N&safe;
    
    while(safe)
    {
        //find last set bit
        int mask=(safe&(-safe));
        
        // find the column no ie:position of setbit mask
        int column=getColumn(mask);
        
        // make it visited
        mat[row][column]=true;
        
        //removing last set bit
        safe=safe-mask;  // safe= safe & (safe-1);
        
        //exploring next row
        Nqueen(row+1,rowMask|mask,(leftDig|mask)<<1,(rightDig|mask)>>1);
        
        // make it unvisited
        mat[row][column]=false;
    }
   
}
void solve()
{
    // take input nxn matrix
    cin>>n;
    
    // maximum  in no of bits=bitscount(n)
    MAX_N=(1<<n)-1;
    
     /*       / | \
             /  |  \
          left  row right 
          diag  mask diag
    */
    // initially all are 0 (00000000)
    int rowMask,leftDig=0,rightDig=0,row=1;
    
    // for check atleast one answer 
    flag=false;
    
    // intialized matrix as unvisited
    for(int i=1;i<=10;i++)
    for(int j=1;j<=10;j++)
    mat[i][j]=false;
    
    // call Nqueen function
    Nqueen(row,rowMask,leftDig,rightDig);
    
    //check atleast one answer or not
    if(flag==false)
    cout<<"-1";
    cout<<"\n";
}
/*
bool mat[11][11];
bool flag;
bool isPossible(int row,int column,int n)
{
    for(int i=row;i>=1;i--)
    {
        if(mat[i][column])
        return false;
    }
    for(int i=row,j=column;i>=1&&j>=1;i--,j--)
    if(mat[i][j])
    return false;
    
    for(int i=row,j=column;i>=1&&j<=n;i--,j++)
    if(mat[i][j])
    return false;
    
    return true;
}
void Nqueen(int row,int n)
{
    if(row==n+1)
    {
        // print the possible path
        cout<<"[";
        for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        if(mat[i][j])
        cout<<j<<" ";
        
        cout<<"] ";
        flag=true;
    }
    else{
         // check for each column to current row
          for(int column=1;column<=n;column++)
          {
              if(isPossible(row,column,n))
              {
                  // make it visited
                  mat[row][column]=true;

                  // calling to next row
                  Nqueen(row+1,n);

                  //make it unvisited
                  mat[row][column]=false;
              }
          }
          
          
    }
    
}
void solve()
{
    // input by user
    int n;cin>>n;

    // mark all matrix is unvisited
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    mat[i][j]=false;

    // for checking it is atleast one possible answer
    flag=false;
    
    // call to Nqueen function
    Nqueen(1,n);
    
    // if not any possible path then print "-1" according to question
     if(flag==false)
     cout<<"-1";
     cout<<"\n";
}
*/
int main()
 {
	ios_base::sync_with_stdio(false);
         cin.tie(NULL);

	#ifndef ONLINE_JUDGE
	freopen("./../input.txt", "r", stdin);
	freopen("./../output.txt", "w", stdout);
	#endif
    
    int testcase;
    cin>>testcase;
    while(testcase--)
	solve();
    
	return 0;
}