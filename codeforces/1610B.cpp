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

bool check(vector<ll> &v,ll x,ll l,ll r) {
    while(l<=r) {
        if(v[l] == v[r]) {
            l++,r--;
        }
        else {
            if(v[l] == x) l++;
            else if(v[r] == x) r--;
            else return false;
        }
    }
    
    return true;
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    
    int t,cs=0;
    cin>>t;
    while(t--) {
        cs++;
        ll i,j,k,n,m=0;
        cin>>n;
        bool flag = true;
        vector<ll> v(n);
        for(i=0;i<n;i++) {
            cin>>v[i];
        }
        
        i = 0,j = n-1;
        while(i<j) {
            if(v[i] == v[j]) {
                i++,j--;
            }
            else {
                if(!check(v,v[i],i+1,j) && !check(v,v[j],i,j-1)) {
                    flag = false;
                }
                break;
            }
        }
        
        if(flag) cout<< "YES\n" ;
        else cout<<"NO\n";
        
        
        // cout<<"Case #"<<cs<<": ";
        
    }
	return 0;
}
