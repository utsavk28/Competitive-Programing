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

bool check(ll k,vector<ll> &a,ll h) {
    ll i,j,n=a.size();
    ll count = 0,maxi=0;
    for(i=0;i<n;i++) {
        count += k;
        if(maxi >= a[i]) count -= (maxi-a[i]+1);
        maxi = max(maxi,a[i]+k-1);
    }
    // cout<<count<<" ";
    return count >= h;
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    
    int t,cs=0;
    cin>>t;
    while(t--) {
        cs++;
        ll n,m,i,j,k;
        cin>>n>>m;
        vector<ll> v(n);
        for(i=0;i<n;i++) cin>>v[i];
        
        ll ans=-1,l=1,r=m;
        while(l<=r) {
            ll mid = (l+r)/2;
            // cout<<mid<<"->";
            bool flag = check(mid,v,m);

            if(flag) {
                ans = mid;
                r = mid-1;
            }
            else {
                l = mid+1;
            }
        }
        cout<<ans<<endl;
        // cout<<"Case #"<<cs<<": ";
        
    }
	return 0;
}
