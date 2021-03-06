#ifndef VARIAVEISGLOBAIS_H
#define VARIAVEISGLOBAIS_H

#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>


GLuint idTexturaFundo,idTexturaLulinha,idTexturaCaninha,idTexturaGado,idTexturaGameOver,idTexturaAlgema;
GLuint idTexturaLegenda,idTexturaComecar,idTexturaControles,idTexturaTitulo;
GLuint texturaAtual, idTexturaGanhou, idTexturaVidas1, idTexturaVidas2, idTexturaVidas3, idTexturaAuxiliar;
Mix_Music *music;
Mix_Chunk *somLulinha;
Mix_Chunk *somExercito;

float xTextura,yTextura,xPosicaoSprite,xVerticeSprite=325,yCaninha=80,xCaninha=200, ladoCaninha=14;
float xVerticeGado[8]={10,90,170,250,330,410,490,570},xVerticeGado2[8]={10,90,170,250,330,410,490,570};
float yVerticeGado=500, xTiroInimigo=0, yTiroInimigo=0;
float yVerticeSprite=10;
int ladoDir=1,ladoEsq=1,direita=0,frames=0,costas=1,primeiraVez=1,tiro=0, xGado2=30, yGado2=50, pause=0, acerto=0, nivel=0;
float sinal=0.1, sinal2=0.1, sinal3=0.1;
int inicia=0, contagemdetempo=0;
int continuaPerdeu=1,continuaGanhou=1,tiroInimigo=1, tamanho=0, escolheInimigo=0, vidas=3, acertouOLulinha = 0, desenhadoGameOver=0;
int ativo[8]={1,1,1,1,1,1,1,1};
int ativo2[7]={1,1,1,1,1,1,1};
int ativo3[7]={1,1,1,1,1,1,1};

#endif
