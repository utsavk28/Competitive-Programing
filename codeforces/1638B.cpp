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
        int i,j,k,n;
        cin>>n;
        vector<int> v(n);
        vector<int> odd,even;
        for(i=0;i<n;i++) {
            cin>>v[i];
            if(v[i]%2 == 0) {
                even.push_back(v[i]);
            }
            else {
                odd.push_back(v[i]);
            }
        }
        bool flag = true;
        n = even.size();
        for(i=0;i<n-1;i++) {
            if(even[i] > even[i+1]) flag = false;
        }
        n = odd.size();
        for(i=0;i<n-1;i++) {
            if(odd[i] > odd[i+1]) flag = false;
        }
        
        if(flag) cout<<"YES\n";
        else cout<<"NO\n";
    
        // cout<<"Case #"<<cs<<": ";
        
    }
	return 0;
}
