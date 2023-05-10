#include <iostream>
#include <cstring>

using namespace std;

// 풀이.
// 트라이를 이용한 풀이다. 트라이는 물론이며 문자열 문제도 오랜만에 풀어서 조금 가물가물했다.
// 그런데 오랜만이라 그런지 구현을 잘못한건지 메모리도 속도도 오히려 트라이를 쓰지 않았을때가
// 훨씬 빨랐다. 그럼에도 불구하고 중요한 개념이며 중요한 기법들이 꽤나 사용되었기에 
// 복습할 가치는 충분했다.

// 자세한 설명은 주석으로 남긴다.

string board[10000];
int T, N;
bool isfind;

// 트라이 구현. 자세한 설명은 종만북을 찾아보자.
struct dial
{
    // 현재 단계에서 종료되었는가.
    bool isend;
    dial* child[10];

    dial() : isend(false)
    {
        memset(child, 0, sizeof(child));
    }
    ~dial()
    {
        for (int i = 0; i < 10; ++i)
            if (child[i] != nullptr)
                delete child[i];
    }

    // 트라이에 문자열을 삽입하는 함수.
    void insert(const char* key)
    {
        // 이 부분이 조금 중요한데 보통 const char * key 변수는 어떤 문자열의 맨 앞 주소값을 가진다.
        // 또한 *key는 그 문자열의 맨 앞글자를 가리킨다.
        // 또한 포인터이기에 key값이 다른 콜스택에서 변화해도 같이 변화될거 같으나
        // 실제로는 매개변수로 넘어갈때 포인터의 주소값이 복사되기에 따로 처리된다.
        // 정리하자면 다음과 같다.

        // const char * key가 있을때
        // 1. key는 포인터이며 가장 앞부분의 주소값이다.
        // 2. *key는 1번의 원리에 의해 가장 앞글자이다.
        // 3. const char * 의 매개변수 및 인자연산은 포인터값을 복사하기 때문에
        // 다른곳에서의 변화가 무시된다.

        if (*key == 0) // 주소값이라면 nullptr로 비교하는게 맞으나 주소값이 아니기에 nullptr을 뜻하는 값인 0으로 비교한다.
        {
            isend = true;
        }
        else
        {
            int idx = *key - '0';
            if (child[idx] == nullptr)
                child[idx] = new dial();

            // key의 범위가 뒤로 1칸 밀린채 매개변수로 넘어간다. ex) abcd >>>> bcd로.
            child[idx]->insert(key + 1);
        }
    }

    void find(const char* key)
    {
        if (*key == 0)
            return;

        if (isend)
        {
            isfind = true;
            return;
        }

        int idx = *key - '0';
        child[idx]->find(key + 1);
    }
};

void MakeAnswer()
{
    for (int iter = 0; iter < T; ++iter)
    {
        dial tree;
        isfind = false;
        cin >> N;
        for (int i = 0; i < N; ++i)
            cin >> board[i];

        // 여기서 트라이를 구축한다.(데이터를 삽입한다.)
        for (int i = 0; i < N; ++i)
            tree.insert(board[i].c_str());
        // for문으로 다시 board의 원소들을 순회하며 아직 다 돌지 않았는데 종료표시가 존재한다면
        // 바로 나와서 답이 존재함을 출력해도 되고 단순 bool 변수로 이미 답이 존재함을 체크만
        // 해도 된다.
        for (int i = 0; i < N; ++i)
        {
            tree.find(board[i].c_str());
            if (isfind)
                break;
        }
        if (isfind)
            cout << "NO" << '\n';
        else
            cout << "YES" << '\n';
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