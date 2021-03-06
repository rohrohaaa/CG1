#include <SOIL/SOIL.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>

#include "desenhanave.h"
#include "desenhaexercito.h"
#include "variaveisglobais.h"
#include "desenhaeatualiza.h"
#include "desenhaTiroInimigo.h"
#include "contagemVidas.h"

//Atira a bala da "nave"
void atira(){
    if(tiro){
        atiraCaninha();
        if(acerto == 0 && yCaninha<700){
            yCaninha+=10;
        }
        else{
            acerto=0;
            tiro=0;
            yCaninha=80;
            
        }  
    }
}

//Play musica
void tocaMusica(){
    if(!Mix_PlayingMusic()){
        Mix_PlayMusic(music,-1);
        Mix_VolumeMusic(72);
        //printf("volume is now : %d\n", Mix_VolumeMusic(-1)); //Verificar o volume
    }

}

//Função pause/resume
void pausaMusica(int pause){
    if(pause==1)
        Mix_PauseMusic();
    else
        Mix_ResumeMusic();
}

// Função tiro inimigo
void jogaTiroInimigo(){

    if(yTiroInimigo>0 && acertouOLulinha==0){
        yTiroInimigo-=10;
    }
    else{
        acertouOLulinha = 0;
        escolheInimigo = rand()%8;
        Mix_PlayChannelTimed(-1,somExercito,0,1000);

            if(ativo[escolheInimigo]==1){
                yTiroInimigo = yVerticeGado;
                xTiroInimigo = xVerticeGado[escolheInimigo]-20;  
            }

            else if(ativo2[escolheInimigo]==1 ){
                yTiroInimigo = yVerticeGado-yGado2;
                xTiroInimigo = xVerticeGado[escolheInimigo];
            }

            else if(ativo3[escolheInimigo]==1){
                yTiroInimigo = yVerticeGado-yGado2-yGado2;
                xTiroInimigo = xVerticeGado[escolheInimigo];
            }
            
    }
    desenhaTiroInimigo();

}

//Tela game over
void gameOver(){
    
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, idTexturaGameOver);
        glBegin(GL_TRIANGLE_FAN);

                    
            glTexCoord2f(0, 0);
            glVertex3f(150, 125,  0);

            glTexCoord2f(1, 0);
            glVertex3f( 550, 125,  0);

            glTexCoord2f(1, 1);
            glVertex3f( 550,  525,  0);

            glTexCoord2f(0, 1);
            glVertex3f(150,  525,  0);
                

        glEnd();
        glDisable(GL_TEXTURE_2D);
    
}

//tela ganhou
void ganhou(){
    
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, idTexturaGanhou);
        glBegin(GL_TRIANGLE_FAN);

                    
            glTexCoord2f(0, 0);
            glVertex3f(150, 125,  0);

            glTexCoord2f(1, 0);
            glVertex3f( 550, 125,  0);

            glTexCoord2f(1, 1);
            glVertex3f( 550,  525,  0);

            glTexCoord2f(0, 1);
            glVertex3f(150,  525,  0);
                

        glEnd();
        glDisable(GL_TEXTURE_2D);
    
}

//funçao desenha minha cena
void desenha() {

    if(!inicia){
        contagemdetempo++;
        if (contagemdetempo<200)
        {
            idTexturaAuxiliar = idTexturaTitulo;
        }
        else if(contagemdetempo>200&& contagemdetempo<400){
            idTexturaAuxiliar = idTexturaControles;
        }
        else if(contagemdetempo>400){
            idTexturaAuxiliar = idTexturaComecar;
        }
        
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D, idTexturaAuxiliar);
            glBegin(GL_TRIANGLE_FAN);
            
                glTexCoord2f(0, 0);
                glVertex3f(0, 0,  0);

                glTexCoord2f(1, 0);
                glVertex3f( 700, 0,  0);

                glTexCoord2f(1, 1);
                glVertex3f( 700,  650,  0);

                glTexCoord2f(0, 1);
                glVertex3f(0,  650,  0);

            glEnd();
            glDisable(GL_TEXTURE_2D);

            glutSwapBuffers();

    }
    
    else{
        if(pause==0&&continuaGanhou && continuaGanhou && desenhadoGameOver==0 ){

        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f (1, 1, 1);

        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, idTexturaFundo);
        glBegin(GL_TRIANGLE_FAN);
            
            glTexCoord2f(0, 0);
            glVertex3f(0, 0,  0);

            glTexCoord2f(1, 0);
            glVertex3f( 700, 0,  0);

            glTexCoord2f(1, 1);
            glVertex3f( 700,  650,  0);

            glTexCoord2f(0, 1);
            glVertex3f(0,  650,  0);

            glEnd();
            glDisable(GL_TEXTURE_2D);

            contagemVidas();
            desenhaLegenda();
            jogaTiroInimigo();
            desenhaNave();
            abateDeGado();
            abateDeGado2();
            abateDeGado3();
        	continuar(); 
            desenhaExercito();
            atira();
            abateLulinha();

            if (continuaPerdeu==0)
            {
                gameOver();
                desenhadoGameOver=1;
            }
            if(continuaGanhou==0){
                ganhou();
                desenhadoGameOver=1;
            }

            //nivel=nivel+1;
            //if(nivel>1000)
            //    jogaTiroInimigo();


            
            glutSwapBuffers();
        }
    }
}


//funçao aualiza minha cena
void atualiza(int periodo) {
        
    glutPostRedisplay();
    glutTimerFunc(33,atualiza,0);
        
}

