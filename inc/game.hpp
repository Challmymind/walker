#ifndef __WALKER_GAME__
#define __WALKER_GAME__

#include <cstdint>
#include <mutex>
#include <gmap.hpp>
#include <launcher.hpp>
#include <thread>
#include <escape-tui.hpp>

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

			// Enables creation of game by launcher.
			friend Launcher;
				
		private:

			// Hide constructor.
			Game(Gmap * map, escape_tui::VConsole * console, escape_tui::InputRecorder * recorder) : _map(map), _console(console), _recorder(recorder) {};

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


	};
}

#endif
