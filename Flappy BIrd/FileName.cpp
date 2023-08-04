#include<stdlib.h>
#include<GL/glut.h>
#include<time.h>
#include<dos.h>
#include<stdio.h>
#include<iostream>
#include<windows.h>
#include<string>
clock_t start, end;
int win1, win2;
void Write(float x, float y, float z, float scale, char* s)
{
	int i, l = strlen(s);
	glPushMatrix();
	glTranslatef(x, y, z);
	glScalef(scale, scale, scale);
	for (i = 0; i < l; i++)
		glutStrokeCharacter(GLUT_STROKE_ROMAN, s[i]);
	glPopMatrix();
}
void frontsheet(void)
{
	glClearColor(0.3, 0.3, 0.3, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	Write(-0.9, 0.9, 1, 0.0007, (char*)"TIET , Patiala");
	Write(-0.38, 0.8, 1, 0.0006, (char*)"CSED");
	glColor3f(1.0, 0.6, 0.0);
	Write(-0.42, 0.6, 0.0, 0.0007, (char*)"Flappy Bird");
	glColor3f(1.0, 1.0, 0.5);
	Write(-0.4, -0.8, 0.0, 0.0006, (char*)"Press 'S' to continue");
	glColor3f(1, 1, 0.0);
	Write(-1.0, 0.1, 0.0, 0.0007, (char*)"Submitted By :");
	glColor3f(1.0, 1.0, 1.0);
	Write(-1.0, -0.03, 0.0, 0.0006, (char*)"1. Aviral Jain : 102016049");
	Write(-1.0, -0.13, 0.0, 0.0006, (char*)"2. Keerti Chib : 102016047");
	Write(-1.0, -0.23, 0.0, 0.0006, (char*)"3. Aastha Chhabra : 102016054");
	glColor3f(1, 1, 0.0);
	Write(-1.0, -0.4, 0.0, 0.0007, (char*)"Submitted to : ");
	glColor3f(1.0, 1.0, 1.0);
	Write(-1.0, -0.5, 0.0, 0.0006, (char*)" Diksha Mam");
	glFlush();
}
float bspd = 0.02; // block dx value
//char name[25];
float b1x = 50.0, b1y = 0;//block 1 init position
float hm = 0.0;//bird moving dy value
int i = 0, sci = 1; float scf = 1; // for increment score score_int score_flag
char scs[20], slevel[20];
//to store score_string using itoa() and level as well

int level = 1, lflag = 1, wflag = 1; //level_flag & welcome_flag init w/1
void init(void)
{
	srand(time(0));//it generates a random no each time code is executed
	b1y = (rand() % 45) + 10;//b/w 10 to 44
	glClearColor(0.49, 0.81, 0.89, 0.0);
	glShadeModel(GL_SMOOTH);
	glLoadIdentity();
	glOrtho(0.0, 100.0, 0.0, 100.0, -1.0, .0);
}
void drawbird()
{
	glBegin(GL_POLYGON); //Body
	glColor3f(0.984, 0.952, 0.1411);
	glVertex2f(10, 48.32);
	glVertex2f(10.96, 46.56);
	glVertex2f(13.92, 44.8);
	glVertex2f(15.88, 44.8);
	glVertex2f(18.84, 46.56);
	glVertex2f(19.8, 48.32);
	glVertex2f(19.8, 50.08);
	glVertex2f(18.84, 51.84);
	glVertex2f(15.88, 53.6);
	glVertex2f(13.92, 53.6);
	glVertex2f(10.96, 51.84);
	glVertex2f(10, 50.08);
	glEnd();
	glBegin(GL_POLYGON); //Body shading
	glColor3f(0.992, 0.734, 0.062);
	glVertex2f(15.5, 47.16);
	glVertex2f(10, 48.32);
	glVertex2f(10.96, 46.56);
	glVertex2f(13.92, 44.8);
	glVertex2f(15.88, 44.8);
	glVertex2f(18.84, 46.56);
	glVertex2f(19.8, 48.32);
	glEnd();
	glBegin(GL_POLYGON); //Beak
	glColor3f(0.99, 0.40, 0.294);
	glVertex2f(16, 49.2);
	glVertex2f(19.8, 50.08);
	glVertex2f(20.5, 50.08);
	glVertex2f(20.5, 49.88);
	glVertex2f(19.8, 49.44);
	glVertex2f(20.5, 49);
	glVertex2f(20.5, 48.32);
	glEnd();
	glBegin(GL_POLYGON); //Eye
	glColor3f(1.0, 1.0, 1.0);
	glVertex2f(17.36, 52.72);
	glVertex2f(14.8, 51.9);
	glVertex2f(14.1, 50.84);
	glVertex2f(14.1, 50.56);
	glVertex2f(14.98, 49.85);
	glVertex2f(18.84, 49.85);
	glVertex2f(19.8, 50.09);
	glVertex2f(18.84, 51.85);
	glEnd();
	glBegin(GL_POLYGON); //Tail
	glColor3f(1.0, 1.0, 1.0);
	glVertex2f(13.5, 47);
	glVertex2f(13.5, 49);
	glVertex2f(11.3, 50.4);
	glVertex2f(9.2, 50.2);
	glVertex2f(8.3, 49.7);
	glVertex2f(8.3, 48);
	glVertex2f(11.86, 46.7);
	glEnd();
	glBegin(GL_POLYGON); //Tail shading
	glColor3f(0.984, 0.952, 0.1411);
	glVertex2f(10.5, 48);
	glVertex2f(8.3, 48.5);
	glVertex2f(8.3, 48);
	glVertex2f(11.86, 46.7);
	glVertex2f(13.3, 47);
	glVertex2f(13.3, 48.5);
	glEnd();
	glColor3f(0.0, 0.0, 0.0); //Eye Retina
	glRectf(17.7, 51.5, 18.7, 50.08);
}
void renderBitmapString(float x, float y, float z, void* font, const char* string)
{
	const char* c;
	glRasterPos3f(x, y, z);
	for (c = string; *c != '\0'; c++)
	{
		glutBitmapCharacter(font, *c);
	}
}
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	//GameOver Checking
	if ((i == 730 || i == -700)
		//top and bottom checking
		||
		(((int)b1x == 10 || (int)b1x == 7 || (int)b1x == 4 || (int)b1x == 1) && (int)b1y < 53 + (int)hm && (int)b1y + 35>53 + (int)hm)
		// front checking
		||
		(((int)b1x == 9 || (int)b1x == 3 || (int)b1x == 6) && (int)b1y < 45 + (int)hm && (int)b1y + 35>45 + (int)hm)
		//lower body checking
		||
		(((int)b1x == 0) && (int)b1y < 46 + (int)hm && (int)b1y + 35>46 + (int)hm))
		// lower tail checking
	{
		glColor3f(0.3, 0.3, 0.3);
		glRectf(0.0, 0.0, 100.0, 100.0);
		glColor3f(0.61, 0.82, 0.36);
		renderBitmapString(40, 70, 0, GLUT_BITMAP_HELVETICA_18, "GAME OVER!!!");
		glColor3f(1.0, 1.0, 1.0);
		renderBitmapString(32, 40, 0, GLUT_BITMAP_HELVETICA_18, "Close the console window to exit...");
		//renderBitmapString(45, 58, 0, GLUT_BITMAP_TIMES_ROMAN_24, "scored:");
		renderBitmapString(70, 58, 0, GLUT_BITMAP_TIMES_ROMAN_24, scs
		);
		glutSwapBuffers();
		glFlush();
		end = clock();
		printf("Survival time : %lf s", double(end - start) / double(CLOCKS_PER_SEC));
		printf("\nBetter luck next time !\n\n");
		system("pause");
		//printf("%s\You scored %s", name, scs);
		exit(0);
		//getch();
	}
	else
	{
		glPushMatrix();
		glColor3f(0.0, 0.5, 0.7);
		glRectf(0.0, 0.0, 100.0, 10.0); //ceil
		glRectf(0.0, 100.0, 100.0, 90.0); //floor
		glColor3f(0.0, 0.0, 0.0); //score
		// renderBitmapString(1, 3, 0, GLUT_BITMAP_TIMES_ROMAN_24, "Distance:");
		//glColor3f(0.7,0.7,0.7);
		scf += 0.025; //so less as program run very fast
		sci = (int)scf;
		printf(scs, "%d", sci);
		//from int to char convertion to display score
		renderBitmapString(20, 3, 0, GLUT_BITMAP_TIMES_ROMAN_24, scs)
			;
		glTranslatef(0.0, hm, 0.0);
		// hm(=dy) changes occur by mouse func
		drawbird();
		//if wall move towards left & get out of projection volume
		if (b1x < -10)
		{
			b1x = 50; //total width is 50
			b1y = (rand() % 25) + 20;
			//10 for selling+10 for giving enough space
			// block bottom limit 0+20 & top limit 24+20=44
		}
		else
			b1x -= bspd;
		//within the projection volume dec its x value by block_speed
		glTranslatef(b1x, -hm, 0.0);
		glColor3f(0.61, 0.82, 0.36);
		glRectf(b1x, b1y, b1x + 10, b1y + 35);//block 1
		glPopMatrix();
		glutSwapBuffers();
		glFlush();
	}
}
void moveBirdU(void)
{
	hm += 0.05;
	i++;
	glutPostRedisplay();
}
void moveBirdD()
{
	hm -= 0.05;
	i--;
	glutPostRedisplay();
}
void mouse(int button, int state, int x, int y)
{
	switch (button)
	{
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN)
			glutIdleFunc(moveBirdU);
		else if (state == GLUT_UP)
			glutIdleFunc(moveBirdD);
		break;
	default: break;
	}
}
void keys(unsigned char key, int x, int y)
{
	if (key == 'w') glutIdleFunc(moveBirdU);
	if (key == 's') glutIdleFunc(moveBirdD);
}
void keyboards(unsigned char key, int x4, int y4)
{
	if (key == 's' || key == 'S')
	{
		glutDestroyWindow(win1);
		glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
		win2 = glutCreateWindow("Flappy Bird");
		glClearColor(0.0, 0.0, 0.0, 0.0);
		glFlush();
		glutDisplayFunc(display);
		gluOrtho2D(-1000, 1000, 0, 1000);
		init();
		glutMouseFunc(mouse);
		glutKeyboardFunc(keys);
	}
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(960, 1080);
	glutInitWindowPosition(0, 0);
	win1 = glutCreateWindow("Flappy Bird");
	glFlush();
	start = clock();
	glutDisplayFunc(frontsheet);
	glutKeyboardFunc(keyboards);
	glutMainLoop();
	return 0;
}