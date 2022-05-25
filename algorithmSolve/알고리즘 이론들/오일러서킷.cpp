#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> board;
vector<int> EdgeNum;
vector<int> answer;
int n;
int EdgeSum;

bool Check()
{
    int odd = 0;
    for (int i = 0; i < n; ++i)
    {
        if (EdgeNum[i] % 2 == 1)
            ++odd;
    }
    return odd == 2 || odd == 0 ? true : false;
}

void DFS(int here)
{
    for (int there = 0; there < board[here].size(); ++there)
        while (board[here][there] > 0)
        {
            --board[here][there];
            --board[there][here];
            DFS(there);
        }
    answer.push_back(here);
}

void MakeAnswer()
{
    if (!Check)
        return;

    for (int i = 0; i < n; ++i)
        if (EdgeNum[i] % 2 == 1)
        {
            DFS(i);
            return;
        }

    for (int i = 0; i < n; ++i)
        if (EdgeNum[i] != 0)
        {
            DFS(i);
            return;
        }
}

void Calcul()
{
    MakeAnswer();
    if (answer.empty() || answer.size() != EdgeSum + 1)
    {
        cout << "-1" << '\n';
        return;
    }
    else
    {
        reverse(answer.begin(), answer.end());
        for (int i = 0; i < answer.size(); ++i)
            cout << answer[i] + 1 << ' ';
        cout << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    board.assign(n, vector<int>(n, 0));
    EdgeNum.assign(n, 0);
    EdgeSum = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
        {
            cin >> board[i][j];
            EdgeNum[i] += board[i][j];
            EdgeSum += board[i][j];
        }
    EdgeSum /= 2;
    cout << "--------------EdgeNum is : --------------" << '\n';
    for (int i = 0; i < n; ++i)
        cout << EdgeNum[i] << ' ';
    cout << '\n';
    cout << "--------------EdgeSum is : --------------" << '\n';
    cout << EdgeSum << '\n';
    Calcul();
    return 0;
}