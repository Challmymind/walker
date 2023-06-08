#ifndef __WALKER__RENDER__
#define __WALKER__RENDER__

#include <game.hpp>

namespace walker {

	class RenderBase {
		public:
			virtual bool render(const Game& game);

			static RenderBase init();

		private:
			RenderBase();
	};
	
}

#endif
