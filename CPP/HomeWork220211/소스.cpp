#include<iostream>

class mt1993 {
public:

	mt1993(ran_dev _Test2) {

	}

};

class ran_dev {
public:
	ran_dev& operator()() {

		return *this;

	}
};

int main() {

	ran_dev _Test1;
	mt1993 _Test2(_Test1());

}