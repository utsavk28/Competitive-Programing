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
        ll i,j,k=INT_MAX,n,m;
        cin>>n;
        string s;
        cin>>s;

        for(char c='a';c<='z';c++) {
            i = 0,j = n-1;
            ll count = 0;
            bool flag=true;
            while(i<=j) {
                if(s[i] == s[j]) {
                    i++,j--;
                }
                else if(s[i] == c) {
                    i++;
                    count++;
                }
                else if(s[j] == c) {
                     j--;
                     count++;
                }
                else {
                    flag = false;
                    break;
                }
            }
            
            if(flag) {
                k = min(k,count);
            }
        }
        
        if(k == INT_MAX) {
            cout<<-1<<endl;
        }
        else {
            cout<<k<<endl;
        }
        
        // cout<<"Case #"<<cs<<": ";
        
    }
	return 0;
}
