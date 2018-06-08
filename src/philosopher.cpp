#include "philosopher.h"
#include <cstdlib>
#include <unistd.h>

Philosopher::Philosopher(){
	state = Thinking;
}

void Philosopher::run() {
}

int Philosopher::execute(){
	cout<<"P"<<this->ID<<": ";
	switch (this->state) {
		case Eating:
			cout<<"Eating..."<<endl;
		break;
		case Thinking:
			cout<<"Thinking..."<<endl;
		break;
		case Hungry:
			cout<<"Hungry..."<<endl;
		break;
	}
	sleep(getRandomTime());
};

int Philosopher::getRandomTime(){
	return rand()%maxTime +1;
}
