#include <launcher.hpp>
#include <game.hpp>

int main(){

	walker::Launcher launcher;
	walker::Gmap map("test.map", 5);
	launcher.add_map(&map);
	walker::Game * game = launcher.create_game();
	
	game->start_poll_input();

	while(game->should_run()) game->step();

	game->stop_poll_input();
}
