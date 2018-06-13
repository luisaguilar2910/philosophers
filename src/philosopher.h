#include<iostream>
#include <mutex>
#include "fork.h"
using namespace std;

#ifndef PHILOSOPHER_LIB
#define PHILOSOPHER_LIB
class Philosopher {
	public:
		enum State { Hungry, Eating, Thinking };
		Philosopher();
		void setID(int ID){this->ID = ID;};
		State getStatus();
		int startThinking();
		int startHungry();
		int startEating();
		void printData();
		void run();
		const unsigned int maxTime = 10;
		int changeStatus(State state);
		int execute(mutex* m);
		int ID;
		Fork* getRight() {return right;};
		Fork* getLeft() {return left;};
		void setRight(Fork* right){this->right = right;};
		void setLeft(Fork* left){this->left = left;};
	private:
		State state;
		int getRandomTime();
		Fork* right;
		Fork* left;
};
#endif
