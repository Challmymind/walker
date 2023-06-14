#include <launcher.hpp>
#include <escape-tui.hpp>
#include <game.hpp>
#include <game/menu_state.hpp>

int main(){

	walker::Gmap map("test.map", 5);
	escape_tui::InputRecorder recorder;
	escape_tui::VConsole console;
	walker::game::MenuState menu;

	walker::Launcher launcher;
	launcher.add_map(&map);
	launcher.add_recorder(&recorder);
	launcher.add_vconsole(&console);
	launcher.add_starting(&menu);
	
	
	if (!launcher.is_ok()) return 1;

	walker::Game game(&launcher);

	game.start();

	while (game.should_run()) {

		game.step();

	}
	
}
