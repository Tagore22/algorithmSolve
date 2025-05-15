#include <iostream>
#include <algorithm>

using namespace std;

struct team
{
    int sum;
    int entrynum;
    int solvetrynum;
    int teamID;
};

const int MAX = 101;
int score[MAX][MAX], entry[MAX], solvetry[MAX];
team allteam[MAX];
int T, N, K, ID, M;

bool SortTeam(const team& lhs, const team& rhs)
{
    if (lhs.sum != rhs.sum)
        return lhs.sum > rhs.sum;
    else if (lhs.solvetrynum != rhs.solvetrynum)
        return lhs.solvetrynum < rhs.solvetrynum;
    else if (lhs.entrynum != rhs.entrynum)
        return lhs.entrynum < rhs.entrynum;
    else
        return false;
}

void InitAll()
{
    for (int i = 1; i <= N; ++i)
    {
        solvetry[i] = 0;
        entry[i] = 0;
        for (int j = 1; j <= K; ++j)
            score[i][j] = 0;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    for (int iter = 0; iter < T; ++iter)
    {
        cin >> N >> K >> ID >> M;
        InitAll();
        for (int i = 0; i < M; ++i)
        {
            int teamID, num, s;
            cin >> teamID >> num >> s;
            ++solvetry[teamID];
            entry[teamID] = i;
            score[teamID][num] = max(score[teamID][num], s);
        }
        for (int i = 1; i <= N; ++i)
        {
            int sum = 0;
            for (int j = 1; j <= K; ++j)
                sum += score[i][j];
            allteam[i] = { sum, entry[i], solvetry[i], i };
        }
        sort(allteam + 1, allteam + N + 1, SortTeam);
        for (int i = 1; i <= N; ++i)
        {
            if (allteam[i].teamID == ID)
            {
                cout << i << '\n';
                break;
            }
        }
    }
    return 0;
}