#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mod 1000000007

class Node {
    public:
    int val;
    Node *left,*right;
    Node(int x) {
        val = x;
        left = NULL;
        right = NULL;
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
        ll hc,dc,hm,dm;
        cin>>hc>>dc>>hm>>dm;
        ll k,w,a;
        cin>>k>>w>>a;
        ll i,j,n,m;
        bool flag = false;
        
        for(i=0;i<=k;i++) {
            n = i,m = k-i;
            if(ceil((1.0*hm)/(1.0*dc+w*n)) <= ceil((1.0*hc+m*a)/(1.0*dm))) flag = true;
            if(flag) break;
        }
        
        if(flag) cout<<"YES\n";
        else cout<<"NO\n";
        
        // cout<<"Case #"<<cs<<": ";
        
    }
	return 0;
}
