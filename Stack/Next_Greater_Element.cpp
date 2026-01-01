#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v = {6, 2, 8, 4, 0, 1, 3};
    stack<int> st;
    vector<int> ans(v.size(), 0);
    for (int i = v.size() - 1; i >= 0; i--)
    {
        while (st.size() > 0 && st.top() <= v[i])
            st.pop();
        if (st.size() == 0)
            ans[i] = -1;
        else
            ans[i] = st.top();

        st.push(v[i]);
    }

    for (int i = 0; i < v.size(); i++)
        cout << ans[i] << " ";
    cout << endl;
}