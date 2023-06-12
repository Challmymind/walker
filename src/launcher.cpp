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
		return true;
	}

	Game * Launcher::create_game() {

		// Critical error.
		if (!is_ok()) std::exit(1);

		// Checks if game exists.
		if (_game_created) return _game;

		// Switch flag before allocation.
		_game_created = true;

		// Allocate memory.
		_game = new Game(_map, _console, _recorder);

		return _game;

	}

	Launcher::~Launcher() {

		// Dealloactes memory if allocated.
		if (_game_created) delete _game;
	}

}
