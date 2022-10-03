#include <iostream>

using namespace std;

//최대 10자리중 기준점을 잡아 그 왼쪽 오른쪽에 있는 원소값들을 곱해 비교하여 같은지 확인한다.
//주어지는 값 N의 최대값은 10자리이므로 기준점은 최대 9곳을 잡을수 있고,
//각 기준점마다 최대 10번의 곱셈이 있으므로 최대 연산은 100번을 넘지 않는다.

string N;

void MakeAnswer()
{
    for (int i = 1; i < N.size(); ++i)
    {
        int left = 1;
        int right = 1;
        for (int idx = 0; idx < i; ++idx)
            left *= N[idx] - '0';
        for (int idx = i; idx < N.size(); ++idx)
            right *= N[idx] - '0';
        if (left == right)
        {
            cout << "YES" << '\n';
            return;
        }
    }
    cout << "NO" << '\n';
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