#include <iostream>
#include <vector>

using namespace std;

vector<int> proto;

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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    while (1)
    {
        string str;
        cin >> str;
        if (str == ".")
            break;
        proto.assign(str.size(), 0);
        kmpProto(str);
        if (str.size() % (str.size() - proto[str.size() - 1]))
            cout << "1" << '\n';
        else
            cout << str.size() / (str.size() - proto[str.size() - 1]) << '\n';
    }
    return 0;
}