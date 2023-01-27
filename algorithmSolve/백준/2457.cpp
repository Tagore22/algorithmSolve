#include <iostream>

using namespace std;

//풀이
//현재 버전의 꽃이 피는 날 cur_from과 지는 날 cur_to를 갱신해가며, 꽃의 배열을 순회해나간다.
//현재 꽃이 피는날보다 더 빨리피거나 같은날 피면서, 현재 꽃이 지는 날보다 더 피는 꽃을 선택하면 된다.
//다만, 배열 순회후 cur_from과 cur_to가 같다는 것은 아무 꽃도 고를수 없었다는 뜻이기에
//cur_to가 11월 30일보다 같거나 작을때에는 0을 출력해야한다.
//마지막에 cur_to가 11월 30일보다 커졌을 경우 순회를 마친다.

struct flower
{
    pair<int, int> from;
    pair<int, int> to;
};

flower board[100000];
int N;

bool CompareMin(pair<int, int> a, pair<int, int> b) //두 pair<>의 비교문. 두 pair<>가 같아도 허용됨.
{
    if (a.first < b.first)
        return true;
    else if (a.first == b.first)
        return a.second <= b.second;
    else
        return false;
}

bool CompareMax(pair<int, int> a, pair<int, int> b) //두 pair<>의 비교문. 두 pair<>가 같으면 허용되지 않음.
{
    if (a.first > b.first)
        return true;
    else if (a.first == b.first)
        return a.second > b.second;
    else
        return false;
}

void MakeAnswer()
{
    int answer = 0;
    pair<int, int> cur_from, cur_to = make_pair(3, 1);
    while (true)
    {
        cur_from = cur_to; //현재 꽃이 지는 날보다 더 빨리 피거나 지는날과 동시에 펴야함.
        for (int i = 0; i < N; ++i)
            if (CompareMin(board[i].from, cur_from) && CompareMax(board[i].to, cur_to))
                cur_to = board[i].to;

        ++answer;

        if (cur_from == cur_to) //꽃을 찾지 못했다.
        {
            cout << 0 << '\n';
            return;
        }

        if (CompareMax(cur_to, make_pair(11, 30))) //11월 30일까지 피는 꽃을 찾았다.
            break;
    }

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> board[i].from.first >> board[i].from.second >> board[i].to.first >> board[i].to.second;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}