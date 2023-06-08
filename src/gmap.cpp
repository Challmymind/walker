#include <gmap.hpp>
#include <fstream>

namespace walker {

	Map::Map(const char* path, std::uint_fast8_t dimension){

		// Create and open stream.
		std::ifstream stream;
		stream.open(path);

		if(stream.good()) {

			// Temporary variables.
			std::uint_fast16_t size = dimension * dimension;
			char symbol;
			std::uint_fast16_t iteration = 0;;

			// Dynamic allocation.
			_map_pointer = std::make_unique<char[]>(size);

			while (stream >> symbol && iteration < size) {

				// Check for end of file.
				if (symbol == EOF) {
					break;
				}

				_map_pointer[iteration] = symbol;

				// Increase iteration.
				iteration++;
			}

			// Check if map hab been loaded correctly.
			if (iteration == size) _map_loaded = true;
		}

		// Close stream.
		stream.close();
			
	}

}
