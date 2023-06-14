#ifndef __WALKER_ISTATE__
#define __WALKER_ISTATE__

namespace walker {

	class Game;

	/* Interface state class.
	 *
	 * Defines standard for states.
	 * All included class are pure virtual.
	 * Only public functions included.
	 * */
	class IState {

		public:

			/* Called when state is started.
			 * */
			virtual void start() = 0;

			/* Runs main state logic.
			 *
			 * Called each time by state machine loop
			 * if state hasn't changed in the iteration.
			 * */
			virtual void step() = 0;

			/* Called when state is changing state to another.
			 * */
			virtual void stop() = 0;

	};

    /* Interface game state class.
     *
     * Defines standard for game class states.
     * All included class are pure virtual.
     * Only public functions included.
     * */
    class GameIState {

    	public:

    		/* Called when state is started.
    		 * */
    		virtual void start(Game * game) = 0;

    		/* Runs main state logic.
    		 *
    		 * Called each time by state machine loop
    		 * if state hasn't changed in the iteration.
    		 * */
    		virtual void step(Game * game) = 0;

    		/* Called when state is changing state to another.
    		 * */
    		virtual void stop(Game * game) = 0;

    };

}

#endif
