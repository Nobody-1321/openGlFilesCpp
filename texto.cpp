#include <GL/glut.h>


void renderBitmapString(float x, float y,void *font, const char *string) {
//    glPushMatrix();
//    float angle=180.0;
    
//   glTranslatef(x, y, 0.0);
//    glRotatef(angle, 0.0, 0.0, 1.0);
//    glRasterPos2f(0.0, 0.0);

    while (*string) {
        glutBitmapCharacter(font, *string);
        glRasterPos2f(x, y -= 18);
        ++string;
    }

//    glPopMatrix();
}



void display();
void renderStrokeString(float x, float y, float angle, void *font, const char *string);

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutCreateWindow("OpenGL Texto con GLUT");
    glutInitWindowSize(400, 400);
    
    glutDisplayFunc(display);

    glClearColor(0.0, 0.0, 0.0, 0.0); // Color de fondo negro
    gluOrtho2D(0, 400, 0, 400);

    glutMainLoop();
    
    return 0;
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 1.0, 1.0); // Color blanco para el texto

    float angle = 90.0;

//    renderStrokeString(100, 100,angle , GLUT_BITMAP_HELVETICA_18, "¡Hola, OpenGL!");
   
    renderBitmapString(100, 399, GLUT_BITMAP_HELVETICA_18, "¡Hola, OpenGL!");
  
  
    //glRasterPos2f(100, 100);
   // glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,'A');
    
    glutSwapBuffers();
}

void renderStrokeString(float x, float y, float angle, void *font, const char *string) {
    glPushMatrix();
    
    glTranslatef(x, y, 0.0);
    glRotatef(angle, 0.0, 0.0, 1.0);
    glTranslatef(-x, -y, 0.0);

    glTranslatef(x, y, 0.0); // Ajustar la posición de rasterización
   
    while (*string) {
        glutStrokeCharacter(font, *string);
        ++string;
    }

    glPopMatrix();
}