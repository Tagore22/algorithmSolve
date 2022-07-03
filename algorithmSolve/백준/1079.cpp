#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> R;
vector<int> guilt;
vector<bool> isSurvive;
int N, num;

int CompareGuilty()
{
    auto next = make_pair(-1, N);
    for (int i = 0; i < N; ++i)
        if (isSurvive[i] && (guilt[i] > next.first || (guilt[i] == next.first && next.second > i)))
            next = make_pair(guilt[i], i);

    return next.second;
}

int LoopGame()
{
    int next = CompareGuilty();
    if (next == num)
        return 0;
    isSurvive[next] = false;
    int answer = 0;
    for (int i = 0; i < N; ++i)
        if (isSurvive[i] && i != num)
        {
            isSurvive[i] = false;
            for (int j = 0; j < N; ++j)
                guilt[j] += R[i][j];
            answer = max(answer, LoopGame() + 1);
            for (int j = 0; j < N; ++j)
                guilt[j] -= R[i][j];
            isSurvive[i] = true;
        }
    isSurvive[next] = true;
    return answer;
}

void FirstLoop()
{
    int SurSize = count(isSurvive.begin(), isSurvive.end(), true);
    if (SurSize % 2 != 0)
    {
        int next = CompareGuilty();
        if (next == num)
        {
            cout << 0 << '\n';
            return;
        }
        isSurvive[next] = false;
    }
    int answer = 0;
    for (int i = 0; i < N; ++i)
        if (isSurvive[i] && i != num)
        {
            isSurvive[i] = false;
            for (int j = 0; j < N; ++j)
                guilt[j] += R[i][j];
            answer = max(answer, LoopGame() + 1);
            for (int j = 0; j < N; ++j)
                guilt[j] -= R[i][j];
            isSurvive[i] = true;
        }
    cout << answer << '\n';
}

void Input() // 참가자 번호는 0번부터 n-1번까지
{
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        int a;
        cin >> a;
        guilt.push_back(a);
    }
    R.assign(N, vector<int>(N, 0));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> R[i][j];
    cin >> num;
    isSurvive.assign(N, true);
}

int main()
{
    Input();
    FirstLoop();
    return 0;
}