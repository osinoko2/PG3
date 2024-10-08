#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

typedef void (*PFunc)(int*);

void Result(int* s) {
	printf("%d秒待って実行されたよ\n", *s);
}

void setTimeout(PFunc p, int second) {
	Sleep(second * 1000);

	p(&second);
}

int main() {
	int dice = rand() % 6 + 1;
	int isDiceThrow;
	PFunc p;
	p = Result;

	printf("サイコロの目は奇数だと思うなら1、偶数だと思うなら2を押してください\n");
	scanf_s("%d", &isDiceThrow);

	setTimeout(p, 3);

	if (dice % 2 == 0){
		if (isDiceThrow == 1)
		{
			printf("不正解");
		}
		if (isDiceThrow == 2)
		{
			printf("正解");
		}
	} else if(dice % 2 == 1){
		if (isDiceThrow == 1)
		{
			printf("正解");
		}
		if (isDiceThrow == 2)
		{
			printf("不正解");
		}
	}

	return 0;
}