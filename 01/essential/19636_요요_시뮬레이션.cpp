#include <iostream>
#include <cmath> 

using namespace std;
// 체중, 에너지 섭취량, 기초 대사량(d: 에너지 섭취량), 활동 대사량(d: 0)
// 체중 변화량 = 일일 에너지 섭취량 - 일일 에너지 소비량(기초+활동 대사)
// 기초 대사량 변화 역치 < 체중 변화량 절댓값 일 경우, 기초 대사량 + 체중 변화량 / 2 내림
// 체중이 0 이하, 기초 대사량 0 이하의 경우 사망 Danger Diet
// 기초 대사량 변화를 고려하지 않은 예상 체중, 기초 대사량
// 기초 대사량 변화를 고려한 예상 체중, 기초 대사량 요요현상이 발생할 경우 YOYO/NO 출력

struct p {
    int w0; // 체중
    int l0; // 기초 대사, 에너지 섭취량
    int a0; // 활동 대사
    int t; // 역치
    int d; // 다이어트 기간
    int l; // 다이어트 기간 중 에너지 섭취량
    int a; // 다이어트 기간 중 활동 대사량
    int w1; // 다이어트 후 체중
    int l1; // 다이어트 후 기초 대사
}
int main() {
    p dash;
    
    // 초기값 입력
    cin >> dash.w0 >> dash.l0 >> dash.t;
    cin >> dash.d >> dash.l >> dash.a;

    // 기초 대사량 변화를 고려하지 않은 경우
    dash.w1 = dash.w0 + (dash.l - dash.l0 - dash.a) * dash.d;
    
    if (dash.w1 <= 0) {
        cout << "Danger Diet" << '\n';
    } else {
        cout << dash.w1 << ' ' << dash.l0 << '\n';
    }

    // 기초 대사량 변화를 고려한 경우
    int weight = dash.w0;
    int metabolism = dash.l0;
    int energy_change = 0;

    for (int i = 0; i < dash.d; i++) {
        int daily_change = dash.l - metabolism - dash.a;
        weight += daily_change;

        if (abs(daily_change) > dash.t) {
            metabolism += floor(daily_change / 2.0);
        }

        // 체중 및 기초 대사량이 0 이하인 경우 예외 처리
        if (weight <= 0 || metabolism <= 0) {
            cout << "Danger Diet" << '\n';
            return 0;
        }
    }

    cout << weight << ' ' << metabolism << ' ';

    // 요요 여부 판단
    if (dash.l0 > metabolism) {
        cout << "YOYO" << '\n';
    } else {
        cout << "NO" << '\n';
    }

    return 0;
}
