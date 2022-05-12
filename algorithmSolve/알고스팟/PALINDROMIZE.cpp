#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> kmpProto(const string& str)
{
    int begin = 1;
    int matched = 0;
    vector<int> proto(str.size(), 0);
    while (begin + matched < str.size())
    {
        if (str[begin + matched] == str[matched])
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
    return proto;
}

int kmpTrans(const string& a)
{
    int begin = 0;
    int matched = 0;
    string b;
    reverse_copy(a.begin(), a.end(), back_inserter(b));
    vector<int> proto = kmpProto(b);
    while (begin + matched < a.size())
    {
        if (a[begin + matched] == b[matched])
        {
            ++matched;
            if (begin + matched == b.size())
                return matched;
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
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        string str;
        cin >> str;
        string rev;
        reverse_copy(str.begin(), str.end(), back_inserter(rev));
        int plus = kmpTrans(str);
        string answer = str + rev.substr(plus);
        cout << answer.size() << '\n';
    }
    return 0;
}