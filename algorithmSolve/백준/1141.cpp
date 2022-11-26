#include <iostream>
#include <vector>
#include <algorithm>

//Ǯ��
//1. �켱 �� ���ڿ����� �����ϵ�, ���ڿ��� �������� ���ڿ��� ���̸� �������� �����ؾ��Ѵ�. �� ���ڿ����� ª�� ���ڿ��� ���غ��� �ϱ⿡ ���߿� ���ڿ��� ���ϴ� �Լ���
//�����Ҷ� �̷��� �ؾ� �� ���Ѵ�.
//2. ���۽� ���� N���� �س���, ���ڿ����� �迭�� ��ȸ�ذ��� ª�� ���ڿ��� �� ���ڿ��� �κй����̸� ���� �ε����� 0�϶����� ���� 1���ְ� �� ���Ĵ� �����Ѵ�.
//3. ���� ����Ѵ�.

using namespace std;

int N;
vector<string> board;

bool ComposeString(const string& str1, const string& str2)
{
    if (str1.size() < str2.size())
        return true;
    else
        return false;
}

void MakeAnswer()
{
    int answer = N;
    for (int i = 0; i < N; ++i)
    {
        for (int j = i + 1; j < N; ++j)
            if (board[j].find(board[i]) == 0)
            {
                --answer;
                break;
            }
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
    {
        string str;
        cin >> str;
        board.push_back(str);
    }
    sort(board.begin(), board.end(), ComposeString);
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}