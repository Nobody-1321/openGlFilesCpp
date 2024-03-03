/*
    el programa lee un bloque de pixeles, se guarda esa informacion en una matriz(guarda la informacion rgb)  
    posteriormente se dibuja la informacion leida en otro lugar. 
*/


#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    int pointA[] = {50, 50};    // bloque de arreglo de vertices el primer elemento del arreglo 
    int pointB[] = {150, 50};   // pertenece a X y el segundo a Y
    int pointC[] = {150, 150};  
    int pointD[] = {50, 150};

    glColor3f(1.0, 0.0, 0.0);
    
    glBegin(GL_POLYGON);
    glVertex2iv(pointA);        // dibuja el rectangulo 
    glVertex2iv(pointB);
    glVertex2iv(pointC);
    glVertex2iv(pointD);
    glEnd();

                                      //matrix de bits para guardar los datos de los pixeles.
    GLubyte bitShape[100 * 100 * 3];  // Ajusta el tamaño según el formato y tamaño de la región
    
    //Lee un bloque de 100x100 píxeles desde la posición (50, 50) en el framebuffer
    glReadPixels(50, 50, 100, 100, GL_RGB, GL_BYTE, bitShape);                                  
    glRasterPos2i(175, 175);          // Establece la posición de rasterización a (175, 175)
   
    //Funcion para dibujar los pixeles 
    glDrawPixels(100, 100, GL_RGB, GL_BYTE, bitShape);

    
    glFlush();
}

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutCreateWindow("ReadPixels and DrawPixels Example");
    glClearColor(1.0, 1.0, 1.0, 1.0);  // puedes ver la descripcion de este bloque de codigo en el 
    glMatrixMode(GL_PROJECTION);       // archivo iniciandoOpengl.cpp 
    gluOrtho2D(0, 800, 0, 800);  
    glutDisplayFunc(display);
    
    glutMainLoop();
    return 0;
}
