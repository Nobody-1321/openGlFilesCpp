#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    int pointA[] = {50, 50};
    int pointB[] = {150, 50};
    int pointC[] = {150, 150};
    int pointD[] = {50, 150};

    // Dibuja un rectángulo rojo en la ventana
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2iv(pointA);
    glVertex2iv(pointB);
    glVertex2iv(pointC);
    glVertex2iv(pointD);
    glEnd();

   // glCopyPixels(50, 50, 150, 150, GL_COLOR);
    
    GLubyte bitShape[100 * 100 * 3];  // Ajusta el tamaño según el formato y tamaño de la región
  
    //glReadPixels(50, 50, 150, 150, GL_COLOR, GL_UNSIGNED_BYTE, bitShape);
    //glRasterPos2i(175, 175);
    //glDrawPixels(100, 100, GL_RGB, GL_UNSIGNED_BYTE, bitShape);


    // Lee un bloque de 100x100 píxeles desde la posición (50, 50) en el framebuffer
    // glReadPixels(x,y, alto de prixeles a leer , ancho de pixeles a leer)

    glReadPixels(50, 50, 100, 100, GL_RGB, GL_BYTE, bitShape);

    // Establece la posición de rasterización a (175, 175)
    glRasterPos2i(175, 175);

    // Dibuja el bloque de píxeles leído en la nueva posición
    glDrawPixels(100, 100, GL_RGB, GL_BYTE, bitShape);

    //leccion aprendida no elemines archivos a lo brito con rm
    //tener cuidado con los el espacio de buffer.
    
    glFlush();
}

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(800, 800);
    glutCreateWindow("ReadPixels and DrawPixels Example");
  
    glClearColor(1.0, 1.0, 1.0, 1.0);  // Color de fondo blanco
    
    glMatrixMode(GL_PROJECTION);
    
    gluOrtho2D(0, 800, 0, 800);  // Ajusta según tus necesidades
    
    glutDisplayFunc(display);
    
    glutMainLoop();
    return 0;
}
