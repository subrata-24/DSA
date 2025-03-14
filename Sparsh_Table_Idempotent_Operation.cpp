//It is used for Idempotent Operation 
//min,max,gcd,lcm,&(And),|(or)
//Time Complexity O(1)

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) a / __gcd(a, b) * b
#define mod 1000000007
#define TheAnt                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

const int k = 25, N = 1e5 + 10;
int sp_Table[k][N];

void build_Sp_Table(int n, vector<int> &v)
{
    for (int i = 0; i < n; i++)
        sp_Table[0][i] = v[i];

    for (int i = 1; i < k; i++)
    {
        for (int j = 0; j + (1 << i) <= n; j++)
            sp_Table[i][j] = min(sp_Table[i - 1][j], sp_Table[i - 1][j + (1 << (i - 1))]);
    }
}

int query(int left, int right)
{
    int lst_one = 31 - __builtin_clz(right - left + 1);

    int ans = min(sp_Table[lst_one][left], sp_Table[lst_one][right - (1 << lst_one) + 1]);
    return ans;
}
signed main()
{
    TheAnt;
    int n;
    cin >> n;
    vector<int> val(n);
    for (int i = 0; i < n; i++)
        cin >> val[i];

    build_Sp_Table(n, val);

    int q;
    cin >> q;
    while (q--)
    {
        int left, right;
        cin >> left >> right;

        // convert to 0 base index
        left--;
        right--;

        cout << query(left, right) << '\n';
    }
    return 0;
}
