#include <iostream>

using namespace std;

//Ǯ��
//�� ���Ҹ� ���°� �Ⱦ��°��� �������� �������� Ǯ�� �ȴ�. ���� �־����� ����� ���� �ִ� 10���̹Ƿ� �ִ� ���귮��
//2�� 10�������� �ð��ȿ� ����� Ǯ�� �ִ�. ����, ��� ��Ḧ ����ص� �� ������ 10���� ���� �ʱ⿡ int�����ε� 
//��� �ذᰡ���ϴ�.

pair<int, int> board[10];
int N;
int answer = 987654321;

void UseOrNot(int idx, int S, int B)
{
    if (idx >= N)
    {
        if (S != 1 && B != 0)
            answer = min(answer, abs(S - B));
        return;
    }

    UseOrNot(idx + 1, S, B);
    UseOrNot(idx + 1, S * board[idx].first, B + board[idx].second);
}

void MakeAnswer()
{
    UseOrNot(0, 1, 0);
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> board[i].first >> board[i].second;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}