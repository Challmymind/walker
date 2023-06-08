#ifndef __WALKER_GMAP__
#define __WALKER_GMAP__

#include <cstdint>
#include <memory>

namespace walker {
	
	/* Stores map and can be passed to the game.
	 * */
	class Map {

		public:

			/* Loads map from given path and creates it's instance.
			 *
			 * @param path to the file and the dimension of loaded map.
			 *
			 * @return true if the map has been loaded.
			 * */
			Map(const char* path, std::uint_fast8_t dimension);

		private:

			// Flag that indicates that map has been loaded without error.
			bool _map_loaded = false;

			std::unique_ptr<char[]> _map_pointer;

	};
}

#endif
