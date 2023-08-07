
#include <bits/stdc++.h>
using namespace std;

//Author : " RVI : The TaxMan "

#define endl "\n"
#define int int64_t
#define span(a) begin(a), end(a)
#define ll long long
#define sortall(v)sort((v).begin(), (v).end())
#define SORT(arr, size)sort((arr), (arr) + (size))
#define print(v) for (const auto& x : v) {cout << x << " ";} cout<<endl;

const int mod = 1e9 + 7;
const int N = 1e5 + 10;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vector<int>>;

ll expo(ll a , ll b , ll m) { a = a % m ; ll res = 1; while (b > 0) {if (b & 1)res = res * a % m; a = a * a % m; b >>= 1;} return res;}
ll mminvPrime(ll a , ll b) {return expo(a, b - 2, b);}
ll mod_add(ll a , ll b , ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_sub(ll a , ll b , ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_mul(ll a , ll b , ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_div(ll a , ll b , ll m) {a = a % m ; b = b % m; return (mod_mul(a, mminvPrime(b, m), b) + m) % m;} //only for prime}

//compute hash
//(s[0]+s[1]*p+s[2]*p^2+s[3]*p^4)%mod;
//compute hash
vector<ll>hshPrefixes;
vector<ll>powers;
void calculateHashPrefixes(const string & s)
{
	int n = s.size();
	const int p = 50;
	hshPrefixes.clear();
	powers.resize(n, 1);
	//precompute p^k
	for (int i = 1; i < n; ++i)
	{
		powers[i] = (powers[i - 1] * p) % mod;
	}
	//precompute hash
	for (int i = 0 ; i < n ; i++)
	{
		int character = s[i] - 'a' + 1;
		if (i == 0)
			hshPrefixes.push_back(character);
		else
			hshPrefixes.push_back((hshPrefixes[i - 1] + character * powers[i]) % mod);
	}
}
ll substringHash(int l , int r)
{
	//ans = h[r]-h[l-1]/p^l;

	if (l == 0)return hshPrefixes[r];
	ll a = mod_sub(hshPrefixes[r] , hshPrefixes[l - 1] , mod);
	ll b = powers[l];
	ll modInverse = expo(b, mod - 2, mod);
	return (a * modInverse) % mod;
}
ll compute_hash(string const & s) {
	const int p = 50;
	ll hash_value = 0;
	ll p_pow = 1;
	for (char c : s) {
		hash_value = (hash_value + (c - 'a' + 1) * p_pow) % mod;
		p_pow = (p_pow * p) % mod;
	}
	return hash_value;
}
void solve()
{
	string s = "adcfadcf";
	calculateHashPrefixes(s) ;
	for (auto x : hshPrefixes)cout << x << " ";
	cout << endl;
	cout << compute_hash(s) << endl;
	cout << (substringHash(0, 3)) << endl;
	cout << (substringHash(4, 7)) << endl;
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
}
