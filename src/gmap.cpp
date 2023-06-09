#include <gmap.hpp>
#include <fstream>


namespace walker {

	Gmap::Gmap(const char* path, std::uint_fast8_t dimension) : dimension(dimension) {

		// Create and open stream.
		std::ifstream stream;
		stream.open(path);

		if(stream.good()) {

			// Temporary variables.
			char symbol;
			std::uint_fast16_t iterations_counter = 0;

			// Dynamic allocation.
			_map_pointer = new char*[dimension];
			for (std::uint_fast8_t i = 0; i < dimension; i++) _map_pointer[i] = new char[dimension];

			for (std::uint_fast8_t i = 0; i < dimension; i++) {

				for (std::uint_fast8_t j = 0; j < dimension; j++) {

					stream >> symbol;

					// Check for end of file.
					if (symbol == EOF) {
						break;
					}

					_map_pointer[i][j] = symbol;

					iterations_counter++;
				}

			}

			// Check if map hab been loaded correctly.
			if (iterations_counter == (std::uint_fast16_t)dimension*dimension) _map_loaded = true;
		}

		// Close stream.
		stream.close();
			
	}

	bool Gmap::is_ok() const {
		return _map_loaded;
	}

	Gmap::~Gmap() {
		
		// Deallocates second dimension.
		for (std::uint_fast8_t i = 0; i < dimension; i++) delete [] _map_pointer[i];
		// Deallocates first dimension.
		delete [] _map_pointer;

	}

}
