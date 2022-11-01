#include <iostream>
#include <string>

//�ϳ��� ���ڿ��� �Է¹޾� ,�� ���ö����� ���ڿ����� int�� ġȯ�Ͽ� �迭�� ����.

using namespace std;

string str;
int board[20];
int N, K;

void CalArray()
{
    for (int i = 0; i < N; ++i)
        board[i] = board[i + 1] - board[i];
    --N;
}

void MakeAnswer()
{
    for (int i = 0; i < K; ++i)
        CalArray();
    for (int i = 0; i < N - 1; ++i)
        cout << board[i] << ',';
    cout << board[N - 1] << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K >> str;
    int iter = 0, idx = 0;
    for (int i = 0; i < str.size(); ++i)
        if (str[i] == ',')
        {
            board[idx] = stoi(str.substr(iter, i - iter + 1));
            iter = i + 1;
            ++idx;
        }
    board[idx] = stoi(str.substr(iter, str.size() - iter));
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}