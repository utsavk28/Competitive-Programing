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
    
    ll n,q,i,j,k,ans=0;
    cin>>n>>q;
    vector<ll> v(n);
    map<ll,ll> mp;
    for(i=0;i<n;i++) {
        cin>>v[i];
        ans += v[i];
        mp[i+1] = v[i];
    }
    
    bool flag = false;
    ll prev = -1;
    while(q--) {
        ll a,b,c;
        cin>>a;
        if(a == 1) {
            cin>>b>>c;
            
            if(flag) {
                if(mp[b]) {
                    ans += c;
                    ans -= mp[b];
                }
                else {
                    ans += c;
                    ans -= prev;
                }
            }
            else {
                ans += c;
                ans -= mp[b];
            }
            mp[b] = c;
        }
        else {
            cin>>c;
            prev = c;
            ans = c*n;
            flag = true;
            mp.clear();
        }
        cout<<ans<<endl;
    }
    
	return 0;
}
