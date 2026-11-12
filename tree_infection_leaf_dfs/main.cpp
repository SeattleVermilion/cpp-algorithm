#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

struct TreeNode
{
    TreeNode* lchild = nullptr;
    TreeNode* rchild = nullptr;
    TreeNode* parent = nullptr;
};

struct State
{
    TreeNode* cur;
    TreeNode* pre;
    int dis;
};

int infectionTime(TreeNode* start)
{
    stack<State> s;
    s.push({start, nullptr, 0});

    int ans = 0;

    while (!s.empty())
    {
        State t = s.top();
        s.pop();

        int degree = 0;

        if (t.cur->lchild != nullptr)
            degree++;

        if (t.cur->rchild != nullptr)
            degree++;

        if (t.cur->parent != nullptr)
            degree++;

        if (degree <= 1)
            ans = max(ans, t.dis);

        if (t.cur->lchild != nullptr && t.cur->lchild != t.pre)
            s.push({t.cur->lchild, t.cur, t.dis + 1});

        if (t.cur->rchild != nullptr && t.cur->rchild != t.pre)
            s.push({t.cur->rchild, t.cur, t.dis + 1});

        if (t.cur->parent != nullptr && t.cur->parent != t.pre)
            s.push({t.cur->parent, t.cur, t.dis + 1});
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, start;
    cin >> n >> start;

    TreeNode* nodes = new TreeNode[n];

    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;

        if (l != -1)
        {
            nodes[i].lchild = &nodes[l];
            nodes[l].parent = &nodes[i];
        }

        if (r != -1)
        {
            nodes[i].rchild = &nodes[r];
            nodes[r].parent = &nodes[i];
        }
    }

    cout << infectionTime(&nodes[start]) << '\n';

    delete[] nodes;

    return 0;
}
