#include <iostream>
#include <queue>

using namespace std;

class compareCal
{
public:
    bool operator() (int a, int b)
    {
        if (abs(a) > abs(b))
            return true;
        else if (abs(a) < abs(b))
            return false;
        else
            return a > b ? true : false;
    }
};

priority_queue<int, vector<int>, compareCal> pQue;

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
        if (x != 0)
            pQue.push(x);
        else
        {
            if (!pQue.empty())
            {
                int y = pQue.top();
                pQue.pop();
                cout << y << '\n';
            }
            else
                cout << 0 << '\n';
        }

    }
    return 0;
}