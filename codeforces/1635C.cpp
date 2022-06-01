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
        ll n,i,j,k;
        cin>>n;
        vector<ll> v(n);
        for(i=0;i<n;i++) cin>>v[i];
        bool ans = true;
        if(v[n-1] >= 0) {
            if(v[n-1] < v[n-2]) {
                ans = false;
            }
        }
        else {
            ans = false;
        }
        
        if(ans) {
            cout<<n-2<<endl;
            for(i=n-2;i>=1;i--) {
                cout<<i<<" "<<i+1<<" "<<n<<endl;
            }
        }
        else {
            ans = true;
            for(i=0;i<n-1;i++) {
                if(v[i] > v[i+1]) ans = false;
            }
            if(ans) {
                cout<<0<<endl;
            }
            else {
                cout<<-1<<endl;
            }
        }
        
        // cout<<"Case #"<<cs<<": ";
        
    }
	return 0;
}
