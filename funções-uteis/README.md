g++ -g --coverage -Wall -O3 -std=c++17 -I./include -c src/fileOptions.cpp -o obj/fileOptions.o
g++ -g --coverage -Wall -O3 -std=c++17 -I./include -c src/main.cpp -o obj/main.o
g++ -g --coverage -Wall -O3 -std=c++17 obj/fileOptions.o obj/main.o -o bin/main
./bin/main