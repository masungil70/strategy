// strategy.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <memory>

using namespace std;

/*
* 해결책 : 단일 책임의 원칙을 적용하여 행동을 구현하는 방법으로 해결
 */

class FlyBehavior {
public:
	virtual void fly() = 0;
};

class FlyWithWings : public FlyBehavior {
public:
	virtual void fly() override {
		cout << "나는 날고 있다~~~" << endl;
	}
};

class FlyNoWay : public FlyBehavior {
public:
	virtual void fly() override {
		cout << "나는 날 수 없다~~~" << endl;
	}
};

class QuackBehavior {
public:
	virtual void quack() = 0;
};

class Quack : public QuackBehavior {
public:
	virtual void quack() override {
		cout << "꽥꽥거리다~~~" << endl;
	}
};

class Squeak : public QuackBehavior {
public:
	virtual void quack() override {
		cout << "삑삑거리다~~~" << endl;
	}
};

class MuteQuack : public QuackBehavior {
public:
	virtual void quack() override {
		cout << "아무것도 하지 않음 ~~~ 소리를 낼 수 없는 경우 " << endl;
	}
};


class Duck {
private:
	FlyBehavior*   _pFlyBehavior;
	QuackBehavior* _pQuackBehavior;
public:
	Duck(FlyBehavior* pFlyBehavior, QuackBehavior* pQuackBehavior) :
		_pFlyBehavior(pFlyBehavior), _pQuackBehavior(pQuackBehavior) {
	}
	~Duck() {
		delete _pFlyBehavior;
		delete _pQuackBehavior;
	}

	void performFly() {
		_pFlyBehavior->fly();
	}

	void performQuack() {
		_pQuackBehavior->quack();
	}

	virtual void display() = 0;
	virtual void swim() {
		cout << "모든 오리는 떠다닌다 심지어 미끼까지~~~" << endl;
	}

};

class MallardDuck : public Duck {
public:
	MallardDuck() : Duck(new FlyWithWings(), new Quack()) {
	}

	virtual void display() override {
		cout << "\n================" << endl;
		cout << "나는 진짜 청둥오리야~~" << endl;
		performQuack();
		performFly();
		swim();
		cout << "================\n" << endl;
	}
};

class RedHeadDuck : public Duck {
public:
	RedHeadDuck() : Duck(new FlyWithWings(), new Quack()) {
	}

	virtual void display() override {
		cout << "\n================" << endl;
		cout << "난 진짜 빨간머리 오리야~~~" << endl;
		performQuack();
		performFly();
		swim();
		cout << "================\n" << endl;
	}
};

class RubberDuck : public Duck {
public:
	RubberDuck() : Duck(new FlyNoWay(), new Squeak()) {
	}

	virtual void display() override {
		cout << "\n================" << endl;
		cout << "난 고무 오리야~~~" << endl;
		performQuack();
		performFly();
		swim();
		cout << "================\n" << endl;
	}


};

//미끼오리 
class DecoyDuck : public Duck {
public:
	DecoyDuck() : Duck(new FlyNoWay(), new MuteQuack()) {
	}

	virtual void display() override {
		cout << "\n================" << endl;
		cout << "난 미끼 오리야~~~" << endl;
		performQuack();
		performFly();
		swim();
		cout << "================\n" << endl;
	}

};

/*
추가기능 : 동적으로 행동을 지정하는 방법
실행중 기능을 변경 할 수 있는 기능을 추가할 수 있게 기능 개선
*/

int main(int argc, char** args) {

	Duck* pMallard = new MallardDuck();
	pMallard->display();
	delete pMallard;

	Duck* pRedHeadDuck = new RedHeadDuck();
	pRedHeadDuck->display();
	delete pRedHeadDuck;

	Duck* pRubberDuck = new RubberDuck();
	pRubberDuck->display();
	delete pRubberDuck;

	Duck* pDecoyDuck = new DecoyDuck();
	pDecoyDuck->display();
	delete pDecoyDuck;

	return 0;
}
