#ifndef __WALKER_GAME_MENU_STATE__
#define __WALKER_GAME_MENU_STATE__

#include <istate.hpp>

namespace walker {

	namespace game {

		/* Menu state
		 * */
		class MenuState : public GameIState {

			public:

				void start(Game * game) override;

				void stop(Game * game) override;

				/* Waits for input to close application or
				 * to start the game.
				 * */
				void step(Game * game) override;

		};
	
	}

}

#endif
