#ifndef __WALKER_LAUNCHER__
#define __WALKER_LAUNCHER__

#include <gmap.hpp>
#include <istate.hpp>
#include <map>
#include <vector>
#include <escape-tui.hpp>

namespace walker {

	class Game;
	
	/* Checks for all critical dependencies of the game.
	 * */
	class Launcher {
		public:

			/* Structure that stores link between
			 * state argument and state.
			 *
			 * Used by functions that search for possible state switches.
			 * */
			struct STATELINK {

				GameIState * state;
				bool (*arg)();

			};

			/* Adds a map object to the game. 
			 *
			 * @param a map object.
			 * */
			void add_map(Gmap * map);

			/* Adds state links to the launcher.
			 *
			 * It will ne passed to the created game.
			 * This design has been chosen so the states can't
			 * be edited on already running game.
			 *
			 * @param from - state from which change, arg - function that 
			 * returns true if state could be switched and to - state to switch.
			 * */
			void add_link(GameIState * from, bool (*arg)(), GameIState * to);

			/* Add starting state to the launcher.
			 *
			 * The game will start with this state.
			 *
			 * @param state that will be starting state.
			 * */
			void add_starting(GameIState * starting);

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

			// Enables creation of game by launcher.
			friend Game;
	
		private:

			// Stores map.
			Gmap * _map = nullptr;

			// Input recorder.
			escape_tui::InputRecorder * _recorder;

			// Pointer to the virtual console.
			escape_tui::VConsole * _console = nullptr;

			// Stores structure of state and it's links.
			// If the state it's running each step() game is searching if
			// any state can be changed.
			std::map<GameIState *, std::vector<struct STATELINK>> _state_links;
			
			// Starting state.
			GameIState * _starting_state = nullptr;

	};

}
#endif
