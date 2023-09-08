#include <iostream>
#include <cstring>

using namespace std;

// 풀이.
// 백트래킹을 사용하여 만들수 있는 모든 순열을 만드는 문제이다.
// bool 배열을 이용하여 현재 원소가 이전에 사용되었는지 확인해가며 모든 원소들을
// 순회하면 된다.

// 속도가 조금 느린감이 없지 않아 다른 풀이들을 확인해보았는데
// 똑같은데 속도가 4, 28 이렇게나 차이가 났다. 풀이를 아예 복사 붙여넣기로 해도 
// 차이가 났다. 서버에 따라서 결과가 차이나는 것 같다. 정말 엄청 크지 않다면
// 신경쓰지 말자.

// 자세한 설명은 주석으로 남긴다.

int answer[8];
bool check[8];
int N;

// 백트래킹으로 모든 결과를 순회하는 함수.
void BackTrack(int idx)
{
    // N - 1개의 원소값을 모두 모았다면 현재 순열을 출력한후 탈출한다.
    if (idx == N)
    {
        for (int i = 0; i < N; ++i)
            cout << answer[i] << ' ';
        cout << '\n';
        return;
    }

    // 모든 원소값을 오름차순으로 순회하며 아직 사용하지 않은 원소들을 
    // 순열에 포함시켜나간다.
    for (int i = 1; i <= N; ++i)
    {
        if (check[i - 1])
            continue;

        check[i - 1] = true;
        answer[idx] = i;
        BackTrack(idx + 1);
        check[i - 1] = false;
    }
}

void MakeAnswer()
{
    memset(check, false, sizeof(check));
    BackTrack(0);
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