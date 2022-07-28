#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<pair<int, int>> board;
multiset<int> backpack;
int N, K;

//ó������ ��ġ�� ũ�� ���԰� ���� �����°� ���� �����Ѵٰ� �����߱⿡
//�Ʒ��� ���� �Լ��� �����Ͽ����� �ٽ� �����غ��� lower_bound�� ���� ���Կ� �´�
//������ ã�� ������ ���� �׷��ʿ䰡 ������.

bool CompareJ(const pair<int, int>& a, const pair<int, int>& b)
{
    if (a.first > b.first)
        return true;
    else if (a.first < b.first)
        return false;
    else
        return a.second < b.second ? true : false;
}

void MakeAnswer()
{
    sort(board.begin(), board.end(), CompareJ);

    long long answer = 0;
    multiset<int>::iterator iter;
    for (int i = 0; i < N; ++i)
    {
        iter = backpack.lower_bound(board[i].second);
        if (iter != backpack.end())
        {
            backpack.erase(iter);
            answer += board[i].first;
        }
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;
    for (int i = 0; i < N; ++i)
    {
        int a, b;
        cin >> a >> b;
        board.push_back(make_pair(b, a));
    }
    for (int i = 0; i < K; ++i)
    {
        int a;
        cin >> a;
        backpack.insert(a);
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}