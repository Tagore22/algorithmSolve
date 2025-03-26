#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 풀이.
// multimap으로도 풀 수 있는 문제지만 그 느린 성능을 알기에 vector 2개로 구현해보았다.

vector<string> teams;
vector<string> names[100];
int N, M;

void MakeAnswer()
{
    for (int i = 0; i < N; ++i)
        sort(names[i].begin(), names[i].end());
    for (int iter = 0; iter < M; ++iter)
    {
        string name;
        int num;
        cin >> name >> num;
        if (num == 0)
        {
            int idx;
            for (int i = 0; i < N; ++i)
            {
                if (teams[i] == name)
                {
                    idx = i;
                    break;
                }
            }
            for (auto& name : names[idx])
                cout << name << '\n';
        }
        else
        {
            bool isFind = false;
            for (int i = 0; i < N; ++i)
            {
                for (int j = 0; j < names[i].size(); ++j)
                {
                    if (names[i][j] == name)
                    {
                        isFind = true;
                        cout << teams[i] << '\n';
                        break;
                    }
                }
                if (isFind)
                    break;
            }
        }
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        string team;
        int num;
        cin >> team >> num;
        teams.push_back(team);
        for (int j = 0; j < num; ++j)
        {
            string name;
            cin >> name;
            names[i].push_back(name);
        }
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}