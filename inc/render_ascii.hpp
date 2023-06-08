#ifndef __WALKER__RENDER_ASCII__
#define __WALKER__RENDER_ASCII__

#include <render_base.hpp>

namespace walker {

	/* Base class for all redeners.
	 * */
	class RenderAscii : public RenderBase {

		public:

			/* Overrided method of render base.
			 *
			 * Renders game changes into terminal.
			 *
			 * @params the game instance.
			 * */
			void render(const Game& game) override;

			/* Creates the render instance.
			 */
			RenderAscii();

		private:

	};
	
}

#endif
