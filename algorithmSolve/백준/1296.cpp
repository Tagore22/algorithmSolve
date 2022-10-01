#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//팀 이름들의 배열을 정렬하여 가장 짧은것을 앞에 둔다. 그 이후 각 팀 이름들의 승률을 구해 더 크다면 교체하며 배열을 순회한다.

vector<string> team;
string name;
int N, L, O, V, E;

void MakeAnswer()
{
    for (int i = 0; i < name.size(); ++i)
    {
        if (name[i] == 'L')
            ++L;
        else if (name[i] == 'O')
            ++O;
        else if (name[i] == 'V')
            ++V;
        else if (name[i] == 'E')
            ++E;
    }
    sort(team.begin(), team.end());
    double answer = -1;
    string ans = "";
    for (int iter = 0; iter < N; ++iter)
    {
        int t_L = 0;
        int t_O = 0;
        int t_V = 0;
        int t_E = 0;
        for (int i = 0; i < team[iter].size(); ++i)
        {
            if (team[iter][i] == 'L')
                ++t_L;
            else if (team[iter][i] == 'O')
                ++t_O;
            else if (team[iter][i] == 'V')
                ++t_V;
            else if (team[iter][i] == 'E')
                ++t_E;
        }
        double check = (L + t_L + O + t_O) * (L + t_L + V + t_V) * (L + t_L + E + t_E) * (O + t_O + V + t_V) * (O + t_O + E + t_E)
            * (V + t_V + E + t_E) % 100;
        if (check > answer)
        {
            answer = check;
            ans = team[iter];
        }
    }
    cout << ans << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> name >> N;
    for (int i = 0; i < N; ++i)
    {
        string str;
        cin >> str;
        team.push_back(str);
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}