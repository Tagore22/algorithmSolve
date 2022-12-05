#include <iostream>
#include <map>

//Ǯ��
//map���� �� ���ڿ���� �����ϴ� ���� ����ȭ�Ͽ� � ���ڿ��� ���� ���� �����ߴ����� Ȯ���Ѵ�. �ٸ� map�� ���ڿ��� �񱳼����� ���ĵǱ� ������ 
//���ڿ����� ���� ���� ���� �ʰ� �� ���������� ���� �����ؾ��Ѵ�.

using namespace std;

map<string, int> board;
int N;

void MakeAnswer()
{
    string str;
    for (int i = 0; i < N; ++i)
    {
        cin >> str;
        ++board[str];
    }

    pair<string, int> answer = make_pair(" ", -1);
    for (auto iter = board.cbegin(); iter != board.cend(); ++iter)
        if (iter->second > answer.second)
            answer = make_pair(iter->first, iter->second);

    cout << answer.first << '\n';
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