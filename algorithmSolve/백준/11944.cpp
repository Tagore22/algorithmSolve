#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string N;
    int M;
    cin >> N >> M;
    string str;
    M = min(stoi(N) * int(N.size()), M);
    while (true)
    {
        for (int i = 0; i < N.size(); ++i)
        {
            if (str.size() == M)
            {
                cout << str << '\n';
                return 0;
            }
            str += N[i];
        }
    }
    return 0;
}