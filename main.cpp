#include <game.hpp>
#include <render.hpp>

int main(){

	walker::Launcher launcher;
	walker::Map map;
	walker::RenderBase render = walker::RenderBase::init();

	if(!launcher.add_map(map)) {
		return 1;
	}

	walker::Game game = launcher.create_game();

	/*send to thread*/ game.poll_input();

	while (game.should_run()){

		game.step();
		if (!render.render(game)) {
			return 1;	
		}

	}

	return 0;
}
