#ifndef FORK_LIB
#define FORK_LIB
class Fork {
	private:
		int ID;
		bool status;
		int philosopherID;
	public:
		Fork();
		Fork(int, int);
		bool isUsing(){return status;};
		int getPhilosopherID() {return philosopherID;};
		int getID() {return ID;};
		void changeStatus () {status = !status;};
		void setID(int ID){this->ID = ID;};
		void setPhilosopherID(int philosopherID){this->philosopherID = philosopherID;};
};
#endif
