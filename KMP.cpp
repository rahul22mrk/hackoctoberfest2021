#include <bits/stdc++.h>
using namespace std;


#define ll		long long int
#define pb		push_back
#define fastio 	ios_base::sync_with_stdio(false);cin.tie(NULL)

void KMP() {
    string str, pat;
    cin >> str >> pat;
    int n = str.size();
    int m = pat.size();

    vector<ll> lps(m, 0);
    int len = 0;
    int i = 1;
    while(i < m) {
        if(pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if(len) {
                len = lps[len - 1];
            } else {
                i++;
            }
        }
    }


    i = 0;
    int j = 0;
    vector<int> ans;
    while(i < n) {
        if(str[i] == pat[j]) {
            i++;
            j++;
            if(j == m) {
                ans.pb(i - m + 1);
                j = lps[j - 1];
            }
        } else {
            if(j) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }

    if(ans.empty()) {
        cout << "Not Found\n";
    } else {
        cout << ans.size() << endl;
       for(int i : ans) {
            cout << i << " ";
       }
       cout << endl;
    }
    cout << endl;
}

int main() {
    fastio;
    int t;
    cin >> t;
    while(t--) {
        KMP();
    }
}
