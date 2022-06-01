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
        ll n,m,i,j,k;
        cin>>n>>m;
        bool flag = true;
        vector<ll> ans;
        while(m || n) {
            ll a = m%10;
            ll b = n%10;
            m /= 10, n /= 10;
            if(a>=b) {
                ans.push_back(a-b);
            }
            else {
                a = 10*(m%10) + a;
                m /= 10;
                if(a >= b && (a-b) < 10) {
                    ans.push_back(a-b);
                }
                else {
                    flag = false;
                    break;
                }
            }
        }
        
        if(flag) {
            reverse(ans.begin(),ans.end());
            flag = false;
            for(auto it:ans) {
                if(it != 0) flag = true;
                if(flag)
                cout<<it<<"";
            }
            cout<<endl;
        }
        else {
            cout<<-1<<endl;
        }
        
        // cout<<"Case #"<<cs<<": ";
        
    }
	return 0;
}
