all: lua_web.o

lua_web.o: lua_web.c lua
	emcc -Ilua-5.4.4/src lua_web.c lua-5.4.4/src/liblua.a -s WASM=1 -Oz -o lua_web.js -g2 -s EXPORTED_FUNCTIONS='["_compile","_run"]' -sEXPORTED_RUNTIME_METHODS=ccall

lua:
	cd lua-5.4.4/src && make generic CC='emcc -s WASM=1'
