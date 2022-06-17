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
        ll n,k,i,j;
        cin>>n>>k;
        vector<ll> v(n);
        ll ans=-1,sz=0,sum=0;
        j=0;
        for(i=0;i<=n;i++) {
            if(i != n) {
                cin>>v[i];
                sum += v[i];
                sz++;
            }
            
            if(sum == k) {
                ans = max(ans,sz);
            }
            
            while(sum > k) {
                sum -= v[j++];
                sz--;
            }
        }
        if(ans == -1) cout<<-1<<endl;
        else cout<<n-ans<<endl;
        // cout<<"Case #"<<cs<<": ";
        
    }
	return 0;
}
