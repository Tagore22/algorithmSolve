#include <iostream> 
#include <vector>
#include <algorithm>

using namespace std;

int n, c;
vector<int> board;
vector<long long> first, second;

void Calcul(int a, int b, vector<long long>& vec, long long sum)
{
    if (a > b)
    {
        vec.push_back(sum);
        return;
    }
    Calcul(a + 1, b, vec, sum);
    Calcul(a + 1, b, vec, sum + board[a]);
}

void FindAnswer()
{
    long long answer = 0;
    Calcul(0, n / 2, first, 0);
    Calcul(n / 2 + 1, n - 1, second, 0);

    sort(second.begin(), second.end());
    for (int i = 0; i < first.size(); ++i)
        answer += upper_bound(second.begin(), second.end(), c - first[i]) - second.begin();
    cout << answer << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> c;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        board.push_back(x);
    }
    FindAnswer();
    return 0;
}