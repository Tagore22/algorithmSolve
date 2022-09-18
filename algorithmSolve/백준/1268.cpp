#include <iostream>
#include <map>

using namespace std;

//2차원 배열을 순회하며, 현재 학생과 같은 반이었던 인원들을 모두 파악한다. 단, 같은 반이었던 학생이 중복이 될수도 있기에
//(1학년,2학년때 모두 같은반인 경우 등) 중복을 피하기 위해 map을 이용한다.

int board[1001][5];
int N;
pair<int, int> cheif = make_pair(0, -1); //학생번호, 같은 반이었던 인원의 수

void CalNum(int idx)
{
    map<int, int> with_list;
    for (int i = 0; i < 5; ++i)
        for (int j = 1; j <= N; ++j)
            if (j != idx && board[j][i] == board[idx][i])
                with_list[j] = 1;
    int now = with_list.size();
    if (now > cheif.second)
        cheif = make_pair(idx, now);
    else if (now == cheif.second)
        cheif = make_pair(min(idx, cheif.first), now);
}

void MakeAnswer()
{
    for (int i = 1; i <= N; ++i)
        CalNum(i);
    cout << cheif.first << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 1; i <= N; ++i)
        for (int j = 0; j < 5; ++j)
            cin >> board[i][j];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}