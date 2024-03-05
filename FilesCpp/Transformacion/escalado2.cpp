#include <GL/glut.h>
#include <vector>

class wcPt2D{
public:
    wcPt2D(GLfloat x, GLfloat y):x{x}, y{y} {}
    GLfloat x, y;
};

void init();
void display(std::vector<wcPt2D>& vectorPuntos);
void displayWrapper();
void scalePolygon(std::vector<wcPt2D>& verts, GLint nVerts, wcPt2D& fixedPt,
                  GLfloat sx, GLfloat sy);

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1000, 500);
    glutCreateWindow("Triangulo en OpenGL 2");
    init();
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 1000, 0, 500);
    glutDisplayFunc(displayWrapper);
    glutMainLoop();
    return 0;
}

void display(std::vector<wcPt2D>& vectorPuntos) {

    glBegin(GL_POLYGON);

    glColor3f(1.0, 0.0, 0.0); // Rojo
    glVertex2f(vectorPuntos[0].x, vectorPuntos[0].y);
        
    glColor3f(0.0, 1.0, 0.0); // Verde
    glVertex2f(vectorPuntos[1].x, vectorPuntos[1].y);
        
    glColor3f(0.0, 0.0, 1.0); // Azul
    glVertex2f(vectorPuntos[2].x, vectorPuntos[2].y);
    glEnd();

    wcPt2D pibote( 860.00, 420.00);
    scalePolygon(vectorPuntos, vectorPuntos.size(), pibote, 0.80, 0.80 );
   
    glutSwapBuffers();
}

void displayWrapper() {
    static std::vector<wcPt2D> vectorPuntos = {
        wcPt2D(450.00, 300.00),
        wcPt2D(450.00, 200.00),
        wcPt2D(300.00, 200.00),
    };

    display(vectorPuntos);
}

void scalePolygon(std::vector<wcPt2D>& verts, GLint nVerts, wcPt2D& fixedPt,
                  GLfloat sx, GLfloat sy)
{
    std::vector<wcPt2D> vertsNew;
    
    for (int k = 0; k < nVerts; k++)
    {   
        vertsNew.push_back(wcPt2D(verts[k].x * sx + fixedPt.x * (1 - sx),
                                  verts[k].y * sy + fixedPt.y * (1 - sy)));
    }

    glBegin(GL_POLYGON);
    for (int k = 0; k < nVerts; k++)
        glVertex2f(vertsNew[k].x, vertsNew[k].y); 
    glEnd();
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0); // Fondo blanco
}
