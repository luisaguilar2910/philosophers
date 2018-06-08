class Philosopher {
	public:
		enum State { Hungry, Eating, Thinking };
		Philosopher();
		State getStatus();
		int startThinking();
		int startHungry();
		int startEating();
		int run();
	private:
		State state;
		const int maxTime = 10;
		int getRandomTime();
};
