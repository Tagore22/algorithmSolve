#include <iostream>
#include <string>

using namespace std;

// 풀이.
// 문제 자체는 그리 어렵지 않다. 모든 수열을 만들어서 그중 가장 작은 좋은 수열을 출력하면 된다.
// 백트래킹을 이용해서 모든 수열을 만들고 따로 좋은 수열을 구분하는 함수를 구현하는 것이다.
// 다만 한가지 실수를 했는데 처음에는 수열을 먼저 만들고 그중 좋은 수열을 찾으려고 했다.
// 문제에서 주어지듯 수열의 길이는 최대 80이기에 모든 수열을 만드려면 3의 80제곱이라는 큰 연산량을 필요로 하는데
// 수열을 만들고 좋은 수열인지 확인을 하려면 그 많은 수를 확인해야한다.
// 따라서 미리 가지치기 방식으로 수를 하나씩 추가하면서 좋은 수열들만을 엄선해 다음 백트래킹으로 넘겨야 했다.

// 자세한 설명은 주석으로 남긴다.

int N;
bool isfind = false;

// 좋은 수열인지 확인하는 함수.
bool CheckArray(const string& str)
{
    int size = str.size();
    for (int i = 0; i < size; ++i)
    {
        for (int j = i + 1; j < size; ++j)
        {
            int len = j - i;
            if (str.substr(i, len) == str.substr(j, len))
                return false;
        }
    }
    return true;
}
// 백트래킹을 구현하는 함수.
void BackTrack(const string str)
{
    if (isfind)
        return;

    if (str.size() == N)
    {
        cout << str << '\n';
        isfind = true;
        return;
    }

    for (int i = 1; i <= 3; ++i)
    {
        string next = str + to_string(i);
        if (CheckArray(next))
            BackTrack(next);
    }
}

void MakeAnswer()
{
    BackTrack(string(""));
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}