#include <iostream>
#include <set>

using namespace std;

// 풀이.
// 결과적으로 자료를 저장한 배열에서 어떤 데이터를 추가하고 제외시키는 문제다.
// 다른 풀이들은 단순히 벡터를 이용하여 조건을 짜서 조금더 빠르게 풀수도 있으나
// 가장 간단한 방법은 정렬도 되고, 추가 및 삭제가 모두 되는 관련 컨테이너를 사용하는 것이 편하다.
// 특히 굳이 map이 아닌 set을 사용하는게 더 용량도 적고 처리할것도 줄어서 빠르다.

// 자세한 설명은 주석으로 남긴다.

// 사전의 역순 즉, 내림차순으로 정렬해야 한다.
set<string, greater<>> board;
int N;

void MakeAnswer()
{
    string name, stat;
    for (int i = 0; i < N; ++i)
    {
        cin >> name >> stat;
        // 현재 상태가 추가라면 추가한다.
        if (stat == "enter")
            board.insert(name);
        // 아니라면 삭제한다.
        else
            board.erase(name);
    }

    // 현재 남아있는 모든 이름들을 출력한다.
    for (auto iter : board)
        cout << iter << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}