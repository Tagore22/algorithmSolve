#include <iostream>
#include <vector>

using namespace std;

vector<int> proto;
int L;
string str;

void kmpProto()
{
    proto.assign(L, 0);
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

    cin >> L >> str;
    kmpProto();
    cout << L - proto[L - 1] << '\n';
    return 0;
}