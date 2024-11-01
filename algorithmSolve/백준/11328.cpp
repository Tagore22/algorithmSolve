#include <iostream>
#include <algorithm>

using namespace std;

int N;

void MakeAnswer()
{
    string str1, str2;
    for (int iter = 0; iter < N; ++iter)
    {
        cin >> str1 >> str2;
        sort(str1.begin(), str1.end());
        sort(str2.begin(), str2.end());

        cout << (str1 == str2 ? "Possible" : "Impossible") << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}