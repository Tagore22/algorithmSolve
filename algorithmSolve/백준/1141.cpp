#include <iostream>
#include <vector>
#include <algorithm>

//풀이
//1. 우선 각 문자열들을 정렬하되, 문자열의 순서보다 문자열의 길이를 기준으로 정렬해야한다. 긴 문자열에서 짧은 문자열을 비교해봐야 하기에 나중에 문자열을 비교하는 함수를
//구현할때 이렇게 해야 더 편한다.
//2. 시작시 답은 N으로 해놓고, 문자열들의 배열을 순회해가며 짧은 문자열이 긴 문자열의 부분문자이며 시작 인덱스가 0일때에는 답을 1빼주고 그 이후는 무시한다.
//3. 답을 출력한다.

using namespace std;

int N;
vector<string> board;

bool ComposeString(const string& str1, const string& str2)
{
    if (str1.size() < str2.size())
        return true;
    else
        return false;
}

void MakeAnswer()
{
    int answer = N;
    for (int i = 0; i < N; ++i)
    {
        for (int j = i + 1; j < N; ++j)
            if (board[j].find(board[i]) == 0)
            {
                --answer;
                break;
            }
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
    {
        string str;
        cin >> str;
        board.push_back(str);
    }
    sort(board.begin(), board.end(), ComposeString);
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}