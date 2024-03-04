#include <GL/glut.h>
#include<vector>
#include<iostream>

class wcPt2D{
public:
    wcPt2D(GLfloat x, GLfloat y):x{x}, y{y} {}
    //wcPt2D(GLint x, GLint y): x{x}, y{y}{}
    GLfloat x, y;
    //GLint x, y;
};

void translatePolygon(std::vector<wcPt2D> verts, GLint nVerts, GLfloat tx, GLfloat ty);
void init();
void display(std::vector<wcPt2D>& vectorPuntos);
void displayWrapper();

int main(int argc, char** argv) {

 glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    //glutInitWindowPosition(500, 200);
    glutCreateWindow("Triangulo en OpenGL");
    init();
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 400, 0, 400);
    glutDisplayFunc(displayWrapper);
    glutMainLoop();
    return 0;
}

void translatePolygon(std::vector<wcPt2D> verts, GLint nVerts, GLfloat tx, GLfloat ty){
    GLint k;
    for (k = 0; k < nVerts; k++)
    {
        verts[k].x = verts[k].x + tx;
        verts[k].y = verts[k].y + ty;
    }
    glBegin(GL_POLYGON);
    for (k = 0; k < nVerts; k++){
        std::cout << "x = " << verts[k].x << "y = " << verts[k].y;
        glVertex2f(verts[k].x, verts[k].y);
    }    
    glEnd();
}

void display(std::vector<wcPt2D>& vectorPuntos) {
// void display(){ 
  //  glClear(GL_COLOR_BUFFER_BIT);
    
   // int pointA[] = {50, 50};
   // int pointB[] = {150, 50};
   // int pointC[] = {150, 150};
   // int pointD[] = {50, 150};
    
   // glColor3f(1.0, 0.0, 0.0);
   /* 
    glBegin(GL_POLYGON);

        glColor3f(1.0, 0.0, 0.0);
        glVertex2iv(pointA);
        glVertex2iv(pointB);
        glColor3f(0.0, 1.0, 0.0);
        glVertex2iv(pointC);
        glColor3f(0.0, 0.0, 1.0);
        glVertex2iv(pointD);

        //  glColor3f(1.0, 0.0, 0.0); // Rojo
        //  glVertex2f(-0.5, -0.5);

        //  glColor3f(0.0, 1.0, 0.0); // Verde
        //  glVertex2f(0.5, -0.5);

        //  glColor3f(0.0, 0.0, 1.0); // Azul
        //  glVertex2f(0.0, 0.5);

        glEnd();
*/
    glBegin(GL_POLYGON);

        glColor3f(1.0, 0.0, 0.0); // Rojo
        glVertex2f(vectorPuntos[0].x, vectorPuntos[0].y);
        
        glColor3f(0.0, 1.0, 0.0); // Verde
        glVertex2f(vectorPuntos[1].x, vectorPuntos[1].y);
        
        glColor3f(0.0, 0.0, 1.0); // Azul
        glVertex2f(vectorPuntos[2].x, vectorPuntos[2].y);
    glEnd();

    translatePolygon(vectorPuntos, vectorPuntos.size(), 80.00, 140.00 );

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
        wcPt2D(70.00, 60.00),
        wcPt2D(60.00, 40.00),
        wcPt2D(80.00, 40.00),
    };
    
    display(vectorPuntos2);


}


void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0); // Fondo blanco
}