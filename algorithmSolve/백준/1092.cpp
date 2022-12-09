#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//정렬기준을 잘못잡아 한참 해맸다. 정신차리자 T^T

//풀이
//처음엔 박스들을 오름차순으로 정렬하고 스택을 이용하여 앞에서 부터 한개씩 옮기는 것을 생각했는데 
//그 반례가 3 6 8 9 6 2 4 4 9 9 였다. 가장 무거운 것은 9하나밖에 못 옮기기에 답이 2가 아닌 3이 나왔었다.
//가장 빠르게 박스들을 옮기는 그리디식 접근은 각 크레인이 현재 옮길수 있는 박스중 가장 무거운 박스들부터 옮기는 것이다.
//그렇기에 두 배열을 모두 내림차순으로 정렬하여 둘의 최대값을 비교하여 예외 상황을 검출하고, 상술했듯이 크레인에서 현재 옮길수 있는
//가장 무거운 박스를 옮긴다. 크레인들의 순회가 한번 끝나면 최종 답인 answer을 1씩 옮기어 모든 순회가 끝나면 출력한다.

vector<int> cranes;
vector<int> board;
int N, M;

void MakeAnswer()
{
    sort(board.begin(), board.end(), greater<>());
    sort(cranes.begin(), cranes.end(), greater<>());

    if (board[0] > cranes[0])
    {
        cout << -1 << '\n';
        return;
    }

    int answer = 0;
    while (!board.empty())
    {
        for (int i = 0; i < N; ++i)
        {
            if (board.empty())
                break;
            for (int j = 0; j < board.size(); ++j)
                if (cranes[i] >= board[j])
                {
                    board.erase(board.begin() + j);
                    break;
                }
        }
        ++answer;
    }

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    int num;
    for (int i = 0; i < N; ++i)
    {
        cin >> num;
        cranes.push_back(num);
    }

    cin >> M;
    for (int i = 0; i < M; ++i)
    {
        cin >> num;
        board.push_back(num);
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}