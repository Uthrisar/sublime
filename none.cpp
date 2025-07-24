#include <bits/stdc++.h>
using namespace std;

int n, m;

int func(int i, vector<int> v2)
{
    if (i == 0)
    {
        if (v2[0])
        {
            return 1;
        }
        else
        {
            return 3;
        }
    }
    if (i < n - 1 && v2[i])
        return func(i - 1, v2);
    int ans = 0;
    if (i == n - 1)
    {
        if (!v2[i])
        {
            if (v2[i - 1] != 0)
            {
                if (v2[i - 1] > 1)
                {
                    v2[i] = v2[i - 1] - 1;
                    ans += func(i - 1, v2) + 1;
                    v2[i] = 0;
                }
                if (v2[i - 1] < m)
                {
                    v2[i] = v2[i - 1] + 1;
                    ans += func(i - 1, v2) + 1;
                    v2[i] = 0;
                }
                v2[i] = v2[i - 1];
                ans += func(i - 1, v2) + 1;
                v2[i] = 0;
            }
            else
            {
                for (int j = 1; j <= m; j++)
                {
                    v2[i] = j;
                    ans += func(i - 1, v2) + 1;
                    v2[i] = 0;
                }
            }
        }
        else
        {
            ans = func(i - 1, v2);
        }
    }
    if (!v2[i] && v2[i - 1])
    {
        if (i < n - 1)
        {
            if (abs(v2[i + 1] - v2[i - 1]) == 1)
            {
                v2[i] = v2[i - 1];
                ans += func(i - 1, v2) + 1;
                v2[i] = 0;
                v2[i] = v2[i + 1];
                ans += func(i - 1, v2) + 1;
                v2[i] = 0;
            }
            if (abs(v2[i + 1] - v2[i - 1]) == 2)
            {
                v2[i] = min(v2[i + 1], v2[i - 1]) + 1;
                ans += func(i - 1, v2) + 1;
                v2[i] = 0;
            }
            if (v2[i + 1] == v2[i - 1])
            {
                v2[i] = v2[i + 1];
                ans += func(i - 1, v2);
                v2[i] = 0;
                if (v2[i + 1] < m)
                {
                    v2[i] = v2[i + 1] + 1;
                    ans += func(i - 1, v2) + 1;
                    v2[i] = 0;
                }
                if (v2[i + 1] > 1)
                {
                    v2[i] = v2[i + 1] - 1;
                    ans += func(i - 1, v2) + 1;
                    v2[i] = 0;
                }
            }
        }
    }
    if (!v2[i] && !v2[i - 1])
    {
        if (v2[i + 1] > 1)
        {
            v2[i] = v2[i + 1] - 1;
            ans += func(i - 1, v2) + 1;
            v2[i] = 0;
        }
        if (v2[i + 1] < m)
        {
            v2[i] = v2[i + 1] + 1;
            ans += func(i - 1, v2) + 1;
            v2[i] = 0;
        }
        v2[i] = v2[i + 1];
        ans += func(i - 1, v2) + 1;
        v2[i] = 0;
    }
    return ans;
}

int main()
{
    cin >> n >> m;
    vector<int> v1(n);
    for (int i = 0; i < n; i++)
        cin >> v1[i];
    vector<int> v2(v1.begin(), v1.end());
    cout << func(n - 1, v2) << "\n";
}