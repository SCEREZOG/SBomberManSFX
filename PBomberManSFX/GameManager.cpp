#include "GameManager.h"


	GameManager::GameManager() {
		gWindow = nullptr;
		gRenderer = nullptr;
		generadorMapa = nullptr;
		keyboardInput = KeyboardInput::Instance();
		enEjecucion = true;
		tilesGraphGM = nullptr;
		camera = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
	}

	bool GameManager::onInit() {

		//Initialization flag
		bool success = true;

		if (SDL_Init(SDL_INIT_VIDEO) < 0)
		{
			cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << endl;
			success = false;
		}
		else
		{
			//Create window
			gWindow = SDL_CreateWindow("Bomberman Man USFX", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
			if (gWindow == nullptr)
			{
				cout << "Window could not be created! SDL_Error: " << SDL_GetError() << endl;
				success = false;
			}
			else
			{

				////Create vsynced renderer for window
				gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
				if (gRenderer == nullptr)
				{
					cout << "Renderer could not be created! SDL Error: " << SDL_GetError() << endl;
					success = false;
				}
				else
				{
					//Initialize renderer color
					SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

					//Initialize PNG loading
					int imgFlags = IMG_INIT_PNG;
					if (!(IMG_Init(imgFlags) & imgFlags))
					{
						printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
						success = false;
					}
				}
			}
		}

		return success;
	}

	bool GameManager::loadContent()
	{
		tilesGraphGM = new TilesGraph(25, 15, 850, 510);
		GameActor::tilesGraph = tilesGraphGM;

		generadorMapa = new MapGenerator(gRenderer, SCREEN_WIDTH, SCREEN_HEIGHT, tilesGraphGM);
		generadorMapa->crearObjetosJuego("resources/level1.txt");
		generadorMapa->transferirObjetosJuego(actoresJuego);

		if (actoresJuego.size() > 0)
			return true;

		return false;
	}

	void GameManager::onEvent(SDL_Event* _event)
	{
		if (_event->type == SDL_QUIT) {
			enEjecucion = false;
		}

		switch (_event->type) {
		case SDL_KEYDOWN:
			keyboardInput->TurnKeyOn(_event->key.keysym.sym);
			break;
		case SDL_KEYUP:
			keyboardInput->TurnKeyOff(_event->key.keysym.sym);
			break;
			//	switch (_event->key.keysym.sym) {
			//	case SDLK_f:
			//		//SDL_SetWindowFullscreen(gWindow, SDL_WINDOW_FULLSCREEN);
			//		break;
			//	case SDLK_n:
			//		//SDL_SetWindowFullscreen(gWindow, SDL_WINDOW_MAXIMIZED);
			//		break;
			//	}
		}
	}

	void GameManager::onLoop() {

		Uint32 tickTime = SDL_GetTicks();
		Uint32 delta = tickTime - lastTickTime;
		lastTickTime = tickTime;

		for (int i = 0; i < actoresJuego.size(); i++) {
			actoresJuego[i]->update(delta);
		}
	}

	void GameManager::onRender() {
		SDL_RenderClear(gRenderer);
		for (int i = 0; i < actoresJuego.size(); i++) {
			actoresJuego[i]->render(camera);
		}

		SDL_RenderPresent(gRenderer);
	}

	void GameManager::close()
	{
		//Free loaded image
		SDL_DestroyTexture(gTexture);
		gTexture = nullptr;

		//Destroy window	
		SDL_DestroyRenderer(gRenderer);
		SDL_DestroyWindow(gWindow);
		gWindow = nullptr;
		gRenderer = nullptr;

		//Quit SDL subsystems
		IMG_Quit();
		SDL_Quit();
	}


	int GameManager::onExecute() {
		if (!onInit()) {
			cout << "Failed to initialize!" << endl;
			return -1;
		}

		if (loadContent() == false) {
			cout << "Failed to load content!" << endl;
			return -1;
		}

		//While application is running
		while (enEjecucion)
		{
			//Handle events on queue
			while (SDL_PollEvent(&evento) != 0)
			{
				onEvent(&evento);
			}

			onLoop();
			onRender();
		}

		//Free resources and close SDL
		close();

		std::cout << "Numero de objetos en el vector: " << actoresJuego.size() << std::endl;
		std::cout << "Numero de objetos creados:" << GameObject::numeroGameObjectCreados << std::endl;

		return 0;

	}

	//GAME 

	//implementacion.......
	GameManager::GameManager(const std::string& windowName, const int width, const int height)
		: windowWidth(width), windowHeight(height)
	{
		// let's init SDL2
		if (SDL_Init(SDL_INIT_VIDEO) != 0)
		{
			std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
			return;
		}

		//// let's init SDL2 TTF
		//if (TTF_Init() != 0)
		//{
		//    std::cout << "TTF_Init Error: " << TTF_GetError() << std::endl;
		//    return;
		//}

		// let's init SDL2 Image
		if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
		{
			std::cout << "IMG_Init Error: " << IMG_GetError() << std::endl;
			return;
		}

		//// let's init SDL2 Mixer
		//if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
		//{
		//    std::cout << "Mix_OpenAudio Error: " << Mix_GetError() << std::endl;
		//    return;
		//}

		// create a window
		window = SDL_CreateWindow(windowName.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			windowWidth, windowHeight, SDL_WINDOW_SHOWN | SDL_WINDOW_ALLOW_HIGHDPI);
		if (!window)
		{
			std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
			return;
		}

		// create a renderer for window
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		if (renderer == nullptr)
		{
			std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
			return;
		}

		// we need new size due to possible high resolution on mac and ios
		int w, h;
		SDL_GetRendererOutputSize(renderer, &w, &h);
		windowWidth = w;
		windowHeight = h;

		//assetManager = new AssetManager();
		sceneManager = new SceneManager();
	}

	GameManager::~GameManager()
	{
		delete sceneManager;
		//delete assetManager;
		// delete SDL2 C pointers
		SDL_DestroyWindow(window);
		SDL_DestroyRenderer(renderer);

		// SDL2 finish
		//Mix_CloseAudio();
		IMG_Quit();
		// TTF_Quit();
		SDL_Quit();
	}

	void GameManager::run()
	{
		if (isRunning)
		{
			return;
		}

		isRunning = true;

		// load assets
		//assetManager->load(renderer);
		// create menu scene
		sceneManager->addScene("menu", std::make_shared<MenuScene>(this));
		sceneManager->activateScene("menu");

		SDL_Event event;

		while (isRunning)
		{
			// check SDL2 events
			while (SDL_PollEvent(&event))
			{
				// send event to current scene
				sceneManager->onEvent(event);
				// stop loop on quit
				if (event.type == SDL_QUIT)
				{
					stop();
				}
			}

			// calculate delta
			Uint32 tickTime = SDL_GetTicks();
			Uint32 delta = tickTime - lastTickTime;
			lastTickTime = tickTime;
			// update current scene
			sceneManager->update(delta);

			// clear the screen
			SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
			SDL_RenderClear(renderer);
			// draw current scene
			sceneManager->render();
			// flip the backbuffer
			SDL_RenderPresent(renderer);
		}
	}

	void GameManager::stop()
	{
		isRunning = false;
	}

	int GameManager::getWindowWidth() const
	{
		return windowWidth;
	}

	int GameManager::getWindowHeight() const
	{
		return windowHeight;
	}

	SDL_Renderer* GameManager::getRenderer() const
	{
		return renderer;
	}

	SceneManager* GameManager::getSceneManager() const
	{
		return sceneManager;
	}

	AssetManager* GameManager::getAssetManager() const
	{
		return assetManager;
	}
