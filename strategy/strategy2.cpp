// strategy.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <memory>

using namespace std;

class Duck {
public:
	Duck() {
	}

	virtual void display() = 0;

	void quack() {
		cout << "꽥꽥거리다~~~" << endl;
	}

	void swim() {
		cout << "헤엄치다~~~" << endl;
	}

	virtual void fly() {
		cout << "날다~~~" << endl;
	}

};


class MallardDuck : public Duck {
public:
	virtual void display() override {
		cout << "\n================" << endl;
		cout << "나는 진짜 청둥오리야~~" << endl;
		quack();
		swim();
		fly();
		cout << "================\n" << endl;
	}
};

class RedHeadDuck : public Duck {
public:
	virtual void display() override {
		cout << "\n================" << endl;
		cout << "난 진짜 빨간머리 오리야~~~" << endl;
		quack();
		swim();
		fly();
		cout << "================\n" << endl;
	}
};

class RubberDuck : public Duck {
public:
	virtual void fly() {
		//cout << "날다~~~" << endl;
	}

	virtual void display() override {
		cout << "\n================" << endl;
		cout << "난 고무 오리야~~~" << endl;
		quack();
		swim();
		fly();
		cout << "================\n" << endl;
	}
};

int main(int argc, char** args) {

	unique_ptr<Duck> pMallard = make_unique<MallardDuck>();
	pMallard->display();

	unique_ptr<Duck> pRedHeadDuck = make_unique<RedHeadDuck>();
	pRedHeadDuck->display();

	//데모 시연을 하는 중 망함 
	unique_ptr<Duck> pRubberDuck = make_unique<RubberDuck>();
	pRubberDuck->display();

	return 0;
}
