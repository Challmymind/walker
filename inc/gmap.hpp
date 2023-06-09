#ifndef __WALKER_GMAP__
#define __WALKER_GMAP__

#include <cstdint>

namespace walker {
	
	/* Stores map and can be passed to the game.
	 * */
	class Gmap {

		public:

			/* Loads map from given path and creates it's instance.
			 *
			 * @param path to the file and the dimension of loaded map.
			 *
			 * @return true if the map has been loaded.
			 * */
			Gmap(const char* path, std::uint_fast8_t dimension);

			/* Loaded map dimension.
			 */
			const std::uint_fast8_t dimension;

			/* Checks if any error occured.
			 *
			 * Created for tests, to catch bugs.
			 *
			 * @return status of _map_loaded flag.
			 * */
			bool is_ok() const;

			/* Deconstructor.
			 *
			 * Constains deallocation of dynamic memory.
			 * */
			~Gmap();

		private:

			// Flag that indicates that map has been loaded without error.
			bool _map_loaded = false;

			// Pointer to loaded data.
			char ** _map_pointer;

	};
}

#endif
