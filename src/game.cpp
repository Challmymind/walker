#include <game.hpp>
#include <cstdlib>
#include <thread>
#include <iostream>
#include <gterminal.hpp>

namespace walker {

	// WIP
	bool Game::step() {

		// Lock mutex.
		_m_wi.lock();

		// HERE STATE UPDATE like
		if (_g_input_record.special[0]) _should_run = false;

		std::cout << "Polled: " << _g_input_record.move << std::endl;

		// Unlock mutex.
		_m_wi.unlock();

		return true;
	}

	void Game::start_poll_input() {

		// Lock mutex.
		_m_ip.lock();

		if(_g_is_polling) return;

		// Activates raw input and ensures it's recover.
		activate_raw_input();

		_g_is_polling = true;	

		// Unlock mutex.
		_m_ip.unlock();

		// Spawn poll thread.
		_poll_thread = std::thread(&Game::__poll_input, this);


	}

	void Game::stop_poll_input() {
		
		// WIP Add checks for file existance.
		
		// Lock mutex.
		_m_ip.lock();

		_g_is_polling = false;

		// Unlock mutex.
		_m_ip.unlock();

		// Wait for thread to stop.
		_poll_thread.join();
		
	}

	void Game::__poll_input(){

		char symbol;

		while(true) {

			// Lock mutex.
			_m_ip.lock();

			// Check if you should stop polling.
			if (!_g_is_polling) {

				// Unlock mutex.
				_m_ip.unlock();
				break;
			}

			// Unlock mutex.
			_m_ip.unlock();

			// Get input.
			symbol = std::getchar();

			// Enter command mode.
			if (symbol == '/') {

				char command[5] = {0,0,0,0,0};
				std::uint8_t com_iteration = 0;
				// Process input.
				while (true) {

					// Check if its end of iteration.
					if (com_iteration >= 5) break;

					// Get input.
					symbol = std::getchar();

					// Check for end of command.
					if (symbol == 10) break;

					// Check if it is control character.
					if(!std::iscntrl(symbol)) command[com_iteration] = symbol;

					// Increase iteration.
					com_iteration++;

				}

				if (std::strcmp(command, "end") == 0) {

					// Lock mutex.
					_m_wi.lock();

					// Request application close.
					_g_input_record.special[0] = 1;

					// Unlock mutex.
					_m_wi.unlock();
				}

				continue;
			}

			// Lock mutex.
			_m_wi.lock();

			switch (symbol) {

				case 'w':
					_g_input_record.move = 1;
					break;
				case 'd':
					_g_input_record.move = 2;
					break;
				case 's':
					_g_input_record.move = 3;
					break;
				case 'a':
					_g_input_record.move = 4;
					break;
				case 'e':
					_g_input_record.interact = true;
					break;

			}

			// Unlock mutex.
			_m_wi.unlock();

		}

		
	}

	bool Game::should_run() const {
		return _should_run;
	}

	// WIP
	std::uint_least16_t Game::poll_error() {
		return 0;
	}


}

