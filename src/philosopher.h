#include<iostream>
using namespace std;

class Philosopher {
	public:
		enum State { Hungry, Eating, Thinking };
		Philosopher();
		void setID(int ID){this->ID = ID;};
		State getStatus();
		int startThinking();
		int startHungry();
		int startEating();
		void run();
		const unsigned int maxTime = 5;
		int changeStatus(State state);
		int execute();
		int ID;
	private:
		State state;
		int getRandomTime();
};
