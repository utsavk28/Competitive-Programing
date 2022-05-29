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
        ll n,m,q,i,j,k;
        cin>>n;
        vector<ll> v(n);
        // vector<unordered_map<ll,ll>> ans;
        vector<vector<ll>> ans;
        unordered_map<ll,ll> mp;
        for(i=0;i<n;i++) {
            cin>>v[i];
            mp[v[i]]++;
        }

        // ans.push_back(mp);
        ans.push_back(v);
        
        vector<ll> prev = v, curr(n,-1);
        while(true) {
            mp.clear();
            for(i=0;i<n;i++) {
                mp[prev[i]]++;
            }
            for(i=0;i<n;i++) {
                curr[i] = mp[prev[i]];
            }
            if(prev == curr) break;
            // ans.push_back(mp);
            ans.push_back(curr);
            prev = curr;
        }
        
        // for(auto it)
        
        cin>>m;
        k = ans.size();
        // cout<<k<<"-\n";
        
        // for(i=0;i<k;i++) {
        //     for(auto it:ans[i]) {
        //         cout<<it.first<<" "<<it.second<<" |";
        //     }
        //     cout<<endl;
        // }
        
        while(m--) {
            cin>>i>>j;
            j = min(j,k-1);
            cout<<ans[j][i-1]<<endl;
        }
        
        
        // cout<<"Case #"<<cs<<": ";
        
    }
	return 0;
}
