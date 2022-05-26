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
        ll i,j,k,n;
        cin>>n;
        vector<ll> v(n);
        for(i=0;i<n;i++) cin>>v[i];
        sort(v.begin(),v.end());
        
        vector<ll> vis(n,0);
        bool ans = true;
        for(i=0;i<n;i++) {
            if(v[i] >= 1 && v[i] <= n && vis[v[i]-1] == 0) {
                vis[v[i]-1] = 1;
            }
            else {
                k = v[i];
                bool flag=false;
                while(k) {
                    if(k >= 1 && k <= n && vis[k-1] == 0) {
                        vis[k-1] = 1;
                        flag = true;
                        break;
                    }
                    k /= 2;
                }
                
                if(flag == false) {
                    ans = false;
                }
            }
        }
        
        if(ans) {
            cout<<"YES\n";
        }
        else {
            cout<<"NO\n";
        }
        
        // cout<<"Case #"<<cs<<": ";
        
    }
	return 0;
}
