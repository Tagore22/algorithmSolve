#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

// 풀이.
// 주어진 문자열들을 문제에서 제시한 3가지 조건대로 정렬하여 출력하는 문제다.
// 문자열이 등장하는 횟수를 알아야하기 위해 map이 필수인데 이 풀이에서는
// 그냥 map을 사용하여 엄청 느리다. 매번 필요없는 정렬을 하기 때문이다.

// 자세한 설명은 주석으로 남긴다.

map<string, int> strs;
vector<string> board;
int N, M;

// 각 문자열들을 주어진 조건대로 정렬하는 함수.
bool CompareString(const string& lhs, const string& rhs)
{
    // 등장횟수가 다를때 더 많이 등장한 문자열이 앞에 온다.
    if (strs[lhs] != strs[rhs])
        return strs[lhs] > strs[rhs];
    // 두 문자열의 길이가 다를때 더 긴 문자열이 앞에 온다.
    else if (lhs.size() != rhs.size())
        return lhs.size() > rhs.size();
    // 그렇지 않으면 사전순 정렬대로 정렬한다.
    else
        return lhs < rhs;
}

void MakeAnswer()
{
    string str;
    // N개의 문자열을 입력받는다.
    for (int iter = 0; iter < N; ++iter)
    {
        cin >> str;
        // 문자열의 길이가 M보다 짧다면 무시한다.
        if (str.size() < M)
            continue;
        // 처음 등장한 문자열이라면 vector에 넣는다.
        if (strs[str] == 0)
            board.push_back(str);
        // 등장횟수를 1 증가시킨다.
        ++strs[str];
    }

    // 벡터에 등장한 중복되지 않은 문자열들을 정렬시킨후 출력한다.
    sort(board.begin(), board.end(), CompareString);
    for (auto s : board)
        cout << s << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}