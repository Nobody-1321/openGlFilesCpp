/*
    glNewList es una forma util de crear algo parecido a una rutina de codigo 
    la cual despues podemos llamar con su identificador 

*/

#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>

const double TWO_PI = 6.2831853;
/* Initial display-window size. */
GLsizei winWidth = 400, winHeight = 400;
GLuint regHex;

class screenPt
{

private:
    GLint x, y;

public:
    /* Default Constructor: initializes coordinate position to (0, 0).*/
    screenPt()
    {
        x = y = 0;
    }

    void setCoords(GLint xCoord, GLint yCoord)
    {
        x = xCoord;
        y = yCoord;
    }

    GLint getx() const
    {
        return x;
    }

    GLint gety() const
    {
        return y;
    }
};

void init()
{
    screenPt hexVertex, circCtr;
    GLdouble theta;
    GLint k;
    
    /* Set circle center coordinates. */
    circCtr.setCoords(winWidth / 2, winHeight / 2);
    glClearColor(1.0, 1.0, 1.0, 0.0);
    
    //
    // Display-window color = white.
    /* Set up a display list for a red regular hexagon.
     * Vertices for the hexagon are six equally spaced
     * points around the circumference of a circle.
     */
    regHex = glGenLists(1);
    // Get an identifier for the display list.
    glNewList(regHex, GL_COMPILE);
    glColor3f(1.0, 0.0, 0.0);
    // Set fill color for hexagon to red.
    glBegin(GL_POLYGON);

    for (k = 0; k < 6; k++)
    {
        theta = TWO_PI * k / 6.0;
        hexVertex.setCoords(circCtr.getx() + 150 * cos(theta),
                            circCtr.gety() + 150 * sin(theta));
        glVertex2i(hexVertex.getx(), hexVertex.gety());
    }

    glEnd();
    glEndList();
}

void regHexagon(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glCallList(regHex);
    glFlush();
}

// Esta función se llama cada vez que la ventana de OpenGL se redimensiona.
// Recibe dos parámetros: newWidth y newHeight, que representan las nuevas dimensiones de la ventana.
void winReshapeFcn(int newWidth, int newHeight)
{
    // Establece la matriz de proyección actual como la matriz de proyección.
    glMatrixMode(GL_PROJECTION);
    
    // Reemplaza la matriz de proyección actual con la matriz identidad.
    glLoadIdentity();
    
    // Configura una proyección ortográfica 2D.
    // Esto establece el sistema de coordenadas de la ventana OpenGL
    // para que vaya desde (0, 0) en la esquina inferior izquierda
    // hasta (newWidth, newHeight) en la esquina superior derecha.
    gluOrtho2D(0.0, (GLdouble)newWidth, 0.0, (GLdouble)newHeight);
    
    // Limpia el búfer de color, estableciendo todos los píxeles en negro.
    // Esto asegura que el contenido anterior de la ventana se borre
    // cuando la ventana se redimensione y se vuelva a dibujar.
    glClear(GL_COLOR_BUFFER_BIT);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(winWidth, winHeight);
    glutCreateWindow("Reshape-Function & Display-List Example");
    init();
    glutDisplayFunc(regHexagon);
    glutReshapeFunc(winReshapeFcn);
    glutMainLoop();
}