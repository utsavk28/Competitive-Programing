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
        ll n,a,b,i,j,k;
        cin>>n>>a>>b;
        bool ans = false;
        vector<int> v(n);
        if(abs(a-b) <= 1 && a+b <=n-2) ans=true;
        
        if(ans) {
            if(a == b) {
                a++,b++;
                // cout<<10*ans<<" ";
                for(i=1;i<=a;i++) v[2*(i-1)] = i;
                for(i=0;i<a;i++) v[2*i+1]=i+a+1;
                for(i=2*a+1;i<=n;i++) v[i-1]=i;
            }// 
            else {
                // cout<<11*ans<<" ";
                k = max(a,b);
                for(i=1;i<=k;i++) v[2*(i-1)] = i;
                for(i=0;i<k-1;i++) v[2*i+1]=i+k+1;
                for(i=2*k;i<=n;i++) v[i-1]=n-(i-2*k);
            }
            
            if(b>a) for(i=0;i<n;i++) v[i] = n-v[i]+1;
        
            for(auto it:v) cout<<it<<" ";
            cout<<endl;
            
        }
        else {
            cout<<-1<<endl;
        }
        // cout<<"Case #"<<cs<<": ";
        
    }
	return 0;
}
