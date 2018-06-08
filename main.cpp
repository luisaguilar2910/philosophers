#include <iostream>
#include "src/fork.h"
#include "src/philosopher.h"

using namespace std;

int main(){
	Fork* forks = new Fork[5];
	Philosopher* philosophers = new Philosopher[5];
		cout<<"Dinner Time"<<endl;
	delete forks;
	delete philosophers;
	return 0;
}
