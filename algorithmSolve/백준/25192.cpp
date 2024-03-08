#include <iostream>
#include <unordered_map>

using namespace std;

// 풀이.
// 문자열들을 입력받아 이미 입력받았던 문자열인지 확인하는 문제다.
// 처음에는 set이나 map을 썼는데 unordered_map이 있었다. 연관 컨테이너는 자주 안쓰니
// 잊어버리는 것 같다. 새롭게 배운것도 있는데 if문에는 원래 board.clear()가 있었다.
// 그런데 반복자를 이용하여 처음과 끝의 범위를 넘긴 board.erase()가 더 빨랐다. 왠지는 결국 못찾았으나
// 일단 알아두자.

// 자세한 설명은 주석으로 남긴다.


// 정렬을 하지 않는 map. 잊어버리지 말자.
unordered_map<string, bool> board;
int N;

void MakeAnswer()
{
    string cur;
    int answer = 0;
    for (int i = 0; i < N; ++i)
    {
        cin >> cur;
        // 새로운 누군가가 접속한다면 그 이전의 기록들은 지워버린다.
        if (cur == "ENTER")
        {
            // 상술하였듯 clear()보다 모든 범위를 넘긴 erase()가 훨씬 더 빨랐다.
            board.erase(board.begin(), board.end());
        }
        // 그렇지 않다면 cur이 이미 존재하는지 확인하고 없었다면 최종값 answer를 1 증가시키며
        // map에 추가한다.
        else
        {
            if (!board[cur])
            {
                ++answer;
                board[cur] = true;
            }
        }
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie();

    cin >> N;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}