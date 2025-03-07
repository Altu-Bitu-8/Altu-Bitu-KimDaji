#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;
//namespace에 있는 클래스에 정의되어 있는 함수들을 사용하겠다. std::cout이라고 쓰지 않아도 된다.

int checkSubString(string str) {
    // 부분 문자열을 생성한 뒤 이를 set에 넣고 set의 크기를 리턴하는 함수
    set<string> s;
    // 문자열을 원소로 갖는 set 선언
    int len = str.length(); 
    // 반복문에서 매번 length 함수를 호출하지 않기 위해 선언한다

    for (int i = 0; i < len; i++) {
        // 부분 문자열이 시작하는 위치: 0 ~ len-1
        for (int j = len - i; j >= 1; j--) { 
            // i번째에서 시작한 부분 문자열의 길이: 1 ~ len-i
            string substr = str.substr(i, j);
            // 부분 문자열을 구하는 함수 substr
            s.insert(substr);
            // set에 부분 문자열을 저장하여 중복 방지
        }
    }

    return s.size();
    // set에 저장된 원수의 개수(= 서로 다른 부분 문자열의 개수) 반환 
}

int main() {
    ios_base::sync_with_stdio(false);
    //C와 C++ 스타일을 혼용할 수 없는 대신에 입출력 속도가 빨라진다
    cin.tie(NULL);
    //cin과 cout을 묶어주는 과정을 생략하여 시간이 절약된다

    string str;
    //문자열을 입력받을 변수 선언
    
    cin >> str;
    // 입력
    
    cout << checkSubString(str);
    // 정답 출력
}