/*********************************************************************
 *-------------------------------------------------------------------*
 *                                                                   *
 *   Life is just a life. Lead it, Feel it & Enjoy It Properly.      *
 *   Nothing is impossible. Just believe in yourself & Almighty.     *
 *                                                                   *
 *-------------------------------------------------------------------*
 *********************************************************************/

#include<bits/stdc++.h>
using namespace std;


///######################### Typedef Section #########################

typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;

///###################################################################

///######################### Input Section ###########################

#define si1(x)        scanf("%d",&x)
#define si2(x,y)      scanf("%d %d", &x, &y)
#define si3(x,y,z)    scanf("%d %d %d", &x, &y, &z)

#define sd1(x)        scanf("%lf",&x)
#define sd2(x,y)      scanf("%lf %lf", &x, &y)
#define sd3(x,y,z)    scanf("%lf %lf %lf", &x, &y, &z)

#define sli1(x)       scanf("%lld",&x)
#define sli2(x,y)     scanf("%lld %lld", &x, &y)
#define sli3(x,y,z)   scanf("%lld %lld %lld", &x, &y, &z)

///###################################################################

///######################### Define Section ##########################

#define nl            "\n"
#define pi            acos(-1.0)
#define mem(arr,val)  memset(arr,val,sizeof(arr))
#define pb            push_back
#define mp            make_pair
#define pr            pair<ll,ll>
#define mod           1000000007

///###################################################################
///###################################################################
/// 1. (0-1)Knapsack
///    a. Knapsack
///    b. Subset Sum
///    c. Count of Subset Sum
///    d. Equal Sum Partition
///    e. Minimum Subset Sum Difference
///    f. Count Minimum Subset Sum Difference
///    g. Target Sum
/// 2. Unbounded Knapsack
///    a.Rod Cutting
///    b.Coin Change I
///    c.Coin Change II
/// 3. Longest Common Sub-sequence
///    a.LCS
///    b.Longest Common Sub-string
///    c.Print Longest Common Sub-sequence
///    d.Shortest Common Supper-sequence
///    e.Print Shortest Common Supper-sequence
///    f.Minimum number of insertion and deletion
///    g.Print Minimum number of insertion and deletion
///    h.Longest Palindromic Sub-sequence
///    i.Minimum number of deletion to make a string palindrome
///    j.Minimum number of insertion to make a string palindrome
///    k.Longest Repeating Sub-sequence
///######################### Coding ##################################

///$$$$$$$$$$$$$$$$$$$$$$$$$ Knapsack $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
#define sz 1000
ll tab[105][10005];

ll Knapsack_Rec(ll wt[], ll val[], ll w, ll n)
{
    if(n==0 || w==0) return 0;
    if(tab[n][w]!=-1) return tab[n][w];

    if(wt[n-1]<=w) return tab[n][w] = max(val[n-1] + Knapsack_Rec(wt,val,w-wt[n-1],n-1), Knapsack_Rec(wt,val,w,n-1));
    else if(wt[n-1]>w) return tab[n][w] = Knapsack_Rec(wt,val,w,n-1);

    return tab[n][w];
}

ll Knapsack_Top(ll wt[], ll val[], ll w, ll n)
{
    for(ll i=0; i<n+1; i++)
        for(ll j=0; j<w+1; j++)
           if(i==0 || j==0) tab[i][j] = 0;

    for(ll i=1; i<n+1; i++)
        for(ll j=1; j<w+1; j++){
            if(wt[i-1]<=j) tab[i][j] = max(val[i-1]+tab[i-1][j-wt[i-1]], tab[i-1][j]);
            else if(wt[i-1]>j) tab[i][j] = tab[i-1][j];
        }

    return tab[n][w];
}

///$$$$$$$$$$$$$$$$$$$$$$$$$ Subset Sum $$$$$$$$$$$$$$$$$$$$$$$$$$$$$

bool tab[1003][1003];

bool SubsetSum(ll wt[], ll n, ll k)
{
    for(ll i=0; i<n+1; i++){
        for(ll j=0; j<k+1; j++){
            if(i==0) tab[i][j] = false;
            if(j==0) tab[i][j] = true;
        }
    }

    for(ll i=1; i<n+1; i++){
        for(ll j=1; j<k+1; j++){
            if(wt[i-1]<=j) tab[i][j] = tab[i-1][j-wt[i-1]] || tab[i-1][j];
            else tab[i][j] = tab[i-1][j];
        }
    }
    return tab[n][k];
}

///$$$$$$$$$$$$$$$$$$$$$ Equal Sum Partition $$$$$$$$$$$$$$$$$$$$$$$

bool EqualSumPartition(ll wt[], ll n)
{
    ll sum = 0;
    for(ll i=0; i<n; i++) sum+=wt[i];

    if(sum%2==0) return SubsetSum(wt,n,sum/2);
    else return false;
}
///$$$$$$$$$$$$$$$$$$ Minimum Subset Sum Difference $$$$$$$$$$$$$$$$

int Min_Sub_Sum_Difference(ll wt[], ll n)
{
    ll total = 0;
    for(ll i=0; i<n; i++) total += wt[i];
    ///cin >> diff;  count of subset sum given difference
    ///ll sum = (diff+total)/2;
    ///SubsetSum(wt,n,sum);
    SubsetSum(wt,n,total);

    ll ans = INT_MAX;
    for(ll i=1; i<=(total/2)+1; i++)
        if(tab[n][i]) ans = min(ans,abs(total-2*i));

    return ans;
}

///$$$$$$$$$$$$$$ Unbounded Knapsack/ Rod cutting $$$$$$$$$$$$$$$$$$$$

ll UndoundedKnapsack(ll wt[], ll val[], ll w, ll n)
{
    for(ll i=0; i<n+1; i++)
        for(ll j=0; j<w+1; j++)
           if(i==0 || j==0) tab[i][j] = 0;

    for(ll i=1; i<n+1; i++)
        for(ll j=1; j<w+1; j++){
            if(wt[i-1]<=j) tab[i][j] = max(val[i-1]+tab[i][j-wt[i-1]], tab[i-1][j]);
            else if(wt[i-1]>j) tab[i][j] = tab[i-1][j];
        }

    return tab[n][w];
}

///$$$$$$$$$$$$$$$$$$$$$$$$$$ Coin Change I $$$$$$$$$$$$$$$$$$$$


ll CoinChangeI(ll wt[], ll n, ll k)
{
    for(ll i=0; i<n+1; i++){
        for(ll j=0; j<k+1; j++){
            if(i==0) tab[i][j] = 0;
            if(j==0) tab[i][j] = 1;
        }
    }

    for(ll i=1; i<n+1; i++){
        for(ll j=1; j<k+1; j++){
            if(wt[i-1]<=j) tab[i][j] = tab[i][j-wt[i-1]] + tab[i-1][j];
            else tab[i][j] = tab[i-1][j];
        }
    }
    return tab[n][k];
}

///$$$$$$$$$$$$$$$$$$$$$$$$$$ Coin Change II $$$$$$$$$$$$$$$$$$$$


ll CoinChangeII(ll wt[], ll n, ll k)
{
    for(ll i=0; i<n+1; i++){
        for(ll j=0; j<k+1; j++){
            if(j==0) tab[i][j] = INT_MAX-1;
            if(i==0) tab[i][j] = 0;
        }
    }

    for(ll j=1; j<=k; j++){
        if(j%wt[0]==0) tab[0][j] = j/wt[0];
        else tab[0][j] = INT_MAX-1;
    }

    for(ll i=1; i<n+1; i++){
        for(ll j=1; j<k+1; j++){
            if(wt[i-1]<=j) tab[i][j] = min(1 + tab[i][j-wt[i-1]], tab[i-1][j]);
            else tab[i][j] = tab[i-1][j];
        }
    }
    return tab[n][k];
}

//###################################################################


///$$$$$$$$$$$$$$$$$$$$$$ Longest Common Sub-sequence $$$$$$$$$$$$$$$

ll LCS_Rec(string s1, string s2, ll n, ll m){
    if(n==0 || m==0) return 0;

    if(tab[n][m]!=-1) return tab[n][m];

    if(s1[n-1]==s2[m-1]) return tab[n][m] = 1+LCS_Rec(s1,s2,n-1,m-1);
    else return tab[n][m] = max(LCS_Rec(s1,s2,n-1,m),LCS_Rec(s1,s2,n,m-1));

    return tab[n][m];
}

ll LCS_Top(string s1, string s2, ll n, ll m){

    for(ll i=0; i<n+1; i++)
        for(ll j=0; j<m+1; j++)
            if(i==0 || j==0) tab[i][j] = 0;

    for(ll i=1; i<n+1; i++){
        for(ll j=1; j<m+1; j++){
            if(s1[i-1]==s2[j-1]) tab[i][j] = 1+tab[i-1][j-1];
            else tab[i][j] = max(tab[i][j-1],tab[i-1][j]);
        }
    }

    return tab[n][m];
}

string LCS_Print(string s1, string s2, ll n, ll m){

    LCS_Top(s1,s2,n,m);

    ll i = n, j = m;
    string s;
    while(i>0 && j>0){
        if(s1[i-1]==s2[j-1]){
            s.pb(s1[i-1]);
            i--;
            j--;
        }
        else{
            if(tab[i][j-1]>tab[i-1][j]) j--;
            else i--;
        }
    }
    reverse(s.begin(),s.end());
    return s;
}

//###################################################################

///$$$$$$$$$$$$$$$$$$$$$$ Longest Common Sub-string $$$$$$$$$$$$$$$

ll LCSS(string s1, string s2, ll n, ll m){

    for(ll i=0; i<n+1; i++)
        for(ll j=0; j<m+1; j++)
            if(i==0 || j==0) tab[i][j] = 0;

    for(ll i=1; i<n+1; i++){
        for(ll j=1; j<m+1; j++){
            if(s1[i-1]==s2[j-1]) tab[i][j] = 1+tab[i-1][j-1];
            else tab[i][j] = 0;
        }
    }

    return tab[n][m];
}

///$$$$$$$$$$$$$$$$$$$$$$ Longest Common Sub-string $$$$$$$$$$$$$$$

ll SCS(string s1, string s2, ll n, ll m){
    return (n+m)-LCS_Top(s1,s2,n,m);
}

string SCS(string s1, string s2, ll n, ll m){
    LCS_Top(s1,s2,n,m);

    ll i = n, j = m;
    string s;
    while(i>0 && j>0){
        if(s1[i-1]==s2[j-1]){
            s.pb(s1[i-1]);
            i--;
            j--;
        }
        else{
            if(tab[i][j-1]>tab[i-1][j]){
                s.pb(s2[j-1]);
                j--;
            }
            else{
                s.pb(s1[i-1]);
                i--;
            }
        }
    }

    while(i>0){
        s.pb(s1[i-1]);
        i--;
    }
    while(j>0){
        s.pb(s2[j-1]);
        j--;
    }
    reverse(s.begin(),s.end());
    return s;
}

ll MNID(string s1, string s2, ll n, ll m){
    ll num = LCS_Top(s1,s2,n,m);

    ll ins = n - num;
    ll del = m - num;
}

ll LPS(string s1, ll n){
    string s2 = s1;
    reverse(s2.begin(),s2.end());
    return LCS_Top(s1,s2,n,n);
}

ll LRS(string s1, ll n){
    string s2 = s1;

    for(ll i=0; i<n+1; i++)
        for(ll j=0; j<n+1; j++)
            if(i==0 || j==0) tab[i][j] = 0;

    for(ll i=1; i<n+1; i++){
        for(ll j=1; j<n+1; j++){
            if(s1[i-1]==s2[j-1] && i!=j) tab[i][j] = 1+tab[i-1][j-1];
            else tab[i][j] = max(tab[i][j-1],tab[i-1][j]);
        }
    }

    return tab[n][m];
}
//###################################################################
///$$$$$$$$$$$$$$$$$$$$$$ Matrix chain Multiplication $$$$$$$$$$$$$$$

ll MCM(ll ar[], ll L, ll R)
{

}

//###################################################################


int main()
{
    ll n, w;
    sli2(n,w);

    mem(tab,-1);
    ll val[n],wt[n];
    for(ll i=0; i<n; i++) sli2(val[i],wt[i]);

    cout << Knapsack_Top(wt,val,w,n) << nl;

    return 0;
}
