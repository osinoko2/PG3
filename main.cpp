#include <stdio.h>

int Recursive(int time, int money){
	if(time <= 1){
		return (100);
	}

	money = money * 2 - 50;

	return (money + Recursive(time - 1, money));
}

int main() {
	int time = 8;
	int money = 100;
	int salary = 1072;
	int result;
	int result2;

	result = salary * time;
	result2 = Recursive(time, money);

	printf("一般的な賃金体系で%d時間 = %d\n", time, result);
	printf("再帰的な賃金体系で%d時間 = %d", time, result2);

	return 0;
}