#include <iostream>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<>> firstQue;
priority_queue<int> secondQue;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        if (firstQue.size() == secondQue.size())
            secondQue.push(x);
        else
            firstQue.push(x);
        if (!firstQue.empty() && !secondQue.empty() && firstQue.top() < secondQue.top())
        {
            int a = firstQue.top();
            int b = secondQue.top();
            firstQue.pop();
            secondQue.pop();
            firstQue.push(b);
            secondQue.push(a);
        }
        cout << secondQue.top() << '\n';
    }
    return 0;
}