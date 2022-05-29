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
    
    ll n,m,q,i,j,k;
    char c;
    cin>>n>>q;
    string s;
    cin>>s;
    ll ans = 0;
    for(i=0;i<n-2;i++) {
        if(s[i] == 'a' && s[i+1] == 'b' && s[i+2] == 'c') ans++; 
    }
    
    while(q--) {
        cin>>k>>c;
        k--;
        // if(s[k] != c) {
            if(s[k] == 'a' && k+2 < n && s[k+1] == 'b' && s[k+2] == 'c') ans--;
            if(s[k] == 'b' && k-1 >= 0 && k+1 < n && s[k-1] == 'a' && s[k+1] == 'c') ans--;
            if(s[k] == 'c' && k-2 >= 0 && s[k-1] == 'b' && s[k-2] == 'a') ans--;
            
            s[k] = c;
            if(s[k] == 'a' && k+2 < n && s[k+1] == 'b' && s[k+2] == 'c') ans++;
            if(s[k] == 'b' && k-1 >= 0 && k+1 < n && s[k-1] == 'a' && s[k+1] == 'c') ans++;
            if(s[k] == 'c' && k-2 >= 0 && s[k-1] == 'b' && s[k-2] == 'a') ans++;
        // } 
        // cout<<k<<" "<<c<<" ";
        // cout<<s<<" ";
        cout<<ans<<endl;
    }
    
	return 0;
}
