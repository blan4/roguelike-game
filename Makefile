all: clean reload lint build exec

mkdir_build:
	[ -d ./cmake-build-debug ] | mkdir -p cmake-build-debug

build:
	cd cmake-build-debug;make roguelike

reload: mkdir_build
	cd cmake-build-debug;cmake ..

exec:
	./cmake-build-debug/src/roguelike

clean:
	rm -rf cmake-build-debug

fast_build:
	cd cmake-build-debug;make roguelike

run: fast_build exec

debug-server: fast_build
	gdbserver :1234 ./cmake-build-debug/src/roguelike

osx_dep:
	brew install cmake cppcheck clang-format
	brew install ncurses spdlog

lint:
	cd cmake-build-debug;make lint

reformat:
	clang-format -i -style=file include/**/*.h
	clang-format -i -style=file src/**/*.cpp