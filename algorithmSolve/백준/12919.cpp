#include <iostream>
#include <algorithm>

using namespace std;

// 풀이.
// 주어진 규칙에 따라 a를 b로 변환이 가능한지를 찾는 문제이다.
// b의 길이가 최대 50이기 때문에 a가 1이라면 1번과 2번 조건을 모두 탐색할시
// 최대 2의 50제곱의 연산량을 필요로 하기 때문에 시간내에 풀수 없다.
// 따라서 반대로 b에서 a로 줄여나간다면 부합되지 않는 조건들을 걸러내어
// 연산량을 줄일수 있다.

// 자세한 설명은 주석으로 남긴다.

string a, b;
bool isFind = false;

void BackTrack(string& str)
{
    // 이미 만들수 있다면 다른 모든 경우를 무시한다.
    // 여기서 1을 출력하고 exit(0)으로 탈출해도 무방하다.
    if (isFind)
        return;
    // 현재 문자열과 a의 길이가 같을때
    if (str.size() == a.size())
    {
        // 둘이 같다면 변환가능.
        if (str == a)
            isFind = true;
        return;
    }
    // 맨뒤가 A라면 A를 지워보고 그 이전으로 가본다.
    if (str[str.size() - 1] == 'A')
    {
        string temp(str.begin(), str.end() - 1);
        BackTrack(temp);
    }
    // 맨앞이 B라면 B를 지우고 뒤집어 그 이전으로 가본다.
    if (str[0] == 'B')
    {
        string temp(str.begin() + 1, str.end());
        reverse(temp.begin(), temp.end());
        BackTrack(temp);
    }
}

void MakeAnswer()
{
    BackTrack(b);
    cout << (isFind ? 1 : 0) << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> a >> b;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}