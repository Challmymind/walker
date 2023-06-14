#include <game/menu_state.hpp>
#include <game.hpp>

namespace walker {

	namespace game {

		void MenuState::start(Game *game){

			// Welcome message.
			char welcomeMSG[] = "Welcome to walker game.";
			char descriptionMSG[] = "It's simple console based game";
			char actionsMSG[] = "To exit press q";

			// Draw welcome message on screen.
			game->draw()->write_data(0, 0, welcomeMSG, sizeof(welcomeMSG));
			
			// Draw information on scren.
			game->draw()->write_data(0, 1, descriptionMSG, sizeof(descriptionMSG));

			// Tell user about possible actions.
			game->draw()->write_data(0, 2, actionsMSG, sizeof(actionsMSG));
			

			return;
		}

		void MenuState::stop(Game *game) {
			return;
		}

		void MenuState::step(Game *game) 
		{

			// Check if you should close game.
			if (game->get_input() == 'q') {

				// If yes then close.
				game->close();
			}

		}
	
	}

}
