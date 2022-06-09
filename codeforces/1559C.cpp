#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007

class Node {
    public:
    ll val;
    vector<Node*> adj;
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
        vector<ll> v(n);
        k = -1;
        for(i=0;i<n;i++) {
            cin>>v[i];
            
            if(i > 0 && v[i-1] == 0 && v[i] == 1) k = i;
            if(i == n-1 && v[i] == 0) k = i+1;
            if(i == 0 && v[i] == 1) k = 0;
        }
        
        if(k == -1) cout<<-1<<endl;
        else if(k == 0) {
            cout<<n+1<<" ";
            for(i=1;i<=n;i++) cout<<i<<" ";
            cout<<endl;
        }
        else if(k == n) {
            for(i=1;i<=n+1;i++) cout<<i<<" ";
            cout<<endl;
        }
        else {
            for(i=1;i<=k;i++) cout<<i<<" ";
            cout<<n+1<<" ";
            for(i=k+1;i<=n;i++) cout<<i<<" ";
            cout<<endl;
        }
        
        // cout<<"Case #"<<cs<<": ";
        
    }
	return 0;
}
