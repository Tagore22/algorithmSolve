#include <iostream>
#include <cctype>
#include <algorithm>

//Ǯ��
//���Ŀ� ���� �Լ��� �����ϴ� �����̴�. �� ũ��, ���ԵǾ� �ִ� ����, ������ �񱳸� �����ؾ��Ѵ�. ����, ������ ������ ���� ���ϴ� ��쿡 �����ؾ��Ѵ�.
//(true, Ȥ�� false�� ���Ե��� �ʰų� �Ѵ� ���ԵǴ� ���)

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