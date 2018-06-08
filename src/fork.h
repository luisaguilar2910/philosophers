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
		void changeStatus () {status = !status;};
};
