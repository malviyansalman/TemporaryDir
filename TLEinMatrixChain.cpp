/*https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication/0*/
#include <bits/stdc++.h>
using namespace std;
int fun(int arr[],int i,int j);
int fun2(int arr[],int ,int j);
int memo[100][100];
int maxtrixMultilplication(int arr[],int i,int j)
{
    memset(memo,-1,sizeof(memo));
    return fun(arr,i,j);
}
int fun(int arr[],int i,int j)
{
    if(i==j)
    return 0;
    if(memo[i][j]!=-1)
    return memo[i][j];
     int inf=INT_MAX;
     for(int k=i;k<j;k++)
         inf=min(inf,fun(arr,i,k)+fun(arr,k+1,j)+arr[i-1]*arr[k]*arr[j]); //modified
    return memo[i][j] = inf;
}
int fun2(int arr[],int i,int j)
{
    if(i==j)
    return 0;
    int inf=INT_MAX;
    for(int k=i;k<j;k++)
        inf=min(inf,fun2(arr,i,k)+fun2(arr,k+1,j)+arr[i-1]*arr[k]*arr[j]);
    return inf;
}
int main() {
    int t;
    std::cin >> t;
    for(int i=0;i<t;i++)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int j=0;j<n;j++)
        cin>>arr[j];
        std::cout << maxtrixMultilplication(arr,1,n-1) << std::endl;
    }
	return 0;
}
/*

this was the earlier approach i was tryig to get rid of making global memory 
but as for now i am not able to do so the modification was done by declaring a global memory array

#include <bits/stdc++.h>
using namespace std;
//int fun(int arr[],int i,int j);
// int fun2(int arr[],int ,int j);
// int maxtrixMultilplication(int arr[],int i,int j)
// {
//     int memo[100][100]; 
//     memset(memo,-1,sizeof(memo));
//     return fun(memo,arr,i,j);
// }
// int fun(int memo[100][100],int arr[],int i,int j)
// {
//     if(i==j)
//     return 0;
//     if(memo[i][j]!=-1)
//     return memo[i][j];
//      int inf=INT_MAX;
//      for(int k=i;k<j;k++)
//      return (memo[i][j]=min(inf,fun(arr,i,k)+fun(arr,k+1,j)+arr[i-1]*arr[k]*arr[j]));
// }
int fun2(int arr[],int i,int j)
{
    if(i==j)
    return 0;
        int inf=INT_MAX;
        for(int k=i;k<j;k++)
        inf=min(inf,fun2(arr,i,k)+fun2(arr,k+1,j)+arr[i-1]*arr[k]*arr[j]);
        return inf;
}
int main() {
    int t;
    std::cin >> t;
    for(int i=0;i<t;i++)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int j=0;j<n;j++)
        cin>>arr[j];
        std::cout << fun2(arr,1,n-1) << std::endl;
    }
	return 0;
}

//https://practice.geeksforgeeks.org/problems/padovan-sequence/0
#include <bits/stdc++.h>
using namespace std;
#define m 1000000007
int memory[200];
int fun(int i)
{
    if(i==1|i==0|i==2)
    return 1;
    else if(memory[i]!=0)
    return memory[i];
    else return (memory[i]=(fun(i-2)%m+fun(i-3)%m)%m);
}
int main() {
	//code
	int T;
	cin>>T;
	//int memory[200];
// 	memory[0]=memory[1]=memory[2]=1;
// 	for(int i=3;i<=201;i++)
// 	memory[i]=(memory[i-2]%m+memory[i-3]%m)%m;
    memset(memory,0,sizeof(memory));
	for(int t=0;t<T;t++)
	{
	    
	    int n;
	    cin>>n;
	    cout<<fun(n)<<endl;
	}
	return 0;
}


*/

//https://practice.geeksforgeeks.org/problems/number-of-unique-paths/0
#include <bits/stdc++.h>
using namespace std;
int arr[16][16];
int fun(int i,int j)
{
    if(i==0 || j==0)
    return 1;
    else if(arr[i][j]!=-1)
    return arr[i][j];
    else return (arr[i][j]=fun(i-1,j)+fun(i,j-1));
}
int main() {
	//code
	int T;
	cin>>T;
	memset(arr,-1,sizeof(arr));
	for(int t=0;t<T;t++)
	{
	    int m,n;
	    cin>>m>>n;
	    cout<<fun(m-1,n-1)<<endl;
	}
	return 0;
}
