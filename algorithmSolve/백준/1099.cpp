#include <iostream>
#include <algorithm>

using namespace std;

// 풀이.
// 어렵다기 보다는 풀이 자체가 복잡했다. 어떠한 위치 idx에서 만들수 있는 모든 문자열중 얻을수 있는 
// 최소한의 변환값들을 dp를 이용하여 구하면 된다. 설명하기 복잡하여 주석으로 남긴다.

// 자세한 설명은 주석으로 남긴다.

string board[50];
string str;
int dp[50];
int N;
const int MAXNUM = 51;

// 두개의 문자열이 주어질때 변환값을 구하는 함수.
int CalCost(string next, string cur)
{
    // 두 문자열의 길이가 다르다면 무조건 변환할수 없다.
    if (next.size() != cur.size())
        return MAXNUM;

    string first = next, second = cur;
    sort(first.begin(), first.end());
    sort(second.begin(), second.end());
    // 두 문자열을 정렬한값이 다르다면 무조건 변화할수 없다.
    if (first != second)
        return MAXNUM;

    int ans = 0;
    for (int i = 0; i < next.size(); ++i)
        if (next[i] != cur[i])
            ++ans;
    return ans;
}

// 현재 문자열 next와 모든 단어들을 비교하여 얻을수 있는 최소한의 변환값을 반환한다.
int MinCost(string next)
{
    int ans = MAXNUM;
    for (int i = 0; i < N; ++i)
        ans = min(ans, CalCost(next, board[i]));
    return ans;
}

int FindMin(int idx)
{
    // 마지막 원소값까지 구했다면 0을 반환하고 탈출한다.
    if (idx == str.size())
        return 0;
    int& ans = dp[idx];
    if (ans != -1)
        return ans;

    ans = MAXNUM;
    for (int i = idx; i < str.size(); ++i)
    {
        // 현재 위치부터 1개씩 늘려가며 부분 문자열로 만들수 있는 최소값을 구한다.
        string next = str.substr(idx, i - idx + 1);
        int cur = MinCost(next);
        // 구할수 없다면 무시한다.
        if (cur == MAXNUM)
            continue;
        ans = min(ans, cur + FindMin(i + 1));
    }
    return ans;
}

void MakeAnswer()
{
    for (int i = 0; i < MAXNUM; ++i)
        dp[i] = -1;
    int answer = FindMin(0);
    cout << (answer == MAXNUM ? -1 : answer) << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> str >> N;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}