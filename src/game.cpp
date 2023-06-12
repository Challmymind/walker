#include <game.hpp>
#include <cstdlib>
#include <thread>

namespace walker {

	// WIP
	bool Game::step() {

		
		char symbol = _recorder->get_input();
		if (symbol == 'a') close();

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

