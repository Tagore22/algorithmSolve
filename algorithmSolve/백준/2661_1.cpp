#include <iostream>
#include <string>

using namespace std;

// 2661번의 조금더 빠른 풀이.
// 좋은 함수를 확인하는 함수를 조금더 개선해본 경우이다.
// 기존에는 모든 원소를 순회하며 그 원소 이후에 같은 원소가 존재한다면
// 부분 수열을 확인해보는 로직이었다면 이번에는 뒤에서 한개씩 추가하는 방식이기에
// 문자열의 크기 / 2까지만 확인해보면 된다.

// 자세한 설명은 주석으로 남긴다.

int N;
bool isfind = false;

// 좋은 수열인지 확인하는 함수. 최대 문자열의 크기 / 2까지만 확인하며
// 뒤에서부터 1 ~ 문자열의 크기 / 2개까지 확인해 나간다.
bool CheckArray(const string& str)
{
    int limit = str.size() / 2;
    for (int i = 1; i <= limit; ++i)
    {
        int from = str.size() - i;
        int to = from - i;
        if (str.substr(from, i) == str.substr(to, i))
            return false;
    }
    return true;
}

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