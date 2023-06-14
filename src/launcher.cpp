#include <launcher.hpp>
#include <game.hpp>
#include <cstdlib>

namespace walker {

	void Launcher::add_map(Gmap *map) {
		_map = map;
	}

	void Launcher::add_vconsole(escape_tui::VConsole *console) {
		_console = console;
	}

	void Launcher::add_recorder(escape_tui::InputRecorder *recorder) {
		_recorder = recorder;
	}

	bool Launcher::is_ok() const{

		// Check for all bad conditions.
		if (_map == nullptr) return false;
		if (_console == nullptr) return false;
		if (_recorder == nullptr) return false;
		if (_starting_state == nullptr) return false;
		return true;
	}


	void Launcher::add_link(GameIState *from, bool (*arg)(), GameIState *to) {

		// Create temp state link.
		struct STATELINK statelink;

		// Add arg.
		statelink.arg = arg;

		// Add state.
		statelink.state = to;
		
		// Push state link.
		_state_links[from].push_back(statelink);

	}

	void Launcher::add_starting(GameIState *starting) {

		// Switch starting state.
		_starting_state = starting;
		
	}

}
