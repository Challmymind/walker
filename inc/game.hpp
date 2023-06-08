#ifndef __WALKER_GAME__
#define __WALKER_GAME__

#include <cstdint>
#include <map.hpp>

// Namespace of project.
namespace walker {
	
	class Game;
	
	/* Launcher class.
	 * Luncher class creates game class object.
	 * Ensures that everything is on it's place.
	 * */
	class Launcher {
		public:
			// Adders:
			bool add_map(const Map& map);
	
			// Spawn game.
			Game create_game();
	
		private:
			bool _game_created = false;
	};
	
	/* Game class.
	 * Game class should act like compositor.
	 * Provides interface for managing game entities.
	 * */
	class Game {
		public:
			// Main loop:
			bool step();
			void poll_input();

			// Flags:
			bool should_run() const;
	
			// Execption handling:
			std::uint_least16_t poll_error();
	
				
		private:
			// Hide constructor.
			Game();

			bool _should_run_flag;

	};

}

#endif
