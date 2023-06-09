#include <gterminal.hpp>
#include <unistd.h>
#include <cstdlib>
#include <termios.h>

namespace walker {

	// Stores original terminal settings.
	struct termios __original;

	void activate_raw_input() {

		// Get terminal settings.
		tcgetattr(STDIN_FILENO, &__original);

		// New terminal settings.
		struct termios raw = __original;
		raw.c_lflag &= ~(ECHO | ICANON);

		// Set new terminal settings.
		tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);

		// Restore original input after exit.
		std::atexit(__restore_input);
	}

	void __restore_input() {
		tcsetattr(STDIN_FILENO, TCSAFLUSH, &__original);
	}

}
