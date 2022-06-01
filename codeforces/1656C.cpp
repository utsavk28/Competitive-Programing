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
        ll i,j,k,n,m;
        cin>>n;
        bool one = false,zero = false;
        vector<ll> v(n);
        for(i=0;i<n;i++) {
            cin>>v[i];
            if(v[i] == 1) one = true;
            if(v[i] == 0) zero = true;
        }
        if(one) {
            if(zero) cout<<"NO\n";
            else {
                unordered_map<ll,ll> mp;
                for(auto it:v) {
                    mp[it]=1;
                }
                bool ans = true;
                for(auto it:v) {
                    if(mp[it-1]) {
                        ans = false;
                        break;
                    }
                }
                
                if(ans) cout<<"YES\n";
                else cout<<"NO\n";
            }
        }
        else {
            cout<<"YES\n";
        }

        
        // cout<<"Case #"<<cs<<": ";
        
    }
	return 0;
}
