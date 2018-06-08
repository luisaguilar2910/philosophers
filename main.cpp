#include <iostream>
#include <vector>
#include <thread>
#include <unistd.h>
#include<algorithm>
#include "src/fork.h"
#include "src/philosopher.h"

using namespace std;

void run(Philosopher* p){
		p->execute();
}

int main(){
	Fork* forks = new Fork[5];
	Philosopher* philosophers = new Philosopher[5];
	vector<thread*> threads;
	for (int i=0; i<5; i++){
		forks[i].setID(i);
		philosophers[i].setID(i);
		thread* t = new thread(run, &philosophers[i]);
		threads.push_back(t);
	}

	for_each(threads.begin(), threads.end(), [](thread* threadP){
		threadP->join();
	});

	cout<<"Here main!"<<endl;
	delete forks;
	delete philosophers;
	return 0;
}
