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
        ll i,j,k,n,m;
        cin>>n;
        // cout<<n<<" ";
        string s,ans1="",ans2="";
        cin>>s;
        ans1 += s[0];
        ans1 += s[0];
        ans2 += s[0];
        for(i=1;i<n;i++) {
            if(s[i] <= s[i-1]) {
                ans2 += s[i];
            }
            else {
                break;
            }
        }
        
        string temp = ans2;
        reverse(temp.begin(),temp.end());
        ans2 += temp;
        string ans = ans2;
        if(ans1[1] <= ans2[1]) ans = ans1;
        // cout<<ans1<<" "<<ans2<<" ";
        cout<<ans<<endl;
        // cout<<"Case #"<<cs<<": ";
        
    }
	return 0;
}
