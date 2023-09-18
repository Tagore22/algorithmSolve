#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

// 풀이.
// 문자열을 뒤집어 출력하는 문제다. 다만 조건이 있다.

// 1. <>로 감싸져 있는 단어는 태그로, 뒤집지 않고 그대로 출력한다.
// 2. 태그가 아닌 단어들은 뒤집어 출력하며 공백으로 나뉘어져 있다.
// 3. 태그는 겹치지 않는다. ex) <ab<cd>>

// 모든 문자들을 순회하며 현재 문자열 cur에 하나씩 더하거나 cur을 출력후 갱신해나간다.
// 다만 여러개의 조건으로 나누어야 하는데 이 풀이에서의 조건문은 다음과 같다.

// 1. 현재 문자가 공백, '<', '>'이 아니라면 그냥 현재 문자열 cur에 더한다.
// 2. 현재 문자가 '<'이라면 태그가 시작되므로 istag를 true로 갱신한다. 또한 이전 문자가 존재했다면
// 태그는 중복될수 없으므로 단어였기에 뒤집어서 출력한후 현재 문자열 cur을 '<'로 갱신한다.
// 3. 현재 문자가 '>'이라면 여태까지 모았던 단어(태그)를 그대로 출력한후 cur을 ""(아무것도 없음)으로 갱신한후
// istag를 비활성화 시킨다.
// 4. 현재 문자가 공백일때에는 태그의 여부에 따라 나뉜다. 현재 태그라면 그대로 더하고 태그가 아니라면
// 앞에 문자열은 단어였으므로 뒤집어서 출력한후 cur을 ""로 갱신한다.
// 5. 그후 남은 문자열을 처리해야 하는데 !istag라면 단어이므로 뒤집고 출력해준다.

// 자세한 설명은 주석으로 남긴다.

string str;

void MakeAnswer()
{
    // 현재 태그의 여부 및 현재까지 저장된 문자열.
    bool istag = false;
    string cur = "";

    for (int i = 0; i < str.size(); ++i)
    {
        // 현재 문자가 공백이면서 태그가 아니라면
        // cur을 뒤집어 출력후 ""로 갱신해준다.
        if (str[i] == ' ' && !istag)
        {
            reverse(cur.begin(), cur.end());
            cout << cur << ' ';
            cur = "";
        }
        // '<'이라면 마찬가지로 cur을 뒤집어 출력하되,
        // cur을 '<'로 갱신해주고 istag를 활성화시킨다.
        else if (str[i] == '<')
        {
            istag = true;
            reverse(cur.begin(), cur.end());
            cout << cur;
            cur = str[i];
        }
        // '>'이라면 그대로 출력후, cur을 ""로 갱신하며
        // istag를 비활성화 시킨다.
        else if (str[i] == '>')
        {
            cur += str[i];
            istag = false;
            cout << cur;
            cur = "";
        }
        // 태그가 활성화되어있거나, 공백, '<', '>'가 아니라면
        // 단순히 cur에 저장한다.
        else
        {
            cur += str[i];
        }
    }
    // 끝이 공백이 아니기에 마지막 단어가 무조건 남는다.
    // istag가 비활성화된 상태라면 뒤집고 마지막 단어를 출력한다.
    if (!istag)
        reverse(cur.begin(), cur.end());
    cout << cur << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    getline(cin, str);
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}