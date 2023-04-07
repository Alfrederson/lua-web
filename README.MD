# Lua Web

Makefile compila o Lua 5.4.4 com emcc. ~~Objetivo final vai ser fazer upload do bytecode gerado pro ESP32~~. Pelo que eu li, o binário gerado pelo Lua normal não é compatível com a VM de Lua pro ESP32. No entanto, dá pra fazer a mesma coisa com o luac.cross, então o objetivo ainda vai ser fazer upload do bytecode compilado no navegador para o ESP32 dentro do navegador.

Isso aqui fica como exemplo de como 1- Compilar algum programa em C para WASM. 2- Embutir o programa em uma página HTML. O Makefile é praticamente copiado e colado desse outro repositório:

https://github.com/vvanders/wasm_lua/


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