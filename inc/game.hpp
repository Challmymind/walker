#ifndef __WALKER_GAME__
#define __WALKER_GAME__

#include <cstdint>
#include <gmap.hpp>
#include <launcher.hpp>
#include <escape-tui.hpp>
#include <istate.hpp>

// Namespace of project.
namespace walker {
	
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

			/* Checks if game should be closed.
			 *
			 * @return the state of the _should_run flag.
			 * */
			bool should_run() const;

			/* Starts game.
			 *
			 * Starts polling input, clears terminal.
			 * Only after starting the game you can start drawing on screen
			 * and update game states.
			 * */
			void start();

			/* Closes game.
			 *
			 * Calling this function without calling start() will do nothing.
			 * */
			void close();
	
			/* Returns error code.
			 * 
			 * If any error inside the game instance has occured, you can poll
			 * it's error code via this function.
			 *
			 * @return error code.
			 * */
			std::uint_least16_t poll_error();

			/* Returns pointer to virtual screen.
			 * */
			escape_tui::VConsole * draw();
			
			/* Returns returned input by input recorder.
			 *
			 * This variable won't update until next step() call.
			 * */
			char get_input();

			// Game contructor.
			Game(Launcher * launcher);
				
		private:

			// Most recent input.
			char _recent_input;

			// Flag indicates if game should be closed.
			bool _should_run = true;

			// Flag is true if game has been started.
			bool _is_game_on = false;

			// Stores map.
			Gmap * _map;

			// Stores console.
			escape_tui::VConsole * _console;

			// Stores recorder.
			escape_tui::InputRecorder * _recorder;

			// Stores structure of state and it's links.
			// If the state it's running each step() game is searching if
			// any state can be changed.
			std::map<GameIState *, std::vector<Launcher::STATELINK>> _state_links;

			// Current state.
			GameIState * _current_state;

	};
}

#endif
