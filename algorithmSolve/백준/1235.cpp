#include <iostream>

using namespace std;

//Ǯ��
//�־����� N���� ���ڿ����� �� �ں��� �κй��ڿ��� ������ N���� �κй��ڿ����� ��� �ٸ� ������ �κй��ڿ� �ڸ����� ���ϸ� �ȴ�.
//��� �ڸ������� �� �ڱ��� �κй��ڿ��� ����µ��� string.substr�̶�� ���� �Լ��� �ֱ⿡ �̰� �̿��ϸ� �������� �ٸ� ��� �κй��ڿ��� ���ϴ�
//2�� for���� �����ϸ� �ȴ�.

string board[1000];
int N;

void MakeAnswer()
{
    int answer = 1;
    bool isfind;
    for (int i = board[0].size() - 1; i >= 1; --i)
    {
        isfind = true;
        for (int from = 0; from < N - 1; ++from)
        {
            for (int to = from + 1; to < N; ++to)
                if (board[from].substr(i) == board[to].substr(i))
                {
                    isfind = false;
                    break;
                }
            if (!isfind)
                break;
        }

        if (!isfind)
            ++answer;
        else
            break;
    }
    cout << answer << '\n';
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