// strategy.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <memory>

using namespace std;

/*
* 해결책 : 동적으로 행동을 지정하는 방법
setXXXBehavior() 메소드를 제공하여 실행 중 행동을 변경할 수 있게 개선한다 
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

//추가된 기능 
class FlyRocketPowered : public FlyBehavior {
public:
	virtual void fly() override {
		cout << "로켓 추진으로 날아갑니다~~~" << endl;
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
	FlyBehavior* _pFlyBehavior;
	QuackBehavior* _pQuackBehavior;
public:
	Duck(FlyBehavior* pFlyBehavior, QuackBehavior*pQuackBehavior) :
		_pFlyBehavior{ pFlyBehavior }, _pQuackBehavior{ pQuackBehavior } {
	}

	~Duck() {
		delete _pFlyBehavior;
		delete _pQuackBehavior;
	}

	void setFlyBehavior(FlyBehavior* pFlyBehavior) {
		if (_pFlyBehavior) {
			delete _pFlyBehavior;
		}
		_pFlyBehavior = pFlyBehavior;
	}

	void setQuackBehavior(QuackBehavior* pQuackBehavior) {
		if (_pQuackBehavior) {
			delete _pQuackBehavior;
		}
		_pQuackBehavior = pQuackBehavior;
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
	MallardDuck() : Duck{ new FlyWithWings(), new Quack() } {
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
	RubberDuck() : Duck(new FlyWithWings(), new Squeak()) {
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
*  Model 오리 
*/

class ModelDuck : public Duck {
public:
	ModelDuck() : Duck(new FlyNoWay(), new Quack()) {
	}

	virtual void display() override {
		cout << "\n================" << endl;
		cout << "난 날지 못하는 모델 오리야~~~" << endl;
		performQuack();
		performFly();
		swim();
		cout << "================\n" << endl;
	}

};

class A {
public:
	A() {}
	A(int a) {}
};

int main(int argc, char** args) {
	//int i = 10; //초기화(o), 대입 (x)
	//int j(10);//초기화(o), 대입 (x)
	//int k{10};//초기화(o), 대입 (x)
	//A obj1;
	//A obj2(10);
	//A obj3 = 10;
	//A obj4(); //함수 선언 
	//A obj5{}; //함수 선언 
	//A obj6{10}; //함수 선언 

	//i = 20; //초기화(x), 대입 (O)


	Duck* pMallard = new MallardDuck();
	pMallard->display();
	delete pMallard;

	//새롭게 추가된 기능 테스트 
	Duck* pModelDuck = new ModelDuck();
	pModelDuck->display();

	////중요함 실행중 행동을 변경함 
	////날수 있는 행동에 대한 변경
	pModelDuck->setFlyBehavior(new FlyRocketPowered());
	pModelDuck->display();
	delete pModelDuck;

	return 0;
}
