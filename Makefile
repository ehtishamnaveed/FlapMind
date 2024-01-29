
SFML_PATH := ./SFML/

FlappyBirds: Build/Main.o Build/Bird.o Build/Pipe.o Build/PipeManager.o Build/Game.o Build/GameManager.o Build/UI.o Build/EventHandler.o
	g++ Build/*.o -o FlappyBirds -L$(SFML_PATH)/lib -lsfml-graphics -lsfml-window -lsfml-system

Build/Main.o: Source/Main.cpp Header/Game.h Header/GameManager.h Header/UI.h
	g++ -c Source/Main.cpp -o Build/Main.o -I$(SFML_PATH)/include

Build/Bird.o: Source/Bird.cpp Header/Bird.h Header/Game.h
	g++ -c Source/Bird.cpp -o Build/Bird.o -I$(SFML_PATH)/include

Build/Pipe.o: Source/Pipe.cpp Header/Pipe.h Header/Game.h
	g++ -c Source/Pipe.cpp -o Build/Pipe.o -I$(SFML_PATH)/include

Build/PipeManager.o: Source/PipeManager.cpp Header/PipeManager.h Header/Pipe.h Header/Game.h
	g++ -c Source/PipeManager.cpp -o Build/PipeManager.o -I$(SFML_PATH)/include

Build/Game.o: Source/Game.cpp Header/Game.h
	g++ -c Source/Game.cpp -o Build/Game.o -I$(SFML_PATH)/include

Build/GameManager.o: Source/GameManager.cpp Header/GameManager.h Header/Bird.h Header/Game.h Header/PipeManager.h
	g++ -c Source/GameManager.cpp -o Build/GameManager.o -I$(SFML_PATH)/include

Build/EventHandler.o: Source/EventHandler.cpp Header/EventHandler.h Header/UI.h
	g++ -c Source/EventHandler.cpp -o Build/EventHandler.o -I$(SFML_PATH)/include

Build/UI.o: Source/UI.cpp Header/UI.h Header/EventHandler.h Header/GameManager.h Header/Game.h
	g++ -c Source/UI.cpp -o Build/UI.o -I$(SFML_PATH)/include

run: FlappyBirds
	./FlappyBirds

clean: 
	rm -f Build/*.o FlappyBirds

