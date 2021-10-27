#include "MapGenerator.h"

MapGenerator::MapGenerator()
{
	anchoPantalla = 0;
	altoPantalla = 0;
	renderer = nullptr;
}

MapGenerator::MapGenerator(SDL_Renderer* _renderer, int _anchoPantalla, int _altoPantalla, TilesGraph* _tilesGraph) :
	anchoPantalla(_anchoPantalla),
	altoPantalla(_altoPantalla),
	renderer(_renderer),
	tilesGraph(_tilesGraph)
{

}

bool MapGenerator::crearObjetosJuego(string _path)
{
	// Crea un flujo de archivo
	fstream file;

	// Abrir el archivo
	file.open(_path.c_str(), ios::in);

	if (file.is_open() == false) {
		std::cout << "No se pudo abrir el archivo de mapa" << std::endl;
		return false;
	}

	string line;

	Texture* texturaBomberman;
	texturaBomberman = new Texture();
	//BOMBERMAN ROBOT
	Texture* texturaBombermanRobot;
	texturaBombermanRobot = new Texture();




	//ENEMIGO
	Texture* texturaEnemigo;
	texturaEnemigo = new Texture();
	Texture* texturaEnemigo2;
	texturaEnemigo2 = new Texture();
	Texture* texturaEnemigo3;
	texturaEnemigo3 = new Texture();
	Texture* texturaEnemigo4;
	texturaEnemigo4 = new Texture();
	Texture* texturaEnemigo5;
	texturaEnemigo5 = new Texture();


	//BOMBER WOMAN
	Texture* texturaBomberwoman;
	texturaBomberwoman = new Texture();


	Texture* texturaMuroMetal;
	texturaMuroMetal = new Texture();
	Texture* texturaMuroCeramica;
	texturaMuroCeramica = new Texture();
	Texture* texturaSueloCesped;
	texturaSueloCesped = new Texture();

	Texture::renderer = renderer;


	texturaBomberman->loadFromImage("resources/bomberman.jpg");
	//BOMBER ROBOT
	texturaBombermanRobot->loadFromImage("resources/bombermanRobot2.jpg");
	//ENEMIGOS
	texturaEnemigo->loadFromImage("resources/enemigo.jpg");
	texturaEnemigo2->loadFromImage("resources/enemigo2.jpg");
	texturaEnemigo3->loadFromImage("resources/enemigo3.jpg");
	texturaEnemigo4->loadFromImage("resources/enemigo4.jpg");
	texturaEnemigo5->loadFromImage("resources/enemigo5.jpg");
	//BOMBER WOMAN
	texturaBomberwoman->loadFromImage("resources/bomberman.jpg");

	texturaMuroCeramica->loadFromImage("resources/muro_ceramica.jpg");
	texturaMuroMetal->loadFromImage("resources/muro_metal.jpg");
	texturaSueloCesped->loadFromImage("resources/suelo_cesped.jpg");

	int x = 0;
	int y = 0;
	int bombermanPosicionX = -1;
	int bombermanPosicionY = -1;
	//BOMBER ROBOT
	int bombermanRobotPosicionX = -1;
	int bombermanRobotPosicionY = -1;

	//BOMBER WOMAN
	int bomberwomanPosicionX = -1;
	int bomberwomanPosicionY = -1;

	//ENEMIGOS
	int enemigoPosicionX = -1;
	int enemigoPosicionY = -1;
	int enemigo2PosicionX = -1;
	int enemigo2PosicionY = -1;
	int enemigo3PosicionX = -1;
	int enemigo3PosicionY = -1;
	int enemigo4PosicionX = -1;
	int enemigo4PosicionY = -1;
	int enemigo5PosicionX = -1;
	int enemigo5PosicionY = -1;




	while (getline(file, line)) {
		vector<char> chars(line.begin(), line.end());
		x = 0;

		for (int i = 0; i < chars.size(); i++) {
			if (chars[i] != ' ') {
				GameObject* objetoNuevo = nullptr;
				Tile* tileNuevo = tilesGraph->getTileEn(x, y);
				switch (chars[i]) {
				case '0':
					objetoNuevo = new SueloCesped(texturaSueloCesped, tileNuevo);
					//BOMBERMAN
					if (x > bombermanPosicionX && bombermanPosicionX == -1) {
						bombermanPosicionX = x;
						bombermanPosicionY = y;
					}
					//BOMBER WOMAN
					if (x > bomberwomanPosicionX || y > bomberwomanPosicionY) {
						bomberwomanPosicionX = x;
						bomberwomanPosicionY = y;
					}

					//BOMBER ROBOT
					if (x > bombermanRobotPosicionX && bombermanRobotPosicionX == -1) {
						bombermanRobotPosicionX = x;
						bombermanRobotPosicionY = y;
					}

					//ENEMIGOS
					if (x > enemigoPosicionX && enemigoPosicionX == -1) {
						enemigoPosicionX = x;
						enemigoPosicionY = y;
					}

					if (x > enemigo2PosicionX && enemigo2PosicionX == -1) {
						enemigo2PosicionX = x;
						enemigo2PosicionY = y;
					}

					if (x > enemigo3PosicionX && enemigo3PosicionX == -1) {
						enemigo3PosicionX = x;
						enemigo3PosicionY = y;
					}

					if (x > enemigo4PosicionX && enemigo4PosicionX == -1) {
						enemigo4PosicionX = x;
						enemigo4PosicionY = y;
					}

					if (x > enemigo5PosicionX && enemigo5PosicionX == -1) {
						enemigo5PosicionX = x;
						enemigo5PosicionY = y;
					}


					//pilaObjetosJuegoMurosMetal.Insertar((GameActor*)objetoNuevo);

					break;
				case '1':
					objetoNuevo = new MuroMetal(texturaMuroCeramica, tileNuevo);
					if (x % 2 == 0 && y % 2 == 0) {
						int key = 0;
						key = x * TilesGraph::anchoTilesGraph + y;
						mObjetoMMP[key] = { x,y };

						for (auto i = mObjetoMMP.begin(); i != mObjetoMMP.end(); i++) {
							cout << x << " " << y << endl;
						};

					}
					break;
				case '2':
					objetoNuevo = new MuroCeramica(texturaMuroMetal, tileNuevo);
					break;

				}

				if (objetoNuevo != nullptr) {
					((GameActor*)objetoNuevo)->setPosicionX(x * 34);
					((GameActor*)objetoNuevo)->setPosicionY(y * 34);
					vectorObjectosJuego.push_back(objetoNuevo);
					x++;
				}
			}
		}
		y++;
	}


	//BOMBERMAN
	GameObject* objetoBomberman = nullptr;
	Tile* tileNuevo = tilesGraph->getTileEn(bombermanPosicionX, bombermanPosicionY);
	objetoBomberman = new Bomberman(texturaBomberman, tileNuevo);
	if (objetoBomberman != nullptr) {
		((GameActor*)objetoBomberman)->setPosicionX(bombermanPosicionX * 34);
		((GameActor*)objetoBomberman)->setPosicionY(bombermanPosicionY * 34);
		vectorObjectosJuego.push_back(objetoBomberman);
	}
	//BOMBER ROBOT
	GameObject* objetoBombermanRobot = nullptr;
	Tile* tileNuevo2 = tilesGraph->getTileEn(bombermanRobotPosicionX, bombermanRobotPosicionY);
	objetoBombermanRobot = new BombermanRobot(texturaBombermanRobot, tileNuevo2);
	if (objetoBombermanRobot != nullptr) {
		((GameActor*)objetoBombermanRobot)->setPosicionX(bombermanRobotPosicionX * 34);
		((GameActor*)objetoBombermanRobot)->setPosicionY(bombermanRobotPosicionY * 34);
		((GamePawn*)objetoBombermanRobot)->setBotomBomba(SDLK_p);
		((GamePawn*)objetoBombermanRobot)->setBotomArriba(SDLK_i);
		((GamePawn*)objetoBombermanRobot)->setBotomAbajo(SDLK_k);
		((GamePawn*)objetoBombermanRobot)->setBotomIzquierda(SDLK_j);
		((GamePawn*)objetoBombermanRobot)->setBotomDerecha(SDLK_l);
		vectorObjectosJuego.push_back(objetoBombermanRobot);
	}


	//BOMBER WOMAN
	GameObject* objetoBomberwoman = nullptr;
	tileNuevo = tilesGraph->getTileEn(bomberwomanPosicionX, bomberwomanPosicionY);
	objetoBomberwoman = new Bomberman(texturaBomberwoman, tileNuevo);
	if (objetoBomberwoman != nullptr) {
		((GameActor*)objetoBomberwoman)->setPosicionX(bomberwomanPosicionX * 34);
		((GameActor*)objetoBomberwoman)->setPosicionY(bomberwomanPosicionY * 34);
		((GamePawn*)objetoBomberwoman)->setBotomBomba(SDLK_o);
		((GamePawn*)objetoBomberwoman)->setBotomArriba(SDLK_w);
		((GamePawn*)objetoBomberwoman)->setBotomAbajo(SDLK_s);
		((GamePawn*)objetoBomberwoman)->setBotomIzquierda(SDLK_a);
		((GamePawn*)objetoBomberwoman)->setBotomDerecha(SDLK_d);
		vectorObjectosJuego.push_back(objetoBomberwoman);
	}

	//ENEMIGOS
	GameObject* objetoEnemigo = nullptr;
	Tile* tileNuevo3 = tilesGraph->getTileEn(enemigoPosicionX, enemigoPosicionY);
	objetoEnemigo = new Enemigo(texturaEnemigo, tileNuevo3);
	if (objetoEnemigo != nullptr) {
		((GameActor*)objetoEnemigo)->setPosicionX(enemigoPosicionX * 350);
		((GameActor*)objetoEnemigo)->setPosicionY(enemigoPosicionY * 34);
		vectorObjectosJuego.push_back(objetoEnemigo);
	}

	GameObject* objetoenemigo2 = nullptr;
	tileNuevo3 = tilesGraph->getTileEn(enemigo2PosicionX, enemigo2PosicionY);
	objetoenemigo2 = new Enemigo(texturaEnemigo2, tileNuevo3);
	if (objetoenemigo2 != nullptr) {
		((GameActor*)objetoenemigo2)->setPosicionX(enemigo2PosicionX * 600);
		((GameActor*)objetoenemigo2)->setPosicionY(enemigo2PosicionY * 300);
		vectorObjectosJuego.push_back(objetoenemigo2);
	}

	GameObject* objetoenemigo3 = nullptr;
	tileNuevo3 = tilesGraph->getTileEn(enemigo3PosicionX, enemigo3PosicionY);
	objetoenemigo3 = new Enemigo(texturaEnemigo3, tileNuevo3);
	if (objetoenemigo2 != nullptr) {
		((GameActor*)objetoenemigo3)->setPosicionX(enemigo3PosicionX * 445);
		((GameActor*)objetoenemigo3)->setPosicionY(enemigo3PosicionY * 270);
		vectorObjectosJuego.push_back(objetoenemigo3);
	}

	GameObject* objetoenemigo4 = nullptr;
	tileNuevo3 = tilesGraph->getTileEn(enemigo4PosicionX, enemigo4PosicionY);
	objetoenemigo4 = new Enemigo(texturaEnemigo4, tileNuevo3);
	if (objetoenemigo4 != nullptr) {
		((GameActor*)objetoenemigo4)->setPosicionX(enemigo4PosicionX * 200);
		((GameActor*)objetoenemigo4)->setPosicionY(enemigo4PosicionY * 250);
		vectorObjectosJuego.push_back(objetoenemigo4);
	}

	GameObject* objetoenemigo5 = nullptr;
	tileNuevo3 = tilesGraph->getTileEn(enemigo5PosicionX, enemigo5PosicionY);
	objetoenemigo5 = new Enemigo(texturaEnemigo5, tileNuevo3);
	if (objetoenemigo5 != nullptr) {
		((GameActor*)objetoenemigo5)->setPosicionX(enemigo5PosicionX * 300);
		((GameActor*)objetoenemigo5)->setPosicionY(enemigo5PosicionY * 300);
		vectorObjectosJuego.push_back(objetoenemigo5);
	}


	return false;
}

void MapGenerator::transferirObjetosJuego(vector<GameObject*>& _vectorObjetosJuegoDestino)
{
	_vectorObjetosJuegoDestino = vectorObjectosJuego;
	/*for (int i = 0; i < vectorObjectosJuego.size(); i++) {
		_vectorObjetosJuegoDestino.push_back(vectorObjectosJuego[i]);
	}*/
}