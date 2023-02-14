#include <iostream>
#include <stack>

using namespace std;

// 풀이
// 이 문제에서 가장 중요한것은 단 하나의 사실인데, '현재 자리수의 수가 그 다음 자리수보다 작을때에는 현재 자리수를 삭제시 무조건 커진다'이다.
// 또한, 앞자리 수가 커져야 결과적으로 수가 커지기에 인덱스 0부터 실행해야 답을 구할수 있다.
// 즉, stack을 하나 생성해서 앞에서 부터 비교하여 하나씩 채워넣는 문제이다.

// 1. stack이 비었을때에는 비교가 불가능하니 그냥 stack에 현재 원소값을 넣는다.
// 2. stack이 비어있지 않을때 맨위 원소와 현재 원소를 비교하여 현재 원소가 더 크고, K가 0이 아니라면(아직 자리수를 지울수 있다면) stack의 맨위 원소를
// 삭제한다.
// 3. 현재 원소가 더 작거나, K가 0이라면(더이상 자리수를 지울수 없다면) 그냥 stack에 넣는다.

// 이것을 주어진 원소들만큼 처리하며 순회한다. 하지만 여기서 끝이 아닌데 예를 들어 4 2 9876 같은 예시를 들면 위 연산에서 지워지는 자리수 없이
// 그대로 stack에 9876이 모두 들어가서 답을 구할수가 없다. 즉 K가 0이 되지 않은 경우가 있기에 stack에서 원소값들을 꺼내 출력하되
// 뒤에서 K개 만큼은 무시한다.

int N, K;
string board;

void MakeAnswer()
{
    // 현재값들으 저장해놓을 stack.
    stack<char> sta;
    for (int i = 0; i < board.size(); ++i)
    {
        // 현재 원소와 stack의 원소를 비교하는 반복문.
        while (true)
        {
            // 현재 stack이 비었다면 그냥 집어넣는다.
            if (sta.empty()) 
            {
                sta.push(board[i]);
                break;
            }

            // 그렇지 않다면 stack의 맨위 원소와 현재 원소를 비교한다.
            char in_sta = sta.top();
            char now = board[i];

            // 현재 원소가 더 크고 K값이 0이 아니라면(아직 지울수 있다면) stack의 현재 원소값을 지운다.
            if (in_sta < now && K > 0)
            {
                sta.pop();
                --K;
            }

            //현재 원소가 더 작거나, K값이 0이라면(더이상 지울수 없다면) stack에 집어넣는다.
            else
            {
                sta.push(now);
                break;
            }
        }
    }

    // stack에 들어가있는 값들을 꺼내 출력하되, 아직 K가 0이 아닌 경우(위에 예시를 참조), K값은 무조건 0이 되어야하므로(지워야하므로)
    // 뒤에서 K값은 무시하고 출력한다.
    string answer = "";
    while (!sta.empty())
    {
        answer += sta.top();
        sta.pop();
    }
    for (int i = answer.size() - 1; i >= K; --i)
        cout << answer[i];
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K >> board;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}