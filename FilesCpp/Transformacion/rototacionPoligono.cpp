#include <GL/glut.h>
#include<vector>
#include<iostream>
#include<math.h>

class wcPt2D{
public:
    wcPt2D(GLfloat x, GLfloat y):x{x}, y{y} {}
    //wcPt2D(GLint x, GLint y): x{x}, y{y}{}
    GLfloat x, y;
    //GLint x, y;
};

void rotatePolygon(std::vector<wcPt2D> verts, GLint nVerts, wcPt2D pivPt, GLdouble theta);
void init();
void display(std::vector<wcPt2D>& vectorPuntos);
void displayWrapper();

int main(int argc, char** argv) {

 glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Triangulo en OpenGL");
    init();
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 400, 0, 400);
    glutDisplayFunc(displayWrapper);
    glutMainLoop();
    return 0;
}

void rotatePolygon(std::vector<wcPt2D> verts, GLint nVerts, wcPt2D pivPt, GLdouble theta){
    std::vector<wcPt2D> vertsRot;
    GLint k;

    for (k = 0; k < nVerts; k++)
    {
        vertsRot.push_back(wcPt2D(pivPt.x + (verts[k].x - pivPt.x) * cos(theta) - (verts[k].y - pivPt.y) * sin(theta),
        pivPt.y + (verts[k].x - pivPt.x) * sin(theta) + (verts[k].y - pivPt.y) * cos(theta)) );
    }

    glBegin(GL_POLYGON);
    for (k = 0; k < nVerts; k++)
        glVertex2f(vertsRot[k].x, vertsRot[k].y);
    glEnd();
}

void display(std::vector<wcPt2D>& vectorPuntos) {
// void display(){ 
  //  glClear(GL_COLOR_BUFFER_BIT);
    
   // int pointA[] = {50, 50};
   // int pointB[] = {150, 50};
   // int pointC[] = {150, 150};
   // int pointD[] = {50, 150};
    
    /*
        glColor3f(1.0, 0.0, 0.0);
        glVertex2iv(pointA);
        glVertex2iv(pointB);
        glColor3f(0.0, 1.0, 0.0);
        glVertex2iv(pointC);
        glColor3f(0.0, 0.0, 1.0);
        glVertex2iv(pointD)
    */

    glBegin(GL_POLYGON);

        glColor3f(1.0, 0.0, 0.0); // Rojo
        glVertex2f(vectorPuntos[0].x, vectorPuntos[0].y);
        
        glColor3f(0.0, 1.0, 0.0); // Verde
        glVertex2f(vectorPuntos[1].x, vectorPuntos[1].y);
        
        glColor3f(0.0, 0.0, 1.0); // Azul
        glVertex2f(vectorPuntos[2].x, vectorPuntos[2].y);
    glEnd();
    wcPt2D pibote(160,20.00);
    rotatePolygon(vectorPuntos, vectorPuntos.size(), pibote, 00.00 );

    glutSwapBuffers();
    // glFlush();
}

void displayWrapper() {
    static std::vector<wcPt2D> vectorPuntos = {
        wcPt2D(-0.5, -0.5),
        wcPt2D(0.5, -0.5),
        wcPt2D(0.0, 0.5),
    };

    static std::vector<wcPt2D> vectorPuntos2 = {
        wcPt2D(160.00, 20.00),
        wcPt2D(300.00, 100.00),
        wcPt2D(300.00, 20.00),
        
    };
    
    display(vectorPuntos2);


}


void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0); // Fondo blanco
}