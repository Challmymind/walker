#ifndef __WALKER_LAUNCHER__
#define __WALKER_LAUNCHER__

#include <gmap.hpp>
#include <escape-tui.hpp>

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

			/* Adds a virtual console to the game.
			 *
			 * @param a virtual console.
			 * */
			void add_vconsole(escape_tui::VConsole * console);

			/* Adds a input recorder to the game.
			 *
			 * @param a input recorder.
			 * */
			void add_recorder(escape_tui::InputRecorder * recorder);

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

			// Pointer to the created game.
			Game * _game = nullptr;

			// Input recorder.
			escape_tui::InputRecorder * _recorder;

			// Pointer to the virtual console.
			escape_tui::VConsole * _console = nullptr;

	};

}
#endif
