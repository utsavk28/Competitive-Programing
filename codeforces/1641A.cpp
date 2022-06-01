#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007

class Node {
    public:
    ll val;
    vector<Node*> adj;
    Node *left,*right;
    Node(int x) {
        val = x;
        adj.clear();
    }
};

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

ll to_number(string s) {
    ll ans = 0;
    int n = s.size(),i;
    for(i=0;i<n;i++) {
        ans = ans*10 + (s[i]-'0');
    }
    
    return ans;
}

ll power(ll x, ll y, ll p)
{
    ll res = 1;     
    x = x % p; 
    if (x == 0) return 0; 
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
 
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    
    int t,cs=0;
    cin>>t;
    while(t--) {
        cs++;
        ll n,x,i,j,k;
        cin>>n>>x;
        vector<ll> v(n);
        for(i=0;i<n;i++) {
            cin>>v[i];
        }
        sort(v.begin(),v.end());
        map<ll,ll> mp;
        ll ans = 0;
        for(i=n-1;i>=0;i--) {
            // cout<<v[i]<<" ";
            if(mp[v[i]]) {
                mp[v[i]]--;
            }
            else if(v[i]%x == 0) {
                mp[v[i]/x]++;
            }
            else {
                ans++;
            }
            // cout<<ans<<" ";
        }
        
        for(auto it:mp) ans+=it.second;
        cout<<ans<<endl;
        
        // cout<<"Case #"<<cs<<": ";
        
    }
	return 0;
}
