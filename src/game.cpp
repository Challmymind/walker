#include <game.hpp>
#include <cstdlib>
#include <thread>

namespace walker {

	Game::Game(Launcher * launcher) {

		// Check for critical conditions.
		if (!launcher->is_ok()) std::exit(1);

		// Pass all dependencies.
		_map = launcher->_map;
		_console = launcher->_console;
		_recorder = launcher->_recorder;
		_current_state = launcher->_starting_state;
		_state_links = launcher->_state_links;
		
	}

	escape_tui::VConsole * Game::draw() {
		
		// Return virtual screen.
		return _console;
	}

	char Game::get_input() {

		// Returns most recent input.
		return _recent_input;

	}

	bool Game::step() {

		// Read latest input.
		_recent_input = _recorder->get_input();

		// Render latest changes.
		_console->render();

		for (auto links : _state_links[_current_state]) {

			// Check if state can be switched.
			if (links.arg) {

				// End current state.
				_current_state->stop(this);

				// Change state.
				_current_state = links.state;

				// Start new state.
				_current_state->start(this);

				// End this loop now.
				return true;

			}

		}
		
		// Run state loop.
		_current_state->step(this);

		return true;
	}

	void Game::start() {

		// Don't run game twice.
		if (_is_game_on) return;

		// Start getting input.
		_recorder->start_recording();

		// Show that game is running.
		_is_game_on = true;

		// Start game.
		_should_run = true;

		// Run first state start function.
		_current_state->start(this);

	}

	void Game::close() {

		// Check if game is running.
		if (!_is_game_on) return;

		// Stop recording input.
		_recorder->stop_recording();

		// Close game.
		_should_run = false;

		// Show that game is closed.
		_is_game_on = false;

	}



	bool Game::should_run() const {
		return _should_run;
	}

	// WIP
	std::uint_least16_t Game::poll_error() {
		return 0;
	}



}

