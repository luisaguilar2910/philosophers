#include "philosopher.h"
#include <cstdlib>
#include <unistd.h>
#include <mutex>

Philosopher::Philosopher(){
	state = Thinking;
}

void Philosopher::run() {
}

void Philosopher::printData(){
	cout<<"ID: "<<this->ID<<" Status: [";
	switch (this->state) {
		case Thinking:
			cout<<"Thinking]"<<endl;
			break;
		case Eating:
			cout<<"Eating]"<<endl;
			break;
		case Hungry:
			cout<<"Hungry]"<<endl;
			break;
	}
}

int Philosopher::execute(mutex* m){
	switch (this->state) {
		case Eating:
			//cout<<"P"<<this->ID<<": "<<"Eating..."<<endl;
			sleep(getRandomTime());
			{
				lock_guard<mutex> lock(*m);
				this->right->setPhilosopherID(-1);
				this->right->changeStatus();
				this->left->setPhilosopherID(-1);
				this->left->changeStatus();
			}
			this->state = Thinking;
		break;
		case Thinking:
			//cout<<"P"<<this->ID<<": "<<"Thinking..."<<endl;
			sleep(getRandomTime());
			this->state = Hungry;
		break;
		case Hungry:
			{
				lock_guard<mutex> lock(*m);
				if(!this->right->isUsing() && !this->left->isUsing()){
					cout<<"Taking: "<<this->right->getPhilosopherID()<<" and "<<this->left->getPhilosopherID()<<endl;
					this->right->setPhilosopherID(this->ID);
					this->right->changeStatus();
					this->left->setPhilosopherID(this->ID);
					this->left->changeStatus();
					this->state = Eating;
				}
			}
		break;
	}
};

int Philosopher::getRandomTime(){
	return rand()%maxTime +1;
}
