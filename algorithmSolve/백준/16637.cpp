#include <iostream>
#include <string>
#include <stack>

using namespace std;

// 풀이.
// 오랜만에 정말 거지같은 문제를 만났다. 거지같다.
// 나중에 알고보니 삼성 문제였다. 거지같다.
// 예전부터 이건 대체 뭔지 하고 넘어갔던 문제인데 시간이 오래걸렸어도 결국엔 스스로 풀었기에 나름 거지같지만 만족한다.
// 조건부터 주의해야할점이 산더미처럼 쌓여있다. 오랜만에 어려운 문제를 푼것 같다.

// 문제자체는 크게 어렵지 않다. 괄호를 넣을수 있는 모든 경우를 사용해서 가장 큰 결과값을 출력하는 것인데 조건이 몇가지 붙어있다.

// 1. 하나의 괄호안에는 하나의 연산자만이 존재할수 있다. 즉 (1*2*3) 같은것은 불가능하다.
// 2. 문제에 제시되었듯 괄호는 중복이 불가능하다. ex((1*2)-3)

// 위 조건을 피해서 순회할수 있는 모든 경우를 해야한다. 또한 주의해야할점이 매우 많은데
// 주석을 통해서 남겨야할정도로 많다.

// 가장 처음에 풀었을때 이상하게 안되는 반례들이 몇가지 있었는데 문제는 괄호를 사용하지 않은 경우를 처리하지 않았기 때문이다.
// 기존의 틀린 풀이들을 보면 전부 괄호를 모두 사용하는 경우만 순회되어 있다. 이것을 놓쳤었다.

// 자세한 설명은 주석으로 남긴다.

string str;
int N, answer;

// 연산자가 겹치는 경우(1 * -1등의 경우)에 이전에 스택에 들어있는 것이 연산자인지 숫자인지 확인하는 함수.
bool CheckPunct(const string& str)
{
    if ('0' <= str[str.size() - 1] && str[str.size() - 1] <= '9')
        return false;
    return true;
}

// 현재 수식의 결과값을 도출하는 함수.
int CalSum(const string& str)
{
    stack<string> sta;
    int oper = 0;
    bool isminus;
    // 큰틀은 다음과 같다.
    // 1. 문자열을 순회한다.
    // 2. 현재값이 숫자일경우
    // 2-1. 스택이 비어있거나(첫번째 수의 등장) 이전의 들어있는 값이 숫자이거나(현재 수가 1자리가 아닌경우)
    // 혹은 현재수가 음수라서 이전값이 연산자(-)일 경우에는 이전값을 불러내 하나로 합쳐서 새로 집어넣는다.
    // 2-2. 그렇지 않은 경우 현재값이 음수가 아닌 상황에서 이전값이 연산자이거나, 스택이 빈경우이기에 그냥 집어넣는다.
    // 2-3. 그후 들어오는 값은 무조건 다음 연산을 위한 연산자이므로 isminus를 false로 갱신해주어 다음 연산자를 체크한다.
    // 3. 현재값이 연산자일 경우
    // 3-1. 스택이 비어있거나, 이전값이 이미 연산자(-)일 경우 현재값은 무조건 음수가 되므로 isminus를 true로 갱신해주고 현재 입력받은
    // 연산자의 수를 저장하는 oper를 1 감소해주어 현재 저장한 연산자는 연산자가 아닌 음수를 위한 연산자임을 체크한다.
    // 3-2. 그후 oper를 1 증가하여 연산자를 저장함을 체크한다.
    // 3-3. 만약 oper가 2라면 피연산자 2개와 연산자 1개를 모두 저장한 상태이므로 연산이 가능하다.
    // 먼저 저장한 값 3개를 꺼내어 계산한후 스택에 집어넣고 현재값을 저장한다.
    // 4. 순회가 끝난후 마지막 스택에 남은값들을 계산한후 반환한다.

    // 모든 값들을 순회한다.
    for (int i = 0; i < str.size(); ++i)
    {
        if ('0' <= str[i] && str[i] <= '9')
        {
            if (!sta.empty() && (!CheckPunct(sta.top()) || isminus))
            {
                string pre = sta.top();
                sta.pop();
                sta.push(pre + str[i]);
            }
            else
            {
                sta.push(to_string(str[i] - '0'));
            }
            isminus = false;
        }
        else
        {
            if (sta.empty() || !sta.empty() && CheckPunct(sta.top()))
            {
                isminus = true;
                --oper;
            }
            ++oper;
            if (oper == 2)
            {
                string second = sta.top();
                sta.pop();
                string ope = sta.top();
                sta.pop();
                string first = sta.top();
                sta.pop();

                int f = stoi(first);
                int s = stoi(second);

                if (ope == "+")
                    sta.push(to_string(f + s));
                else if (ope == "-")
                    sta.push(to_string(f - s));
                else
                    sta.push(to_string(f * s));
                oper = 1;
            }
            sta.push(str.substr(i, 1));
        }
    }
    string second = sta.top();
    sta.pop();
    string ope = sta.top();
    sta.pop();
    string first = sta.top();
    sta.pop();

    int f = stoi(first);
    int s = stoi(second);

    if (ope == "+")
        sta.push(to_string(f + s));
    else if (ope == "-")
        sta.push(to_string(f - s));
    else
        sta.push(to_string(f * s));
    return stoi(sta.top());
}

// 모든 경우의 수를 순회하는 함수.
void BackTrack(int idx, const string str)
{
    for (int i = idx; i < str.size() - 2; i += 2)
    {
        // i와 i + 2까지를 복사하여 계산함수에 넘겨 그값을 받는다.
        // 그 값을 i + 3부터 끝까지 복사한값과 합쳐서 
        // BackTrack의 두번째 매개변수로 넘긴다.
        // idx는 2가 증가되어 넘어간다.
        int cur = CalSum(str.substr(i, 3));
        string next = to_string(cur);
        BackTrack(i + 2 + next.size() - 1, str.substr(0, i) + next + str.substr(i + 3));
    }

    // 이후 괄호를 사용하지 않은 경우를 확인한다.
    answer = max(answer, CalSum(str));
}

void MakeAnswer()
{
    // N이 1인 경우와 3인 경우를 따로 처리해주어야한다.
    if (N == 1)
    {
        cout << str[0] << '\n';
        return;
    }
    else if (N == 3)
    {
        cout << CalSum(str) << '\n';
        return;
    }
    answer = CalSum(str);
    BackTrack(0, str);
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> str;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}