#include <iostream>
#include <stack>

using namespace std;

// 풀이.
// 스택을 이용하여 순서대로 수를 꺼낼수 있는지를 확인하는 문제다.
// 그리 어려운 문제는 아니나 아마 스택과 연결시키기가 힘들어 정답율이 낮은듯 하다.
// 결과적으로 직선줄 a와 옆줄 b가 있을때 먼저 b에 현재 번호가 맨앞에 있는지 확인하고
// 없다면 a를 전부 비워가며 현재 번호를 찾으면 된다. 만약 a를 전부 찾았음에도 
// 현재 번호가 없다면 b의 뒷부분에 있다는 것이기에 순서대로 수를 꺼낼수 없다.

// 자세한 설명은 주석으로 남긴다.

stack<int> a, b;
int board[1000];
int N;

void MakeAnswer()
{
    // 거꾸로 스택에 집어넣는다.
    for (int i = N - 1; i >= 0; --i)
        a.push(board[i]);
    // N명을 세워야 하기에 최대 N번을 순회한다.
    for (int i = 1; i <= N; ++i)
    {
        // b가 비어있지 않다면 먼저 확인한다.
        // 다만 b에서 a로의 이동은 불가능하기에 맨앞만 확인한다.
        // b에 맨앞에 현재 번호가 존재한다면 이동하고 i번째 이동은 끝난다.
        if (!b.empty())
        {
            // b의 맨앞 번호를 확인한다.
            int here = b.top();
            // 그 번호가 현재 번호 i와 동일하다면.
            if (here == i)
            {
                // b에서 탈출하고 i + 1번째 순회를 시작한다.
                b.pop();
                continue;
            }
        }
        // b에서 찾지 못했을 경우.
        bool isFind = false;
        // a를 전부 찾아본다.
        while (!a.empty())
        {
            // a의 맨앞 번호를 찾아본다.
            int here = a.top();
            a.pop();
            // 그 번호가 현재 번호 i와 동일하다면.
            if (here == i)
            {
                // a에서 탈출하고 i + 1번째 순회를 시작한다.
                isFind = true;
                break;
            }
            // 아니라면 b로 옮기고 다시 a를 찾아본다.
            b.push(here);
        }
        // 만약 a를 전부 찾아봤음에도 i를 찾지 못했다면 b의 뒷부분에 존재하는데
        // 이러면 순서대로 세울수 없으므로 "Sad"를 출력하고 프로그램을 끝낸다.
        if (!isFind)
        {
            cout << "Sad" << '\n';
            return;
        }
    }
    // 마지막까지 전부 순서대로 찾았다면 "Nice"를 출력하고 프로그램을 끝낸다.
    cout << "Nice" << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}