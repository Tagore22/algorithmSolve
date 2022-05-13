#include <iostream>
#include <vector>

using namespace std;

const int maxNum = 360000;
vector<int> proto(maxNum, 0);
vector<int> answer;
vector<int> a(maxNum * 2, 0);
vector<int> b(maxNum, 0);

void kmpProto()
{
    int begin = 1;
    int matched = 0;
    while (begin + matched < b.size())
    {
        if (b[begin + matched] == b[matched])
        {
            ++matched;
            proto[begin + matched - 1] = matched;
        }
        else
        {
            if (matched == 0)
            {
                ++begin;
            }
            else
            {
                begin += matched - proto[matched - 1];
                matched = proto[matched - 1];
            }
        }
    }
}

void kmp()
{
    int begin = 0;
    int matched = 0;
    while (begin + matched < a.size())
    {
        if (matched < b.size() && a[begin + matched] == b[matched])
        {
            ++matched;
            if (matched == b.size())
                answer.push_back(begin + 1);
        }
        else
        {
            if (matched == 0)
            {
                ++begin;
            }
            else
            {
                begin += matched - proto[matched - 1];
                matched = proto[matched - 1];
            }
        }
    }
}

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
        a[x] = 1;
        a[x + maxNum] = 1;
    }
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        b[x] = 1;
    }
    kmpProto();
    kmp();
    if (!answer.empty())
        cout << "possible" << '\n';
    else
        cout << "impossible" << '\n';
    return 0;
}