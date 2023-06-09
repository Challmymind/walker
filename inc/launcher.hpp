#ifndef __WALKER_LAUNCHER__
#define __WALKER_LAUNCHER__

#include <gmap.hpp>

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
			void add_map(Gmap * map);

			/* Checks if everythink is ready for creating the game instance.
			 *
			 * If all dependencies has been added and none of the has
			 * errors then signals that launcher is ready for creating the game.
			 *
			 * @return true if no error occured.
			 * */
			bool is_ok() const;	
	
			/* Creates game object.
			 *
			 * If every critacal dependency has been added then function will
			 * return a game object. Only one game object should be alive.
			 *
			 * @return true if game created successfully.
			 * */	
			Game * create_game();

			/* Handles allocated momory.
			 * */
			~Launcher();
	
		private:

			// Ensures that only one game instance is created.
			bool _game_created = false;

			// Stores map.
			Gmap * _map = nullptr;

			Game * _game = nullptr;

	};

}
#endif
