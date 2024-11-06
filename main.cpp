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

template <typename Type1, typename Type2>

class Calc {
public:
	static void Min(Type1 a, Type2 b);
};

template <typename Type1, typename Type2>
void Calc<Type1, Type2>::Min(Type1 a, Type2 b) {

	if (a > b) {

		if (typeid(b) == typeid(int)) {
			printf("%d\n", b);

			return;
		} else if (typeid(b) == typeid(float)) {
			printf("%.02f\n", b);

			return;
		} else {
			printf("%.02lf\n", b);

			return;
		}
	} else if (a < b) {

		if (typeid(a) == typeid(int)) {
			printf("%d\n", a);

			return;
		} else if (typeid(a) == typeid(float)) {
			printf("%.02f\n", a);

			return;
		} else {
			printf("%.02lf\n", a);

			return;
		}
	} else {

		printf("同じ値です\n");
	}
}

class IShape
{
public:
	virtual void Size();
	virtual void Draw();

private:
};

void IShape::Size()
{
}

void IShape::Draw()
{
}

class Circle : public IShape
{
public:
	void Size() override;
	void Draw() override;

private:
};

void Circle::Size()
{
}

void Circle::Draw()
{
}

class Rectangle : public IShape
{
public:
	void Size() override;
	void Draw() override;

private:
};

void Rectangle::Size()
{
}

void Rectangle::Draw()
{
}

Enemy enemy;

int main(int argc, const char *argv[]) {
	int a = 5;
	int b = 25;
	float c = 12.4f;
	float d = 12.3f;
	double e = 255.9;
	double f = 256.2;

	Calc<int, int>::Min(a, b);
	Calc<float, float>::Min(c, d);
	Calc<double, double>::Min(e, f);

	return 0;
}