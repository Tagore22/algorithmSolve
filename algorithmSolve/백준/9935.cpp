#include <iostream>
#include <vector>

using namespace std;

// 풀이.
// 스택을 모방한 형식으로 풀면 된다.
// 앞에서부터 알파벳을 하나씩 벡터에 저장하다가 벡터의 크기가 폭탄의 크기만큼
// 커지면 현재 저장된 알파벳과 폭탄을 비교하여 같다면 폭탄만큼 저장된 내용을
// 제거하고 같지 않다면 무시한다. 이것을 주어지는 알파벳의 길이만큼 반복하면 된다.

string board, bomb;
vector<char> answer;
int bsize;

void CheckBomb()
{
    int asize = answer.size();
    for (int i = 0; i < bsize; ++i)
    {
        if (answer[asize - bsize + i] != bomb[i])
            return;
    }

    for (int i = 0; i < bsize; ++i)
        answer.pop_back();
}

void MakeAnswer()
{
    bsize = bomb.size();

    for (int i = 0; i < board.size(); ++i)
    {
        answer.push_back(board[i]);
        if (answer.size() >= bsize)
            CheckBomb();
    }

    if (answer.empty())
        cout << "FRULA";
    else
        for (int i = 0; i < answer.size(); ++i)
            cout << answer[i];

    cout << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> board >> bomb;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}