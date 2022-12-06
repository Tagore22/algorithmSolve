#include <iostream>
#include <cctype>
#include <algorithm>

//풀이
//정렬에 쓰일 함수를 구현하는 문제이다. 각 크기, 포함되어 있는 수들, 사전식 비교를 구현해야한다. 또한, 원자적 연산을 하지 못하는 경우에 주의해야한다.
//(true, 혹은 false에 포함되지 않거나 둘다 포함되는 경우)

using namespace std;

string board[50];
int N;

int SumSerial(const string& a)
{
    int sum = 0;
    for (int i = 0; i < a.size(); ++i)
        if (isdigit(a[i]))
            sum += a[i] - '0';

    return sum;
}

bool ComposeSerial(const string& a, const string& b)
{
    if (a.size() != b.size())
        return a.size() < b.size() ? true : false;
    else if (SumSerial(a) != SumSerial(b))
        return SumSerial(a) < SumSerial(b) ? true : false;
    else
        return a < b ? true : false;
}

void MakeAnswer()
{
    sort(board, board + N, ComposeSerial);
    for (int i = 0; i < N; ++i)
        cout << board[i] << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}