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
			sleep(getRandomTime());
		break;
		case Thinking:
			cout<<"Thinking..."<<endl;
			sleep(getRandomTime());
		break;
		case Hungry:
			cout<<"Hungry..."<<endl;
			//look for unused fork
			//wait for unused fork
		break;
	}
};

int Philosopher::getRandomTime(){
	return rand()%maxTime +1;
}
