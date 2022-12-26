#include <stdio.h>
#include <stdlib.h>// rand �Լ� ����� ����
#pragma warning (disable:4996)
#include <time.h> // time �Լ� ����� ����
int main(void) {
	clock_t start, finish;
	double duration;
	start = clock(); // ���� �ð�
	for (int i = 0; i < 100; i++) {
		;
	}
	// ����ð��� �����ϰ� �ϴ� �ڵ�
	finish = clock(); // ���� �ð�
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("���� �ð�: %lf ��\n", duration);
	return;
}