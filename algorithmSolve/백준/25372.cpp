#include <iostream>

using namespace std;

// Ǯ��.
// ���ڿ��� ���̰� ���ǿ� �ش��ϴ��� Ȯ���ϴ� ����.

int N;

void MakeAnswer()
{
    string str;
    for (int iter = 0; iter < N; ++iter)
    {
        cin >> str;
        if (str.size() < 6 || str.size() > 9)
            cout << "no" << '\n';
        else
            cout << "yes" << '\n';
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