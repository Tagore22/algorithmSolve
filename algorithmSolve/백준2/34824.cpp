#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, y, k;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        string str;
        cin >> str;
        if (str == "yonsei")
            y = i;
        else if (str == "korea")
            k = i;
    }
    cout << (y < k ? "Yonsei Won!" : "Yonsei Lost...") << '\n';
    return 0;
}