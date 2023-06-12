#include <launcher.hpp>
#include <escape-tui.hpp>
#include <game.hpp>

int main(){

	walker::Gmap map("test.map", 5);
	escape_tui::InputRecorder recorder;
	escape_tui::VConsole console;

	walker::Launcher launcher;
	launcher.add_map(&map);
	launcher.add_recorder(&recorder);
	launcher.add_vconsole(&console);
	
	if (!launcher.is_ok()) return 1;

	walker::Game * game = launcher.create_game();

	game->start();
	while (game->should_run()) {

		game->step();

	}
	
}
