//Sparsh Table for non idempotent operation
//sum,multiply,XOR

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

    for (int i = 1; i <= k; i++)
    {
        for (int j = 0; j + (1 << i) <= n; j++)
        {
            sp_Table[i][j] = sp_Table[i - 1][j] + sp_Table[i - 1][j + (1 << (i - 1))];
        }
    }
}

int query(int left, int right)
{
    int sum = 0;
    for (int i = k; i >= 0; i--)
    {
        if ((1 << i) <= (right - left + 1))
        {
            sum += sp_Table[i][left];
            left += (1 << i);
        }
    }
    return sum;
}

signed main()
{
    TheAnt;
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int k = log2(n);

    build_Sp_Table(n, v);

    int q;
    cin >> q;
    while (q--)
    {
        int left, right;
        cin >> left >> right;

        // Convert to zero-based indexing if necessary
        left--;
        right--;

        int ans = query(left, right);

        cout << ans << '\n';
    }

    return 0;
}
