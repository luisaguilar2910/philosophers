#include <iostream>
#include <vector>
#include <thread>
#include <unistd.h>
#include <algorithm>
#include <mutex>
#include "src/fork.h"
#include "src/philosopher.h"

using namespace std;

static mutex m;

void run(Philosopher* p){
	while(1){
		p->execute(&m);
	}
}

void printInfo(Philosopher* philosophers, Fork* forks){
	while(1){
		for(int i=0;i<5;i++){
			philosophers[i].printData();
		}
		cout<<endl;
		{
			lock_guard<mutex> lock(m);
			for(int i=0;i<5;i++){
				forks[i].printData();
			}
		}
		cout<<endl;
		sleep(1);
	}
}

int main() {
	Fork* forks = new Fork[5];
	Philosopher* philosophers = new Philosopher[5];
	srand(time(0));

	vector<thread*> threads;

	for(int i=0; i<5; i++){
		forks[i].setID(i);
		forks[i].setPhilosopherID(-1);
	}

	for (int i=0; i<5; i++){
		philosophers[i].setID(i);
		philosophers[i].setRight(&forks[i]);
		philosophers[i].setLeft(&forks[(i+1) % 5]);
		philosophers[i].printData();
		thread* t = new thread(run, &philosophers[i]);
		threads.push_back(t);
	}

	thread* t = new thread(printInfo, philosophers, forks);
	threads.push_back(t);

	for_each(threads.begin(), threads.end(), [](thread* threadP){
		threadP->join();
	});

	cout<<"Here main!"<<endl;
	delete forks;
	delete philosophers;
	return 0;
}
