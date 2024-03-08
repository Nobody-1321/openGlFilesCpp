#include<GL/glut.h>
#include<math.h>
#include<stdlib.h>
class wcPt2D {
public:
GLfloat x, y;
};


inline GLint round (const GLfloat a) { return GLint (a + 0.5); }
/* Define a four-bit code for each of the outside regions of a
* rectangular clipping window.
*/

const GLint winLeftBitCode = 0x1;
const GLint winRightBitCode = 0x2;
const GLint winBottomBitCode = 0x4;
const GLint winTopBitCode = 0x8;



/* A bit-mask region code is also assigned to each endpoint of an input
* line segment, according to its position relative to the four edges of
* an input rectangular clip window.
*
* An endpoint with a region-code value of 0000 is inside the clipping
* window, otherwise it is outside at least one clipping boundary. If
* the 'or' operation for the two endpoint codes produces a value of
* false, the entire line defined by these two endpoints is saved
* (accepted). If the 'and' operation between two endpoint codes is
* true, the line is completely outside the clipping window, and it is
* eliminated (rejected) from further processing.
*/

inline GLint inside (GLint code) { return GLint (!code); }

inline GLint reject (GLint code1, GLint code2)
{ return GLint (code1 & code2); }

inline GLint accept (GLint code1, GLint code2)
{ return GLint (!(code1 | code2)); }

GLubyte encode(wcPt2D pt, wcPt2D winMin, wcPt2D winMax)
{
    GLubyte code = 0x00;
    if (pt.x < winMin.x)
        code = code | winLeftBitCode;
    if (pt.x > winMax.x)
        code = code | winRightBitCode;
    if (pt.y < winMin.y)
        code = code | winBottomBitCode;
    if (pt.y > winMax.y)
        code = code | winTopBitCode;
    return (code);
}

void swapPts(wcPt2D *p1, wcPt2D *p2)
{
    wcPt2D tmp;
    tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}
void swapCodes(GLubyte *c1, GLubyte *c2)
{
    GLubyte tmp;
    tmp = *c1;
    *c1 = *c2;
    *c2 = tmp;
}

void setPixel (int x, int y){
    glPointSize(5.0);
    glBegin(GL_POINTS);
    glColor3f(1.0,0.0,0.0);
    glVertex2i(x, y);
    glEnd();
}

void linesBrem(int x0, int y0, int xEnd, int yEnd){
    int dx = fabs(xEnd - x0), dy = fabs(yEnd - y0);
    int p = 2 * dy - dx;
    int twoDy = 2 * dy, twoDyMinusDx = 2 * (dy- dx);
    int x, y;

    if (x0 > xEnd){
        x = xEnd;
        y = yEnd;
        xEnd = x0;
    }else{
        x = x0;
        y = y0;
    }

    setPixel(x, y);

    while (x<xEnd){
        x++;
        if(p < 0){
            p += twoDy;
        }else{
            y++;
            p += twoDyMinusDx;
        }
        setPixel(x, y);

    }
}
void lineClipCohSuth (wcPt2D winMin, wcPt2D winMax, wcPt2D p1, wcPt2D p2){

    GLubyte code1, code2;
    GLint done = false, plotLine = false;
    GLfloat m; 

    while (!done) {
        code1 = encode (p1, winMin, winMax);
        code2 = encode (p2, winMin, winMax);
        if (accept (code1, code2)) {
            done = true;
            plotLine = true;
        }else
            if (reject (code1, code2))
            done = true;
        else {
            /* Label the endpoint outside the display window as p1. */
            if (inside(code1))
            {
                swapPts(&p1, &p2);
                swapCodes(&code1, &code2);
            }
        }        
        /* Use slope m to find line-clipEdge intersection. */
        if (p2.x != p1.x)
            m = (p2.y - p1.y) / (p2.x - p1.x);
        if (code1 & winLeftBitCode) {
            p1.y += (winMin.x - p1.x) * m;
            p1.x = winMin.x;
        }else
            if (code1 & winRightBitCode) {
            p1.y += (winMax.x - p1.x) * m;
            p1.x = winMax.x;
        }else
            if (code1 & winBottomBitCode) {
            /* Need to update p1.x for nonvertical lines only. */
                 if (p2.x != p1.x)
                    p1.x += (winMin.y - p1.y) / m;
                p1.y = winMin.y;
            }
            else
                if (code1 & winTopBitCode) {
                    if (p2.x != p1.x)
                        p1.x += (winMax.y - p1.y) / m;
                    p1.y = winMax.y;
                }
     }
    
    if (plotLine)
        linesBrem (round (p1.x), round (p1.y), round (p2.x), round (p2.y));
}