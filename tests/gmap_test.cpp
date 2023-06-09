#include <gmap.hpp>

int main(){

	walker::Gmap map("test.map", 5);
	if (!map.is_ok()) return 1;
	return 0;
}
