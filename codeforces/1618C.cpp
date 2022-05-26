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
        ll gcd1 = 0,gcd2 = 0;
        
        for(i=0;i<n;i++) {
            cin>>v[i];
            if(i%2 == 0) {
                gcd1 = gcd(gcd1,v[i]);
            }   
            else {
                gcd2 = gcd(gcd2,v[i]);
            }
        }
        bool ans1 = true, ans2 = true;
        
        for(i=0;i<n;i++) {
            if(i%2 == 1) {
                if(v[i]%gcd1 == 0) ans1 = false;
            }
            else {
                if(v[i]%gcd2 == 0) ans2 = false;
            }
        }
        
        if(ans1) {
            cout<<gcd1<<endl;
        }
        else if(ans2) {
            cout<<gcd2<<endl;
        }
        else {
            cout<<0<<endl;
        }
        
        // cout<<"Case #"<<cs<<": ";
        
    }
	return 0;
}
