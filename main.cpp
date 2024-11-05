#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <functional>

typedef void (*PFunc)(int*);

void result(int* s) {
	printf("%d秒待って実行されたよ\n", *s);
}

void setTimeout(PFunc p, int second) {
	Sleep(second * 1000);

	p(&second);
}

class Enemy
{
public:
	// 状態遷移関数
	void Approach();
	void Shot();
	void Separation();
	void Update();
private:
	static void (Enemy::* sphaseTable[])();
	enum Phase
	{
		approachPhase,
		shotPhase,
		separationPhase
	};

	Phase phase_ = Phase::approachPhase;
};

// フェーズの関数テーブル
void (Enemy::* Enemy::sphaseTable[])() = {
	&Enemy::Approach, // 接近
	&Enemy::Shot, // 射撃
	&Enemy::Separation // 離脱
};

void Enemy::Approach()
{
	printf("敵が近づいてきた!\n");

	phase_ = Phase::shotPhase;
}

void Enemy::Shot()
{
	printf("敵が弾を発射した!\n");

	phase_ = Phase::separationPhase;
}

void Enemy::Separation()
{
	printf("敵が離れていく...\n");
}

void Enemy::Update() {
	(this->*sphaseTable[static_cast<size_t>(phase_)])();
}

Enemy enemy;

int main(int argc, const char *argv[]) {
	enemy.Update();
	enemy.Update();
	enemy.Update();

	return 0;
}