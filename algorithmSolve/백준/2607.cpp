#include <iostream>

using namespace std;

// 풀이.
// 정답율이 보여주듯 매우 번거로운 문제였다. 두 문자열이 주어질때 어떤 문자열의 한 단어를 추가하거나 제외하거나
// 바꾸어서 나머지 한 문자열과 같은 길이, 같은 종류의 문자수를 유지할수 있는지를 묻는 문제다.
// 여러가지 가지치기를 이용해서 최대한 연산량을 줄여야 하는데 다음과 같다.

// 1. 애시당초 두 문자열의 길이가 2이상 차이난다면 불가능하다.
// 2. 두 문자열이 어떠한 알파벳 A를 지닌 수가 2이상 차이난다면 불가능하다. 

// 이 2가지 가지치기를 이용해서 모든 경우의 수를 순회해야 한다. 또한 두 문자열의 길이 차이에 따라 또 나뉘어진다.

// 자세한 설명은 주석으로 남긴다.

int checkstr1[26];
string str1, str2;
int N, size1, size2, num = 0;

// 두 문자열을 비교하여 비슷한 구성인지 확인하는 함수.
bool CompareStr()
{
    int checkstr2[26];
    for (int i = 0; i < 26; ++i)
        checkstr2[i] = 0;
    // 현재 문자열을 구성하는 알파벳과 그 수를 저장한다.
    for (int i = 0; i < size2; ++i)
        ++checkstr2[str2[i] - 'A'];
    int diff, ans = 0;
    // 모든 알파벳을 순회하며 각 문자열이 지닌 해당 알파벳의 수를 비교한다.
    // 만약 어떠한 알파벳에서 2이상 차이가 난다면 변환하여도 비슷한 구성이 되지 않기에
    // false를 출력하고 탈출한다.
    for (int i = 0; i < 26; ++i)
    {
        diff = abs(checkstr1[i] - checkstr2[i]);
        if (diff >= 2)
            return false;
        ans += diff;
    }
    // 두 문자열의 길이가 같다면 차이가 0이거나 2일때(모두 같고 다른 알파벳 한개씩을 가지고 있을때 ex) DOG, DOH)
    // 비슷한 구성을 만들수 있다.
    if (size1 == size2)
        return ans == 0 || ans == 2 ? true : false;
    // 두 문자열이 길이가 1이 차이날때 차이는 1보다 작거나 같아야만 비슷한 구성을 만들수 있다.
    else
        return ans <= 1 ? true : false;
}

void MakeAnswer()
{
    size1 = str1.size();
    // 첫번째 문자열을 구성하는 알파벳과 그 수를 저장한다.
    for (int i = 0; i < size1; ++i)
        ++checkstr1[str1[i] - 'A'];
    int answer = 0;
    // N - 1개의 문자열을 입력받아 비교해본다.
    for (int iter = 1; iter < N; ++iter)
    {
        cin >> str2;
        size2 = str2.size();
        if (abs(size1 - size2) >= 2)
            continue;
        answer = CompareStr() ? answer + 1 : answer;
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> str1;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}