
/*

La función glShadeModel(GL_SMOOTH) es una llamada de OpenGL que se utiliza para configurar el 
modelo de sombreado de caras en suavizado (smooth shading).

En OpenGL, hay dos modelos principales de sombreado de caras: GL_FLAT y GL_SMOOTH:

GL_FLAT: Este modelo calcula un color para cada cara de un objeto basándose en el color 
del vértice definido para esa cara. Todos los píxeles dentro de una cara se pintan con 
el mismo color. Este modelo proporciona un aspecto de sombreado "plano", donde cada 
cara tiene un solo color.

GL_SMOOTH: En cambio, este modelo calcula un color para cada píxel dentro de una cara interpolando
suavemente los colores de los vértices que forman la cara. Esto crea una apariencia de sombreado
suave y gradiente dentro de la cara, lo que hace que los objetos parezcan más suaves y más 
realistas.

*/



#include<GL/glut.h>

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glShadeModel (GL_SMOOTH); // esta por defecto 
   // glShadeModel(GL_FLAT); // se implemtara el ultimo color 

    glBegin (GL_TRIANGLES);
    glColor3f (0.0, 0.0, 1.0);
    glVertex2i (50, 50);
    glColor3f (1.0, 0.0, 0.0);
    glVertex2i (150, 50);
    glColor3f (0.0, 1.0, 0.0);
    glVertex2i (75, 150);
    glEnd ( );

    glFlush();
}

int main(int argc,char** argv){
    
    glutInit (&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400,400);
    glutCreateWindow("helloINTERPOL");
    glClearColor(1.0, 1.0, 1.0, 1.0);
    gluOrtho2D(0, 400, 0, 400);
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}