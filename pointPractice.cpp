#include<GL/glut.h>
//g++ tu_programa.cpp -o tu_programa -lGL -lGLU -lglut

#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(20.0);
  //  glColor3f (1.0, 0.0, 0.0);
    glBegin(GL_POINTS);

    // Primer punto rojo de tamaño 5.0
    glPointSize(5.0);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2i(50, 100);

    // Segundo punto verde de tamaño 10.0
    glPointSize(10.0);
    glColor3f(0.0, 1.0, 0.0);
    glVertex2i(75, 150);

    // Tercer punto azul de tamaño 15.0
    glPointSize(15.0);
    glColor3f(0.0, 0.0, 1.0);
    glVertex2i(100, 200);

    glEnd();

    glutSwapBuffers();
}

void dissplay() {
    glClear(GL_COLOR_BUFFER_BIT);

    typedef GLfloat vertex3[3], color3[3];

    vertex3 pt[8] = { {0.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {1.0, 0.0, 0.0},
                     {1.0, 1.0, 0.0}, {0.0, 0.0, 1.0}, {0.0, 1.0, 1.0}, {1.0, 0.0, 1.0}, {1.0, 1.0, 1.0} };

    color3 hue[8] = { {1.0, 0.0, 0.0}, {1.0, 0.0, 0.0}, {0.0, 0.0, 1.0},
                     {0.0, 0.0, 1.0}, {1.0, 0.0, 0.0}, {1.0, 0.0, 0.0}, {0.0, 0.0, 1.0}, {0.0, 0.0, 1.0} };

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, pt);
    glColorPointer(3, GL_FLOAT, 0, hue);

    // Agrega aquí la llamada para dibujar el cubo, como glDrawArrays o glDrawElements

    glutSwapBuffers();
}

/* Define a two-dimensional world-coordinate data type. */
typedef struct {
    float x, y;
} wcPt2D;

wcPt2D dataPts[5];

void linePlot(wcPt2D *dataPts) {
    int k;
    glBegin(GL_LINE_STRIP);
    for (k = 0; k < 5; k++)
        glVertex2f(dataPts[k].x, dataPts[k].y);
    glEnd();
}

void drawAxes() {
    glLineWidth (2.0);
    glBegin(GL_LINES);
    // X-axis
    glVertex2f(10.0, 20.0);
    glVertex2f( 20.0, 50.0);
    // Y-axis
   // glVertex2f(0.0, -1.0);
   // glVertex2f(0.0, 1.0);
    glEnd();
}

void diisplay() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw coordinate axes
    glColor3f(0.0, 0.0, 0.0);  // Black color for axes
    drawAxes();

  /*  // Set up line stipple
    glEnable(GL_LINE_STIPPLE);

    // Input first set of (x, y) data values.
    glLineStipple(1, 0x1C47);  // Dash-dot pattern
    glLineWidth(1.0);
    linePlot(dataPts);

    // Input second set of (x, y) data values.
    glLineStipple(1, 0x00FF);  // Dashed pattern
    glLineWidth(2.0);
    linePlot(dataPts);

    // Input third set of (x, y) data values.
    glLineStipple(1, 0x0101);  // Dotted pattern
    glLineWidth(3.0);
    linePlot(dataPts);

    // Disable line stipple
    glDisable(GL_LINE_STIPPLE);
  */
    glutSwapBuffers();
}


int main(int argc, char** argv) {
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(400, 400); 
    glutCreateWindow("OpenGL Blending Example");
    glClearColor(1.0, 1.0, 1.0, 1.0);  // Color de fondo blanco
    gluOrtho2D(0, 400, 0, 400);
   
    
    glutDisplayFunc(diisplay);

    glutMainLoop();

    return 0;
}
