#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

typedef void (*PFunc)(int*);

void DispResult(int* s) {
	printf("%d秒待って実行されたよ\n", *s);
}

void setTimeout(PFunc p, int second) {
	Sleep(second * 1000);

	p(&second);
}

int main() {
	int dice = rand() % 6 + 1;
	int isDice;
	PFunc p;
	p = DispResult;

	printf("サイコロの目は奇数だと思うなら1、偶数だと思うなら2を押してください\n");
	scanf_s("%d", &isDice);

	setTimeout(p, 3);

	if (dice % 2 == 0){
		if (isDice == 1)
		{
			printf("不正解");
		}
		if (isDice == 2)
		{
			printf("正解");
		}
	} else if(dice % 2 == 1){
		if (isDice == 1)
		{
			printf("正解");
		}
		if (isDice == 2)
		{
			printf("不正解");
		}
	}

	return 0;
}