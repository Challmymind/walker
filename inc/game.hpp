#ifndef __WALKER_GAME__
#define __WALKER_GAME__

#include <cstdint>
#include <mutex>
#include <gmap.hpp>
#include <launcher.hpp>
#include <thread>

// Namespace of project.
namespace walker {
	
	/* Updated after reading input.*/
	struct INPUT_RECORD {

		/* Move flag.
		 * 0: no move input.
		 * 1: up move input.
		 * 2: right move input.
		 * 3: down move input.
		 * 4: left move input.
		 * */
		std::uint_fast8_t move;

		/* Interact flag.
		 * true if recorded interact key.
		 * */
		bool interact;

		/* Special flags.
		 * [0]: if 1 close app.
		 * */
		std::uint_fast8_t special[1];

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

			/* Starts polling the input from user.
			 *
			 * Must be called in thread otherwise will freeze the game.
			 * Uses game interrupts to change game state.
			 * */
			void start_poll_input();

			/* Stops polling the input from user.
			 * */
			void stop_poll_input();

			/* Checks if game should be closed.
			 *
			 * @return the state of the _should_run flag.
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

			// Enables creation of game by launcher.
			friend Launcher;
				
		private:

			// Internal polling implementation.
			void __poll_input();

			// Hide constructor.
			Game(Gmap * map) : _map(map) {};

			// Flag indicates if game should be closed.
			bool _should_run = true;

			// GUARDED Flag indicates that polling is on.
			bool _g_is_polling = false;

			// Stores map.
			Gmap * _map;

			// Mutex for _g_is_polling flag.
			std::mutex _m_ip;

			// Mutex for _g_is_writing_input flag.
			std::mutex _m_wi;

			// Poll thread.
			std::thread _poll_thread;

			// Input struct.
			struct INPUT_RECORD _g_input_record;

	};
}

#endif
