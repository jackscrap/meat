CC=g++
DEPS = main.cpp src/graphic/window.hpp src/graphic/window.cpp src/player.hpp src/player.cpp src/prop.hpp src/prop.cpp

make: main.cpp
	 $(CC) $(DEPS) -std=c++11 -lglfw -lGL -lX11 -lpthread -lXrandr -lXi -ldl -lGLEW -lGLU -lm -pthread -ldrm -lXdamage -lXfixes -lX11-xcb -lxcb-glx -lxcb-dri2 -lXxf86vm -lXext -lxcb -lXau -lXdmcp -lsfml-graphics -lsfml-window -lsfml-system

clean:
	rm *.out
