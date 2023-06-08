#ifndef __WALKER_GAME__
#define __WALKER_GAME__

#include <cstdint>
#include <gmap.hpp>

// Namespace of project.
namespace walker {
	
	class Game;
	
	/* Checks for all critical dependencies of the game.
	 * */
	class Launcher {
		public:

			/* Adds a map object to the game. 
			 *
			 * @param a map object.
			 * */
			void add_map(const Map& map);

			/* Checks if everythink is ready for creating the game instance.
			 *
			 * If all dependencies has been added and none of the has
			 * errors then signals that launcher is ready for creating the game.
			 *
			 * @return 0 if no error occured otherwise error code.
			 * */
			std::uint_least16_t is_ok();	
	
			/* Creates game object.
			 *
			 * If every critacal dependency has been added then function will
			 * return a game object. Only one game object should be alive.
			 *
			 * @return true if game created successfully.
			 * */	
			Game create_game();
	
		private:

			// Ensures that only one game instance is created.
			bool _game_created = false;

	};
	
	/* Game class should act like compositor.
	 * Provides interface for managing game entities.
	 * */
	class Game {

		public:

			/* Steps the game by one step.
			 *
			 * @return true if no error occured.
			 * */
			bool step();

			/* Polls input from user.
			 *
			 * Must be called in thread otherwise will freeze the game.
			 * */
			void poll_input();

			/* Checks if game should be closed.
			 *
			 * @return the state of the _should_run_flag.
			 * */
			bool should_run() const;
	
			/* Returns error code.
			 * 
			 * If any error inside the game instance has occured, you can poll
			 * it's error code via this function.
			 *
			 * @return error code.
			 * */
			std::uint_least16_t poll_error();
	
				
		private:
			// Disable constructor.
			Game();

			// Flag that indicates if game should be closed.
			bool _should_run_flag;

	};
}

#endif
