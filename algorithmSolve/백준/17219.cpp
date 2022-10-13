#include <iostream>
#include <map>

//string 2���� ������Ű�� ����. �ߺ��� ���ٰ� �����ֱ⿡ map�� ����ϸ� �ȴ�.

using namespace std;

map<string, string> board;
string check[100000];
int N, M;

void MakeAnswer()
{
    for (int i = 0; i < M; ++i)
        cout << board[check[i]] << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        string first, second;
        cin >> first >> second;
        board[first] = second;
    }

    for (int i = 0; i < M; ++i)
        cin >> check[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}