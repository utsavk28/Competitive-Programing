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
        string s;
        cin>>s;
        ll i,j,n=s.size();
        bool flag = false;
        for(i=0;i<n-1;i++) {
            ll x = s[i]-'0', y =s[i+1]-'0';
            if(x+y >= 10) {
                flag = true;
                break;
            }
        }
        
        if(flag) {
            flag = true;
            string ans = "";
            for(i=n-1;i>0;i--) {
                ll x = s[i]-'0';
                ll y = s[i-1]-'0';
                if(flag && x+y >= 10) {
                    flag = false;
                    string temp = to_string(x+y);
                    // cout<<x+y;
                    s[i] = temp[1];
                    s[i-1] = temp[0];
                    i--;
                }

            }
            // reverse(ans.begin(),ans.end());
            cout<<s<<endl;
        }
        else {
            ll x = s[0]-'0';
            ll y = s[1]-'0';
            cout<<x+y;
            for(i=2;i<n;i++) {
                cout<<s[i];
            }
            cout<<endl;
        }
        
        // cout<<"Case #"<<cs<<": ";
        
    }
	return 0;
}
