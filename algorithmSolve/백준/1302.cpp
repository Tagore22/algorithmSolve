#include <iostream>
#include <map>

//풀이
//map으로 각 문자열들과 등장하는 수를 동기화하여 어떤 문자열이 가장 많이 등장했는지를 확인한다. 다만 map은 문자열의 비교순위로 정렬되기 때문에 
//문자열들의 등장 수가 같지 않고 더 많을때에만 답을 갱신해야한다.

using namespace std;

map<string, int> board;
int N;

void MakeAnswer()
{
    string str;
    for (int i = 0; i < N; ++i)
    {
        cin >> str;
        ++board[str];
    }

    pair<string, int> answer = make_pair(" ", -1);
    for (auto iter = board.cbegin(); iter != board.cend(); ++iter)
        if (iter->second > answer.second)
            answer = make_pair(iter->first, iter->second);

    cout << answer.first << '\n';
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