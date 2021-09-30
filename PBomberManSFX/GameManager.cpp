#include "GameManager.h"


GameManager::GameManager() {
	gWindow = nullptr;
	gRenderer = nullptr;
	texturaBomber1 = nullptr;
	texturaBomber2 = nullptr;
	texturaMuroMetalico = nullptr;
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
		gWindow = SDL_CreateWindow("Bomber Man USFX", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
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
};

bool GameManager::loadMedia()
{
	//Loading success flag
	bool success = true;

	//Load PNG texture
	gTexture = loadTexture("texture.png");
	if (gTexture == NULL)
	{
		printf("Failed to load texture image!\n");
		success = false;
	}

	return success;
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
	else
	{
		//Main loop flag
		bool quit = false;

		//Event handler
		SDL_Event event;

		texturaBomber1 = new Texture(gRenderer);
		texturaBomber1->loadFromImage("resources/bomber.bmp");
		texturaBomber2 = new Texture(gRenderer);
		texturaBomber2->loadFromImage("resources/textures.bmp");
		texturaMuroMetalico = new Texture(gRenderer);
		texturaMuroMetalico->loadFromImage("resources/muro_metalico2.jpg");

		Bomber* b1 = new Bomber(texturaBomber1);
		Bomber* b2 = new Bomber(texturaBomber2);
		MuroMetalico* mm1 = new MuroMetalico(texturaMuroMetalico);
		MuroMetalico* mm2 = new MuroMetalico(texturaMuroMetalico);
		MuroMetalico* mm3 = new MuroMetalico(texturaMuroMetalico);
		MuroMetalico* mm4 = new MuroMetalico(texturaMuroMetalico);

		mm1->setImagenX(0);
		mm1->setImagenY(0);
		mm1->setAncho(770);
		mm1->setAlto(30);
		mm1->setPosicionX(0);
		mm1->setPosicionY(0);

		mm2->setImagenX(0);
		mm2->setImagenY(0);
		mm2->setAncho(30);
		mm2->setAlto(600);
		mm2->setPosicionX(770);
		mm2->setPosicionY(0);

		mm3->setImagenX(0);
		mm3->setImagenY(0);
		mm3->setAncho(770);
		mm3->setAlto(30);
		mm3->setPosicionX(0);
		mm3->setPosicionY(570);


		mm4->setImagenX(0);
		mm4->setImagenY(0);
		mm4->setAncho(30);
		mm4->setAlto(570);
		mm4->setPosicionX(0);
		mm4->setPosicionY(30);

		//b1->setImagenX(50);
		//b1->setImagenY(50);
		//b1->setAncho(20);
		//b1->setAlto(30);

		b2->setImagenX(570);
		b2->setImagenY(3);
		b2->setAncho(20);
		b2->setAlto(33);
		b2->setPosicionX(50);
		b2->setPosicionY(50);
				
		actoresJuego.push_back(b1);
		actoresJuego.push_back(b2);
		actoresJuego.push_back(mm1);
		actoresJuego.push_back(mm2);
		actoresJuego.push_back(mm3);
		actoresJuego.push_back(mm4);

		//While application is running
		while (!quit)
		{
			//Handle events on queue
			while (SDL_PollEvent(&event) != 0)
			{
				//User requests quit
				if (event.type == SDL_QUIT)
				{
					quit = true;
				}
			}

			//Clear screen
			//SDL_RenderClear(gRenderer);

			//Render texture to screen
			//SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);
			
				
			////Clear screen
			SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
			SDL_RenderClear(gRenderer);

			//Update screen

			/*onLoop();
			onRender();*/
			
			for (int i = 0; i < actoresJuego.size(); i++) {
				/*((GameActor*)actoresJuego[i])->setPosicionX(rand() % SCREEN_WIDTH);
				((GameActor*)actoresJuego[i])->setPosicionY(rand() % SCREEN_HEIGHT);*/

				actoresJuego[i]->render();
			}

			SDL_RenderPresent(gRenderer);
		}
	}

	//Free resources and close SDL
	close();

	return 0;

}

SDL_Texture* GameManager::loadTexture(std::string path)
{
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	return newTexture;
}