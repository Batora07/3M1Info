Pour compiler le programme :
mettre: include "MMachine" 
dans premake4.lua

Puis :
à la racine de gkit :
premake/premake4.linux --file=premake4.lua gmake

make mm_player

Pour executer (toujours à la racine de gkit):
$ ./MMachine/bin/mm_player 

