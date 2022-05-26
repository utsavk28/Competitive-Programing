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
        vector<bool> v(n,false);
        unordered_map<ll,vector<vector<ll>>> mp;
        for(i=0;i<n;i++) {
            vector<ll> temp(2);
            cin>>temp[0]>>temp[1];
            mp[temp[1]-temp[0]].push_back(temp);
        }
        
        for(i=0;i<=n;i++) {
            for(auto it:mp[i]) {
                for(j=it[0];j<=it[1];j++) {
                    if(v[j] == false) {
                        v[j] = true;
                        cout<<it[0]<<" "<<it[1]<<" "<<j<<endl;
                        break;
                    }
                }
            }
        }
        // cout<<endl;
        // cout<<"Case #"<<cs<<": ";
        
    }
	return 0;
}
