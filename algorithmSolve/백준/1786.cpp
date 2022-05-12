#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> proto;
vector<int> answer;

void kmpProto(const string& str)
{
    int begin = 1;
    int matched = 0;
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
}

void kmp(const string& a, const string& b)
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

    string a, b;
    getline(cin, a);
    getline(cin, b);
    proto.assign(b.size(), 0);
    kmpProto(b);
    kmp(a, b);
    cout << answer.size() << '\n';
    for (int i = 0; i < answer.size(); ++i)
        cout << answer[i] << '\n';
    return 0;
}