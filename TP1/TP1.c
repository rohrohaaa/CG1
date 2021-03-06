#include "includes.h"

int main(int argc, char** argv) {
    SDL_Init (SDL_INIT_AUDIO);
    Mix_Init(MIX_INIT_MP3);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(700, 650);
    glutInitWindowPosition(100, 100);

    glutCreateWindow("Companheiro Ladrao roubou meu coracao");

    glutReshapeFunc(redimensiona);
    glutKeyboardFunc(teclado);
    glutSpecialFunc(especial);
    glutDisplayFunc(desenha);
    glutTimerFunc(33,atualiza,0);

    inicializa();
    tocaMusica();

    glutMainLoop();
    SDL_Quit ();
    return 0;
}