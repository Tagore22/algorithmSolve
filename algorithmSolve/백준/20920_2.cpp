#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

// 20920번의 최종 풀이.
// 기존에 존재하던 vector를 제외한 풀이.
// unordered_map 역시 중복을 배제하기 때문에 굳이 vector에 중복을 제외한
// 문자열들을 입력하지 않아도 후에 unordered_map의 값을 그대로 복사하면 된다.
// 또한 기존에는 unordered_map에 직접 접근하여 그 값을 얻어냈었는데
// 관련 컨테이너는 랜덤 액세스가 불가능하기 때문에 매번 반복자를 이용하여 해당
// 문자열을 지닌 원소를 찾을때까지 순회를 계속해야 한다. 따라서 매우 많은
// 연산량을 필요로 한다. 그렇기 때문에 정렬시 아예 pair<string, int> 값을 넘겨
// unordered_map으로의 접근을 차단하여 최적화를 노릴수 있다.

// 자세한 설명은 주석으로 남긴다.

int N, M;

bool CompareString(const pair<string, int>& lhs, const pair<string, int>& rhs)
{
    // 등장횟수가 다를때 더 많이 등장한 문자열이 앞에 온다.
    if (lhs.second != rhs.second)
        return lhs.second > rhs.second;
    // 두 문자열의 길이가 다를때 더 긴 문자열이 앞에 온다.
    else if (lhs.first.size() != rhs.first.size())
        return lhs.first.size() > rhs.first.size();
    // 그렇지 않으면 사전순 정렬대로 정렬한다.
    else
    else
        return lhs.first < rhs.first;
}

void MakeAnswer()
{
    string str;
    unordered_map<string, int> strs;
    // N개의 문자열을 입력받는다.
    for (int iter = 0; iter < N; ++iter)
    {
        cin >> str;
        // 문자열의 길이가 M보다 짧다면 무시한다.
        if (str.size() < M)
            continue;
        // 등장횟수를 1 증가시킨다.
        ++strs[str];
    }

    // 정렬을 위해 vector로, unordered_map의 접근을 하지 않기 위해 pair<string, int>로
    // unordered_map에서의 값을 복사해온다.
    vector<pair<string, int>> board(strs.begin(), strs.end());
    // 문제에서 제시된 조건으로 문자열들을 정렬시킨후 출력한다.
    sort(board.begin(), board.end(), CompareString);
    for (auto s : board)
        cout << s.first << '\n';
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