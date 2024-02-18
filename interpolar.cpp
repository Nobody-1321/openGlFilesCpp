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