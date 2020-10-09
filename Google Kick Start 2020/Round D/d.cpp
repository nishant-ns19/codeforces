/*
	Nishant Singh
	nishant.ns19
*/
#include <bits/stdc++.h>
#include <functional> 
#include <iostream> 
// ******** Big Integer ********
// #include <boost/multiprecision/cpp_int.hpp>
// using namespace boost::multiprecision;
// #define ll1024  int1024_t
// ******** Big Integer ********
// ******** Using PBDS ********
// #include <ext/pb_ds/assoc_container.hpp> // Common file 
// #include <ext/pb_ds/tree_policy.hpp> 
// using namespace __gnu_pbds; 
// #define ook order_of_key    //count of strictly smaller elements
// #define fbo find_by_order   //find element at an index 
// ******** Using PBDS ********
using namespace std;
#define ll long long
#define ld long double
#define pll pair<long long,long long>
#define pii pair<int,int>
#define vll vector<ll>
#define vec vector
#define setcount(x) __builtin_popcountll(x)
#define f first
#define s second
#define mp make_pair
#define REP(i,n) for(ll i=0;i<(n);i++)
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define REV(i,a,b) for(ll i=(a);i>=(b);i--)
#define pb push_back
#define in insert
#define init(x,a) memset(x,a,sizeof(x))
#define all(c) c.begin(),c.end()
#define pq priority_queue
#define ffl fflush(stdout)
#define mset multiset
#define out(x) cout<<#x<<" = "<<" "<<x<<"\n";
#define ub upper_bound
#define lb lower_bound 
#define ln "\n"
#define Y "YES"
#define N "NO"
ll const mod=1e9 + 7;
ll const inf=2e18;
// ******** Using PBDS ********
// typedef tree<long long, null_type, less<long long>, rb_tree_tag, 
//              tree_order_statistics_node_update> 
//                 os; 
// ******** Using PBDS ********
inline ll add(ll a,ll b) 
{ 
	return (a%mod + b%mod + mod)%mod; 
}
inline ll mul(ll a,ll b) 
{ 
	return (a%mod * b%mod + mod)%mod; 
}
inline ll sub(ll a,ll b) 
{ 
	return (a%mod - b%mod + mod)%mod; 
}
ll gcd(ll a,ll b)
{
	if (b == 0) 
		return a; 
	return gcd(b, a % b);  
}
ll modexp(ll x, ll n){
	if(n==0){
		return 1;
	}
	else if(n&1){
		return (modexp((x*x)%mod, n/2)%mod * x%mod)%mod;
	}
	else{
		return (modexp((x*x)%mod, n/2)%mod);
	}
}
ll modinv(ll n)
{
	return modexp(n,mod-2);
}
// ******** GLOBAL VARIABLES ********
// ******** GLOBAL VARIABLES ********
void solve(){
	ll n,q;
	cin>>n>>q;
	ll a[n];
	REP(i,n-1)
	{
		cin>>a[i];
	}
	ll ans[q];
	REP(i,q)
	{
		ll id,k;
		cin>>id>>k;
		if(id==(n))
		{
			ans[i]=n-k;
			ans[i]++;
			cout<<ans[i]<<" ";
		}
		else if(id==1)
		{
			ans[i]=k;
			cout<<k<<" ";
		}
		else if(k==1)
		{
			cout<<id<<" ";
			ans[i]=id;
		}
		else
		{
			ll last=id-1;
			id--;
			ll l=id-1;
			ll r=id;
			ll cnt=k-1;
			while(cnt && r<(n-1) && l>=0)
			{
				if(a[l]<a[r])
				{
					last=l;
					l--;
				}
				else
				{
					r++;
					last=r;
				}
				cnt--;
			}
			while(cnt && (r <n-1)){
				r++;
				last=r;
				cnt--;
			}
			while(cnt && (l >= 0)){
				last=l;
				l--;
				cnt--;
			}
			cout<<last+1<<" ";
		}
	}
	cout<<ln;
}  
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll T=1;
	cin>>T; 	
	for(int t=1;t<=T;t++)
	{
		cout<<"Case #"<<t<<": ";
		solve();
	}
	return 0;
}