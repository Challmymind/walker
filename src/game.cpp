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

		// Procces command if needed.
		if (_g_input_record.fcommand) {
			
			// End command : sends close signal.
			if (std::strcmp(_g_input_record.command, "end") == 0) {

				// Stop main loop.
				_should_run = false;

				// Stop polling input.
				stop_poll_input();
			}

			// Reset command buffer.
			for (std::uint_fast8_t i = 0; i < 5; i++) _g_input_record.command[i] = 0;

			// Unset command flag.
			_g_input_record.fcommand = false;
		}

		// HERE STATE UPDATE

		// Print current typed command.
		std::cout << "Current command: ";
		for (std::uint_fast8_t i = 0; i < 5; i++) std::cout << _g_input_record.command[i];
		std::cout << std::endl;

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
		
		// Lock mutex.
		_m_ip.lock();

		_g_is_polling = false;

		// Unlock mutex.
		_m_ip.unlock();

		
	}

	Game::~Game() {
		
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
				return;
			}

			// Unlock mutex.
			_m_ip.unlock();

			// Get input.
			symbol = std::getchar();

			// Enter command mode.
			if (symbol == '/') {

				std::uint8_t com_iteration = 0;
				// Process input.
				while (true) {

					// Check if its end of iteration.
					if (com_iteration >= 5) break;

					// Get input.
					symbol = std::getchar();

					// Check for end of command.
					if (symbol == '\n') break;

					// Lock mutex.
					_m_wi.lock();

					// Check if it is control character.
					if(!std::iscntrl(symbol)) _g_input_record.command[com_iteration] = symbol;
					
					// Unlock mutex.
					_m_wi.unlock();

					// Increase iteration.
					com_iteration++;

				}
				// Lock mutex.
				_m_wi.lock();

				// Set command flag.
				_g_input_record.fcommand = true;
				
				// Unlock mutex.
				_m_wi.unlock();

				while (true) {
					
					// Lock if possible.
					if (_m_wi.try_lock()) {
						
						if (!_g_input_record.fcommand) {

							// Unlock lock.
							_m_wi.unlock();
							break;

						}

						// Unlock lock.
						_m_wi.unlock();
					}

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
				default:
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

