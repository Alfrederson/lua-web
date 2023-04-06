# Lua Web

Makefile compila o Lua 5.4.4 com emcc. Objetivo final vai ser fazer upload do bytecode gerado pro ESP32.

## Pra compilar isso

1- Baixar o LUA aqui dentro.

```
curl -R -O http://www.lua.org/ftp/lua-5.4.4.tar.gz
tar zxf lua-5.4.4.tar.gz
cd lua-5.4.4
make all test
```

2- Instalar o emscripten e as outras coisas pra conseguir compilar o lua_web.c com o emcc.

3- rodar isso:

```
make
```