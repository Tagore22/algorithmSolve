#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 풀이
// 알파벳 개수 C개와 그중 L개의 암호를 만들어야 하는데, 암호의 조건은 3가지이다.
//
// 1. 모음이 최소 1개 이상이다.
// 2. 자음이 최소 2개 이상이며.
// 3. 오름차순으로 정렬되어있다.
// 
// 재귀 함수를 반복하며 만들수 있는 모든 문자열중 위 조건에 부합하는 문자열들을 따로 vector에 담아 출력하면 된다.

vector<string> answer;
string board = "";
int L, C;

// 현재 주어진 문자열이 암호에 조건에 부합하는지를 확인하는 함수. 자음과 모음의 개수를 확인함.
bool CheckStr(string& cur)
{
    int mo = 0, ja = 0;
    for (int i = 0; i < cur.size(); ++i)
    {
        if (cur[i] == 'a' || cur[i] == 'e' || cur[i] == 'i' || cur[i] == 'o' || cur[i] == 'u')
            ++mo;
        else
            ++ja;
    }

    return mo >= 1 && ja >= 2 ? true : false;
}


// 만들수 있는 모든 문자열을 재귀로 만들어본다. 
void CalStr(int idx, string cur)
{
    if (idx != -1)
        cur += board[idx];

    if (idx >= C)
        return;

    if (cur.size() == L)
    {
        if (CheckStr(cur))
            answer.push_back(cur);
        return;
    }

    for (int i = idx + 1; i < C; ++i)
        CalStr(i, cur);
}

void MakeAnswer()
{
    sort(board.begin(), board.end());
    CalStr(-1, string(""));
    for (int i = 0; i < answer.size(); ++i)
        cout << answer[i] << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> L >> C;
    char cha;
    for (int i = 0; i < C; ++i)
    {
        cin >> cha;
        board += cha;
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}