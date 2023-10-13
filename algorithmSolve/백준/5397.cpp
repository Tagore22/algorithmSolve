#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

// 풀이.
// 문자열을 입력받아 각 조건에 따라 마지막 문자열을 출력하는 문제다.
// 각 조건은 다음과 같다.

// 1. 현재 위치를 가르키는 커서가 존재한다.
// 2. 문자열의 현재 문자가 대문자, 소문자, 숫자라면 커서 위치에 추가한다.
// 3. 화살표라면 < 일때는 커서를 1 왼쪽으로 > 이라면 1 오른쪽으로 이동시킨다.
// 4. - 이라면 현재 커서 위치 바로 앞 글자를 지운다.

// 해당 조건들을 구현만 하면 된다. 처음에는 string 형식으로 풀었는데
// 시간 초과 났다. 해당 풀이를 보면 알겠지만 to_string이나 substr등 변환 함수들이 있는데
// 매번 입력받는 문자열의 길이가 100만에 육박하기에 시간초과가 난것 같다.

// 결국에는 스택으로 풀었는데 더 간단하게 풀린것 같다.

// 자세한 설명은 주석으로 남긴다.

int T;

void MakeAnswer()
{
    string str;
    // 커서를 기준으로 앞과 뒤에 해당하는 스택들.
    stack<char> board, temp;
    for (int iter = 0; iter < T; ++iter)
    {
        cin >> str;
        // 입력받은 문자열을 순회하며 최종 문자열을 출력한다.
        for (int i = 0; i < str.size(); ++i)
        {
            // '<'일때는 커서를 왼쪽으로 이동시키는데 이것은 커서앞 문자를 커서 뒤로 이동시키는것과 같다.
            // 따라서 커서 앞이 비어있지 않다면 커서 앞 스택의 맨 윗 문자를 커서 뒤 스택으로 옮기면 된다.
            if (str[i] == '<')
            {
                if (!board.empty())
                {
                    char here = board.top();
                    board.pop();
                    temp.push(here);
                }
            }
            // '>'일때는 반대로 커서 뒤 문자를 커서 앞으로 옮기는것과 같다.
            else if (str[i] == '>')
            {
                if (!temp.empty())
                {
                    char here = temp.top();
                    temp.pop();
                    board.push(here);
                }
            }
            // '-'는 커서의 바로 앞 문자를 지우는 것이기에 커서 앞 스택의 가장 윗 문자를 지워버린다.
            else if (str[i] == '-')
            {
                if (!board.empty())
                    board.pop();
            }
            // 나머지는 모두 대문자, 소문자, 숫자이기에 현재 커서 앞 스택에 집어넣는다.
            else
            {
                board.push(str[i]);
            }
        }
        // 커서 뒷 스택이 남아있을수 있기에 모두 커서 앞 스택으로 옮겨준다.
        while (!temp.empty())
        {
            char here = temp.top();
            temp.pop();
            board.push(here);
        }
        // 그후 최종답 answer에 모두 옮긴후 역방향으로 옮겨졌기에 뒤집은 후 출력한다.
        // 여기서 이 방식 말고 board와 temp를 따로 담아도 되지만 속도차이는 크지 않았다.
        string answer = "";
        while (!board.empty())
        {
            answer += board.top();
            board.pop();
        }
        reverse(answer.begin(), answer.end());
        cout << answer << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}