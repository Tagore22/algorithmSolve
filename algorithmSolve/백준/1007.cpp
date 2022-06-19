#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits>

using namespace std;

vector<pair<int, int>> board;
vector<bool> check;
int N;
double answer;

void MakeAnswer()
{
    pair<int, int> ans = make_pair(0, 0);
    for (int i = 0; i < N; ++i)
    {
        if (check[i])
        {
            ans.first -= board[i].first;
            ans.second -= board[i].second;
        }
        else
        {
            ans.first += board[i].first;
            ans.second += board[i].second;
        }
    }
    answer = min(answer, sqrt(pow(ans.first, 2) + pow(ans.second, 2)));
}

void Calcul(int num, int idx) //처음 호출시 idx는 -1부터
{
    if (num == N / 2)
        MakeAnswer();
    else
    {
        for (int i = idx + 1; i < N; ++i)
        {
            check[i] = true;
            Calcul(num + 1, i);
            check[i] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    for (int i = 0; i < T; ++i)
    {
        board.clear();
        cin >> N;
        for (int j = 0; j < N; ++j)
        {
            int a, b;
            cin >> a >> b;
            board.push_back(make_pair(a, b));
        }
        answer = numeric_limits<double>::max();
        check.assign(N, false);
        Calcul(0, -1);
        cout << fixed;
        cout.precision(6);
        cout << answer << '\n';
    }
    return 0;
}