#include "fork.h"

Fork::Fork(int ID, int philosopherID){
	this->ID = ID;
	this->philosopherID = philosopherID;
	this->status = false;
}

Fork::Fork(){
	this->ID = -1;
	this->philosopherID = -1;
	this->status = false;
}

void Fork::printData(){
	cout<<this->ID<<": "<<this->philosopherID<<", "<<this->status<<endl;
}
