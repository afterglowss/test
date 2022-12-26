#include <stdio.h>
#include <stdlib.h>// rand 함수 사용을 위해
#pragma warning (disable:4996)
#include <time.h> // time 함수 사용을 위해
int main(void) {
	clock_t start, finish;
	double duration;
	start = clock(); // 시작 시각
	for (int i = 0; i < 100; i++) {
		;
	}
	// 수행시간을 측정하고 하는 코드
	finish = clock(); // 종료 시각
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("실행 시간: %lf 초\n", duration);
	return;
	//vrs
}