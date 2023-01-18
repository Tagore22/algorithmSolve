#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

//Ǯ��
//�ܼ��� ���� ������. �� ������ ���� �󵵼�, ���� ���� 2�����ε� ���� �󵵼��� ���Ҷ� ���� �ϴ� �ִ밪�� 10���̱⿡ �̰���
//��� �迭�� ��Ƴ����� ���� map�� ����ؾ� �ߴ�. ����, ����Ͽ����� �󵵼��� ������ ��� ���ؾ��� ����������� �����ؾ������Ƿ�
//map<int, pair<int,int>>�� ����ؾ��Ѵ�. �������� ����� �� �Լ� �ϳ��� �����ϴ°� ���̴�.

int board[1000];
map<int, pair<int, int>> check; //���� ��, ���� ������ ���� �켱����, ���� �󵵼�.
int N, C;

bool SortFunc(int a, int b)
{
    if (check[a].second > check[b].second) //�󵵼� ��ü�� ���̳��ٸ� �ٷ� �񱳰���.
        return true;
    else if (check[a].second == check[b].second) //�󵵼��� ���ٸ� �켱������ ���Ѵ�.
        return check[a].first > check[b].first;
    else
        return false;
}

void MakeAnswer()
{
    sort(board, board + N, SortFunc);
    for (int i = 0; i < N; ++i)
        cout << board[i] << ' ';
    cout << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> C;
    for (int i = 0; i < N; ++i)
    {
        cin >> board[i];
        if (check[board[i]].first == 0)
            check[board[i]].first = N - i;
        ++check[board[i]].second;
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}