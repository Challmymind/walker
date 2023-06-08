#ifndef __WALKER__RENDER_BASE__
#define __WALKER__RENDER_BASE__

#include <game.hpp>

namespace walker {

	/* Base class for all redeners.
	 * */
	class RenderBase {

		public:

			/* Renders the game's changes into screen.
			 *
			 * @params the game instance.
			 * */
			virtual void render(const Game& game) = 0;

	};
	
}

#endif
