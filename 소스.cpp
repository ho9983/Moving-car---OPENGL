#include <glut.h>	
#include <math.h>
#include <GLU.H>
#include <gl.h>
#include <iostream>
#include <stdio.h>

int a[16] = { 220,97,144,152,55,171,108,86,168,99,0,207,238,235,233,167 }; // 색을 위한 배열 a,b,c
int b[16] = { 53,194,110,152,153,184,137,3,55,138,0,43,240,255,203,8 };
int c[16] = { 5,243,133,253,33,228,141,18,46,95,75,1,253,204,169,130 };
static float angle = 0.0, ratioF;
static float x = 0.0f, y = 1.75f, z = 5.0f;
static float lx = 0.10f, ly = 0.10f, lz = -1.0f;
static GLint carDisplayList;
float theta = 0.01, fxincr = 0.1, fzincr = 0, temp, theta1, fx = -30, fz = 1;
int xxxx = 0, yyyy = 0, kk = 0, moveCarVar = 0;


void changeSize(int w, int h) {
	// 화면을 늘이거나 줄일때 실행창에 영향을 주지 않기위해 만든 함수.
	
	if (h == 0)
		h = 1;
	ratioF = 1.0f * w / h;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glViewport(0, 0, w, h);

	gluPerspective(45, ratioF, 1, 1000);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(x, y, z,
		x + lx, y + ly, z + lz,
		0.0f, 1.0f, 0.0f);
}

void drawCar()
{

	glTranslatef(0.0, 0.8, 0.0);
	glEnable(GL_BLEND); //반투명 선언
	glBlendFunc(GL_ONE, GL_ZERO);
	
	// 자동차를 그리기 위한 선 따기. 각 알파벳은 설계도의 좌표점 이름이다.
	glBegin(GL_LINE_LOOP);
		glVertex3f(-1.12, -.48, 0.7);//a
		glVertex3f(-0.86, -.48, 0.7);//b
		glVertex3f(-.74, -0.2, 0.7);//c
		glVertex3f(-.42, -.2, 0.7);//d
		glVertex3f(-0.3, -.48, 0.7);//e
		glVertex3f(.81, -0.48, 0.7);//f
		glVertex3f(.94, -0.2, 0.7);//g
		glVertex3f(1.24, -.2, 0.7);//h
		glVertex3f(1.38, -.48, 0.7);//i
		glVertex3f(1.52, -.44, 0.7);//j
		glVertex3f(1.52, .14, 0.7);//k
		glVertex3f(1.14, 0.22, 0.7);//l
		glVertex3f(0.76, .22, 0.7);//m
		glVertex3f(.52, 0.56, 0.7);//n
		glVertex3f(-0.1, 0.6, 0.7);//0
		glVertex3f(-1.02, 0.6, 0.7);//p
		glVertex3f(-1.2, 0.22, 0.7);//q
		glVertex3f(-1.2, -.28, 0.7);//r
	glEnd();
	
	glBegin(GL_LINE_LOOP);
		glVertex3f(-1.12, -.48, -0.7);//a'
		glVertex3f(-0.86, -.48, -0.7);//b'
		glVertex3f(-.74, -0.2, -0.7);//c'
		glVertex3f(-.42, -.2, -0.7);//d'
		glVertex3f(-0.3, -.48, -0.7);//e'
		glVertex3f(.81, -0.48, -0.7);//f'
		glVertex3f(.94, -0.2, -0.7);//g'
		glVertex3f(1.24, -.2, -0.7);//h'
		glVertex3f(1.38, -.48, -0.7);//i'
		glVertex3f(1.52, -.44, -0.7);//j'
		glVertex3f(1.52, .14, -0.7);//k'
		glVertex3f(1.14, 0.22, -0.7);//l'
		glVertex3f(0.76, .22, -0.7);//m'
		glVertex3f(.52, 0.56, -0.7);//n'
		glVertex3f(-0.1, 0.6, -0.7);//o'
		glVertex3f(-1.02, 0.6, -0.7);//p'
		glVertex3f(-1.2, 0.22, -0.7);//q'
		glVertex3f(-1.2, -.28, -0.7);//r'
	glEnd();
	
	glBegin(GL_LINES);
		glVertex3f(-1.12, -.48, 0.7);//a
		glVertex3f(-1.12, -.48, -0.7);//a'
		glVertex3f(-0.86, -.48, 0.7);//b
		glVertex3f(-0.86, -.48, -0.7);//b'
		glVertex3f(-.74, -0.2, 0.7);//c
		glVertex3f(-.74, -0.2, -0.7);//c'
		glVertex3f(-.42, -.2, 0.7);//d
		glVertex3f(-.42, -.2, -0.7);//d'
		glVertex3f(-0.3, -.48, 0.7);//e
		glVertex3f(-0.3, -.48, -0.7);//e'
		glVertex3f(.81, -0.48, 0.7);//f
		glVertex3f(.81, -0.48, -0.7);//f'
		glVertex3f(.94, -0.2, 0.7);//g
		glVertex3f(.94, -0.2, -0.7);//g'
		glVertex3f(1.24, -.2, 0.7);//h
		glVertex3f(1.24, -.2, -0.7);//h'
		glVertex3f(1.38, -.48, 0.7);//i
		glVertex3f(1.38, -.48, -0.7);//i'
		glVertex3f(1.52, -.44, 0.7);//j
		glVertex3f(1.52, -.44, -0.7);//j'
		glVertex3f(1.52, .14, 0.7);//k
		glVertex3f(1.52, .14, -0.7);//k'
		glVertex3f(1.14, 0.22, 0.7);//l
		glVertex3f(1.14, 0.22, -0.7);//l'
		glVertex3f(0.76, .22, 0.7);//m
		glVertex3f(0.76, .22, -0.7);//m'
		glVertex3f(.52, 0.56, 0.7);//n
		glVertex3f(.52, 0.56, -0.7);//n'
		glVertex3f(-0.1, 0.6, 0.7);//0
		glVertex3f(-0.1, 0.6, -0.7);//o'
		glVertex3f(-1.02, 0.6, 0.7);//p
		glVertex3f(-1.02, 0.6, -0.7);//p'
		glVertex3f(-1.2, 0.22, 0.7);//q
		glVertex3f(-1.2, 0.22, -0.7);//q'
		glVertex3f(-1.2, -.28, 0.7);//r
		glVertex3f(-1.2, -.28, -0.7);//r'
	glEnd();
	

	// 자동차 천장 채우기
	glBegin(GL_POLYGON);
		glVertex3f(-0.1, 0.6, 0.7);//o
		glVertex3f(-0.1, 0.6, -0.7);//o'
		glVertex3f(-1.02, 0.6, -0.7);//p'
		glVertex3f(-1.02, 0.6, 0.7);//p
	glEnd();


	glBegin(GL_POLYGON);
		glVertex3f(-0.1, 0.6, 0.7);//o
		glVertex3f(-0.1, 0.6, -0.7);//o'
		glVertex3f(.52, 0.56, -0.7);//n'
		glVertex3f(.52, 0.56, 0.7);//n
	glEnd();

	//자동차 뒷면 채우기
	glBegin(GL_POLYGON);
		glVertex3f(-1.2, 0.22, 0.7);//q
		glVertex3f(-1.2, 0.22, -0.7);//q'
		glVertex3f(-1.2, -.28, -0.7);//r'
		glVertex3f(-1.2, -.28, 0.7);//r
	glEnd();


	
	glBegin(GL_POLYGON);
		glVertex3f(1.52, .14, 0.7);//k
		glVertex3f(1.14, 0.22, 0.7);//l
		glVertex3f(1.14, 0.22, -0.7);//l'
		glVertex3f(1.52, .14, -0.7);//k'
	glEnd();
	
	glBegin(GL_POLYGON);
		glVertex3f(0.76, .22, 0.7);//m
		glVertex3f(0.76, .22, -0.7);//m'
		glVertex3f(1.14, 0.22, -0.7);//l'
		glVertex3f(1.14, 0.22, 0.7);//l
	glEnd();
	
	glBegin(GL_POLYGON);
		glVertex3f(-1.12, -.48, 0.7);//a
		glVertex3f(-0.86, -.48, 0.7);//b
		glVertex3f(-.74, -0.2, 0.7);//c
		glVertex3f(-0.64, 0.22, 0.7);//cc
		glVertex3f(-1.08, 0.22, 0.7);//dd
		glVertex3f(-1.2, 0.22, 0.7);//q
		glVertex3f(-1.2, -.28, 0.7);//r
	glEnd();

	glBegin(GL_POLYGON);
		glVertex3f(-.74, -0.2, 0.7);//c
		glVertex3f(-0.64, 0.22, 0.7);//cc
		glVertex3f(-0.5, 0.22, 0.7);//hh
		glVertex3f(-0.5, -0.2, 0.7);//pp
	glEnd();
	
	// 바퀴 이음새부분 채우기
	glBegin(GL_POLYGON);
		glVertex3f(0.0, 0.22, 0.7);//gg
		glVertex3f(1.14, 0.22, 0.7);//l
		glVertex3f(1.24, -.2, 0.7);//h
		glVertex3f(0.0, -0.2, 0.7);//oo
	glEnd();
	
	//왼쪽 뒷바퀴 부분 비운곳 채우기
	glBegin(GL_POLYGON);
		glVertex3f(-1.12, -.48, -0.7);//a'
		glVertex3f(-0.86, -.48, -0.7);//b'
		glVertex3f(-.74, -0.2, -0.7);//c'
		glVertex3f(-0.64, 0.22, -0.7);//cc'
		glVertex3f(-1.08, 0.22, -0.7);//dd'
		glVertex3f(-1.2, 0.22, -0.7);//q'
		glVertex3f(-1.2, -.28, -0.7);//r'
	glEnd();
	
	// 나머지부분 모두 채우기
	glBegin(GL_POLYGON);
		glVertex3f(-.74, -0.2, -0.7);//c'
		glVertex3f(-0.64, 0.22, -0.7);//cc'
		glVertex3f(-0.5, 0.22, -0.7);//hh'
		glVertex3f(-0.5, -0.2, -0.7);//pp'
	glEnd();
	
	glBegin(GL_POLYGON);
		glVertex3f(0.0, 0.22, -0.7);//gg'
		glVertex3f(1.14, 0.22, -0.7);//l'
		glVertex3f(1.24, -.2, -0.7);//h'
		glVertex3f(0.0, -0.2, -0.7);//oo'
	glEnd();

	glBegin(GL_POLYGON);
		glVertex3f(-1.2, 0.22, 0.7);//q
		glVertex3f(-1.08, 0.22, 0.7);//dd
		glVertex3f(-0.98, 0.5, 0.7);//aa
		glVertex3f(-1.02, 0.6, 0.7);//p
	glEnd();
	
	glBegin(GL_POLYGON);
		glVertex3f(-1.02, 0.6, 0.7);//p
		glVertex3f(-0.98, 0.5, 0.7);//aa
		glVertex3f(0.44, 0.5, 0.7);//jj
		glVertex3f(.52, 0.56, 0.7);//n
		glVertex3f(-0.1, 0.6, 0.7);//0
	glEnd();

	glBegin(GL_POLYGON);
		glVertex3f(-0.64, 0.5, 0.7);//bb
		glVertex3f(-0.64, 0.22, 0.7);//cc
		glVertex3f(-0.5, 0.22, 0.7);//hh
		glVertex3f(-0.5, 0.5, 0.7);//ee
	glEnd();
	
	glBegin(GL_POLYGON);
		glVertex3f(0.0, 0.5, 0.7);//ff
		glVertex3f(0.0, 0.22, 0.7);//gg
		glVertex3f(0.12, 0.22, 0.7);//ll
		glVertex3f(0.12, 0.5, 0.7);//ii
	glEnd();

	glBegin(GL_POLYGON);
		glVertex3f(.52, 0.56, 0.7);//n
		glVertex3f(0.44, 0.5, 0.7);//jj
		glVertex3f(0.62, 0.22, 0.7);//kk
		glVertex3f(0.76, .22, 0.7);//m
	glEnd();
	
	// 자동차 밑부분
	glBegin(GL_POLYGON);
		glVertex3f(-.42, -.2, 0.7);//d
		glVertex3f(.94, -0.2, 0.7);//g
		glVertex3f(.81, -0.48, 0.7);//f
		glVertex3f(-0.3, -.48, 0.7);//e
	glEnd();
	
	// 자동차 밑부분
	glBegin(GL_POLYGON);
		glVertex3f(1.14, 0.22, 0.7);//l
		glVertex3f(1.52, .14, 0.7);//k
		glVertex3f(1.52, -.44, 0.7);//j
		glVertex3f(1.38, -.48, 0.7);//i
		glVertex3f(1.24, -.2, 0.7);//h
	glEnd();
	
	glBegin(GL_POLYGON);
		glVertex3f(-1.2, 0.22, -0.7);//q'
		glVertex3f(-1.08, 0.22, -0.7);//dd'
		glVertex3f(-0.98, 0.5, -0.7);//aa'
		glVertex3f(-1.02, 0.6, -0.7);//p'
	glEnd();
	
	// 천장과 유리가 맞닿은곳 채우기
	glBegin(GL_POLYGON);
		glVertex3f(-1.02, 0.6, -0.7);//p'
		glVertex3f(-0.98, 0.5, -0.7);//aa'
		glVertex3f(0.44, 0.5, -0.7);//jj'
		glVertex3f(.52, 0.56, -0.7);//n'
		glVertex3f(-0.1, 0.6, -0.7);//o'
	glEnd();

	glBegin(GL_POLYGON);
		glVertex3f(-0.64, 0.5, -0.7);//bb'
		glVertex3f(-0.64, 0.22, -0.7);//cc'
		glVertex3f(-0.5, 0.22, -0.7);//hh'
		glVertex3f(-0.5, 0.5, -0.7);//ee'
	glEnd();

	glBegin(GL_POLYGON);
		glVertex3f(0.0, 0.5, -0.7);//ff'
		glVertex3f(0.0, 0.22, -0.7);//gg'
		glVertex3f(0.12, 0.22, -0.7);//ll'
		glVertex3f(0.12, 0.5, -0.7);//ii'
	glEnd();
	
	glBegin(GL_POLYGON);
		glVertex3f(.52, 0.56, -0.7);//n'
		glVertex3f(0.44, 0.5, -0.7);//jj'
		glVertex3f(0.62, 0.22, -0.7);//kk'
		glVertex3f(0.76, .22, -0.7);//m'
	glEnd();

	glBegin(GL_POLYGON);
		glVertex3f(-.42, -.2, -0.7);//d'
		glVertex3f(.94, -0.2, -0.7);//g'
		glVertex3f(.81, -0.48, -0.7);//f'
		glVertex3f(-0.3, -.48, -0.7);//e'
	glEnd();

	glBegin(GL_POLYGON);
		glVertex3f(1.14, 0.22, -0.7);//l'
		glVertex3f(1.52, .14, -0.7);//k'
		glVertex3f(1.52, -.44, -0.7);//j'
		glVertex3f(1.38, -.48, -0.7);//i'
		glVertex3f(1.24, -.2, -0.7);//h'
	glEnd();
	
	
	// 오른쪽 뒷자석 차문
	glBegin(GL_POLYGON);
		glVertex3f(-0.5, 0.22, 0.7);//hh
		glVertex3f(0.0, 0.22, 0.7);//gg
		glVertex3f(0.0, -0.2, 0.7);//oo
		glVertex3f(-0.5, -0.2, 0.7);//pp
	glEnd();
	
	// 왼쪽 뒷자석 차문
	glBegin(GL_POLYGON);
		glVertex3f(-0.5, 0.22, -0.7);//hh'
		glVertex3f(0.0, 0.22, -0.7);//gg'
		glVertex3f(0.0, -0.2, -0.7);//oo'
		glVertex3f(-0.5, -0.2, -0.7);//pp'
	glEnd();
	
	
	glBegin(GL_POLYGON);
		glVertex3f(0.12, 0.22, 0.7);//ll
		glVertex3f(0.62, 0.22, 0.7);//kk
		glVertex3f(0.62, -0.2, 0.7);//mm
		glVertex3f(0.12, -0.2, 0.7);//nn
	glEnd();
	
	glBegin(GL_POLYGON);
		glVertex3f(0.12, 0.22, -0.7);//ll'
		glVertex3f(0.62, 0.22, -0.7);//kk'
		glVertex3f(0.62, -0.2, -0.7);//mm'
		glVertex3f(0.12, -0.2, -0.7);//nn'
	glEnd();
	
	
	// 후방에서 볼때 앞에 비어있는 곳 채우기
	glBegin(GL_POLYGON);
		glVertex3f(1.52, .14, 0.7);//k
		glVertex3f(1.52, .14, -0.7);//k'
		glVertex3f(1.52, -.44, -0.7);//j'
		glVertex3f(1.52, -.44, 0.7);//j
	glEnd();
	
	// 타이어그리기
	glTranslatef(-.58, -.52, 0.7);// 첫번째 타이어 translate
	glColor3f(0.1, 0.1, 0.1);// 타이어 색
	glutSolidTorus(0.12f, .14f, 10, 25);
	glTranslatef(1.68, 0.0, 0.0);// 두번째 타이어 translate
	glutSolidTorus(0.12f, .14f, 10, 25);

	glTranslatef(0.0, 0.0, -1.4);// 세번째 타이어 translate
	glutSolidTorus(0.12f, .14f, 10, 25);
	glTranslatef(-1.68, 0.0, 0.0);// 네번째 타이어 translate
	glutSolidTorus(0.12f, .14f, 10, 25);
	glTranslatef(.58, .52, 0.7);// 원본 타이어 translate
	glRotatef(90.0, 0.0, 1.0, 0.0);
	glTranslatef(0.0, 0.0, -1.40);

	glutSolidTorus(0.2f, .2f, 10, 25); // 차 뒤에 달린 타이어. 장식용.

	glTranslatef(0.0, 0.0, 1.40);
	glRotatef(270.0, 0.0, 1.0, 0.0);

	
	//glColor3f(1.0, 1.0, 1.0);

	// 자동차 창문 코드
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);// 유리는 반투명
	
	// 전방유리
	glBegin(GL_POLYGON);
	glColor4f(0.0, 0.0, 0.0, 0.7);   //색 : 반투명 검은색
		glVertex3f(0.562, .5, .6);//AAA
		glVertex3f(.562, .5, -.6);//AAA'
		glVertex3f(.76, .22, -.6);//MMM'
		glVertex3f(.76, .22, .6);//MMM
	glEnd();
	
	// 뒷유리
	glBegin(GL_POLYGON);
		glVertex3f(-1.068, 0.5, 0.6);//pp
		glVertex3f(-1.068, 0.5, -0.6);//pp'
		glVertex3f(-1.2, 0.22, -0.6);//qq'
		glVertex3f(-1.2, 0.22, 0.6);//qq
	glEnd();
	
	// 오른쪽 뒷자석 유리
	glBegin(GL_POLYGON);
	glVertex3f(-0.98, 0.5, 0.7);//aa
	glVertex3f(-0.64, 0.5, 0.7);//bb
	glVertex3f(-0.64, 0.22, 0.7);//cc
	glVertex3f(-1.08, 0.22, 0.7);//dd
	glEnd();
	
	// 왼쪽 뒷자석 유리
	glBegin(GL_POLYGON);
		glVertex3f(-0.98, 0.5, -0.7);//aa
		glVertex3f(-0.64, 0.5, -0.7);//bb
		glVertex3f(-0.64, 0.22, -0.7);//cc
		glVertex3f(-1.08, 0.22, -0.7);//dd
	glEnd();
	
	
	// 오른쪽 중간 유리
	glBegin(GL_POLYGON);
	glVertex3f(-0.5, 0.5, 0.7);
	glVertex3f(0.0, 0.5, 0.7);
	glVertex3f(0.0, 0.22, 0.7);
	glVertex3f(-0.5, 0.22, 0.7);
	glEnd();
	
	// 왼쪽 중간 유리
	glBegin(GL_POLYGON);
		glVertex3f(-0.5, 0.5, -0.7);
		glVertex3f(0.0, 0.5, -0.7);
		glVertex3f(0.0, 0.22, -0.7);
		glVertex3f(-0.5, 0.22, -0.7);
	glEnd();
	
	//오른쪽 앞좌석 유리
	glBegin(GL_POLYGON);
		glVertex3f(0.12, 0.5, 0.7);//ii
		glVertex3f(0.44, 0.5, 0.7);//jj
		glVertex3f(0.62, 0.22, 0.7);//kk
		glVertex3f(0.12, 0.22, 0.7);//ll
	glEnd();
	

	//왼쪽 앞좌석 유리

	glBegin(GL_POLYGON);
		glVertex3f(0.12, 0.5, -0.7);//ii'
		glVertex3f(0.44, 0.5, -0.7);//jj'
		glVertex3f(0.62, 0.22, -0.7);//kk'
		glVertex3f(0.12, 0.22, -0.7);//ll'
	glEnd();


	
	glColor3f(0.0, 0.0, 1.0);
}

void drawLine() { // 주차선 그리는 함수
	glLineWidth(5);
	
	// 오른쪽 차 앞 세로선
	glBegin(GL_LINE_LOOP);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(12.5, 0.0, 5.5);
	glVertex3f(12.5, 0.0, -9.5);
	glEnd();
	// 오른쪽 차 뒷 세로선
	glBegin(GL_LINE_LOOP);
	glVertex3f(17.5, 0.0, 5.5);
	glVertex3f(17.5, 0.0, -9.5);
	glEnd();
	
	// 파란색 차 부터 가로선 그림
	glBegin(GL_LINE_LOOP);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(12.5, 0.0, 5.5);
	glVertex3f(17.5, 0.0, 5.5);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(12.5, 0.0, 2.0);
	glVertex3f(17.5, 0.0, 2.0);
	glEnd();
	

	glBegin(GL_LINE_LOOP);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(12.5, 0.0, -2.5);
	glVertex3f(17.5, 0.0, -2.5);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(12.5, 0.0, -6.0);
	glVertex3f(17.5, 0.0, -6.0);
	glEnd();

	//민트색 차 마지막 가로선
	glBegin(GL_LINE_LOOP);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(12.5, 0.0, -9.5);
	glVertex3f(17.5, 0.0, -9.5);
	glEnd();
}


GLuint DisplayList() { // 리스트를 사용하여 속도향상. 인터넷에서 찾음
	GLuint carDL; //함수이름의 약자를 변수명으로 선언.

	// list 형성
	carDL = glGenLists(1);

	// 리스트 선언. 시작.
	glNewList(carDL, GL_COMPILE);

	// 자동차 그리는 함수 호출.
	drawCar();
	
	// list 끝
	glEndList();

	return(carDL);
}


void initScene()
{
	glEnable(GL_DEPTH_TEST); // 깊이 버퍼 형성
	carDisplayList = DisplayList(); // 470라인의 함수 호출
	//carDisplayList : 13라인의 전역변수 
}


void renderScene(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.7, 0.85, 1.0, 1.0); // 하늘색

	// 땅바닥 그리기

	glColor3f(0.25f, 0.25f, 0.25f); 
	glBegin(GL_QUADS); // 사각형
		glVertex3f(-50.0f, 0.0f, -50.0f);
		glVertex3f(-50.0f, 0.0f, 50.0f);
		glVertex3f(50.0f, 0.0f, 50.0f);
		glVertex3f(50.0f, 0.0f, -50.0f);
	glEnd();
	drawLine();
	// 주차장에 있는 차들을 그리기
	for (int i = -2; i < 2; i++) {
		glPushMatrix();
		glTranslatef(-15, 0, (i) * 4.0); // Translatef로 회전시켜서 그려준다.
		glColor3ub(c[i], b[i], b[i]); // 전역변수로 선언된 배열값으로 색을 넣는다.
		glCallList(carDisplayList);	// 리스트 호출.
		glPopMatrix();
	}
	for (int i = -2; i < 2; i++) {
			glPushMatrix();
			glTranslatef(0, 0, (i) * 4.0); // Translatef로 회전시켜서 그려준다.
			glColor3ub(a[i], a[i], c[i]); // 전역변수로 선언된 배열값으로 색을 넣는다.
			glCallList(carDisplayList);	// 리스트 호출.
			glPopMatrix();
		}
	for (int i = -2; i < 0; i++) {
		glPushMatrix();
		glTranslatef(15, 0, (i) * 4.0); // Translatef로 회전시켜서 그려준다.
		glColor3ub(a[i], b[i], c[i]); // 전역변수로 선언된 배열값으로 색을 넣는다.
		glCallList(carDisplayList);	// 리스트 호출.
		glPopMatrix();
	}
		glPushMatrix();
		glTranslatef(15, 0, 4.0); // Translatef로 회전시켜서 그려준다.
		glColor3ub(2, 32, 122); // 전역변수로 선언된 배열값으로 색을 넣는다.
		glCallList(carDisplayList);	// 리스트 호출.
		glPopMatrix();
	
	if (fxincr != 0) 
		theta1 = (atan(fzincr / fxincr) * 180) / 3.141;
	else if (fzincr>0)
		theta1 = -90.0;
	else 
		theta1 = 90.0;

	if (fxincr>0 && fzincr<0) { // 자동차가 회전을 할수 있도록 해줌.
		theta1 = -theta1;
	}
	else if (fxincr<0 && fzincr<0) {
		theta1 = 180 - theta1;
	}
	else if (fxincr<0 && fzincr>0) {
		theta1 = -180 - theta1;
	}
	else if (fxincr>0 && fzincr>0) {
		theta1 = -theta1;
	}
	
	//else theta1=90;
	//glLoadIdentity(); 생략
	
	glPushMatrix(); // 움직이는 차. 주차해야되는 차를 그린다.
	glTranslatef(fx, 0, fz);
	glRotatef(theta1, 0, 1, 0);
	glColor3f(1.0, 0.0, 0.0); 
	glCallList(carDisplayList);
	glPopMatrix();

	glutSwapBuffers();
}

void orientMe(float ang) { // 카메라 왼쪽, 오른쪽 돌아가는 함수
	lx = sin(ang);
	lz = -cos(ang);
	glLoadIdentity();
	gluLookAt(x, y, z,
		x + lx, y + ly, z + lz,
		0.0f, 1.0f, 0.0f);
}
void orientMe2(float ang) { // 카메라 위 아래로 돌아가는 함수
	ly = sin(ang);
	lz = -cos(ang);
	glLoadIdentity();
	gluLookAt(x, y, z,
		x + lx , y + ly, z + lz,
		0.0f, 1.0f, 0.0f);
}
void moveMeFlat(int i) { // 카메라 x, z 축을 따라 이동시키는 함수
	if (xxxx == 1)
		y = y + i*(lz)*0.1;

	if (yyyy == 1) {
		x = x + i*(lz)*0.1;
	}
	else {
		z = z + i*(lz)*0.5;
		x = x + i*(lx)*0.5;
	}
	glLoadIdentity();
	gluLookAt(x, y, z,
		x + lx, y + ly, z + lz,
		0.0f, 1.0f, 0.0f);
}

void processNormalKeys(unsigned char key, int x, int y) { // 화면 이동함수, 기능 함수
	glLoadIdentity();

	//static float x = 0.0f, y = 1.75f, z = 5.0f;
	//static float lx = 0.10f, ly = 0.10f, lz = -1.0f;
	if (key == 'q')
		exit(0);
	if (key == 't')
		gluLookAt(1, 50, 10,	0, 0, 0,		0.0, 1.0, .0);
	if (key == 'a') moveMeFlat(2); xxxx = 0, yyyy = 1;
	if (key == 'd') moveMeFlat(-2); xxxx = 0, yyyy = 0;
	if (key == 'w') moveMeFlat(2); yyyy = 0; xxxx = 0;
	if (key == 's') moveMeFlat(-2); yyyy = 1; xxxx = 0;
}


void cameraKey(int key, int x, int y) { // 화면 이동함수 2

	switch (key) 
	{
	case GLUT_KEY_LEFT: angle -= 0.05f; orientMe(angle); break;
	case GLUT_KEY_RIGHT: angle += 0.05f; orientMe(angle); break;
	case GLUT_KEY_UP: angle += 0.05f; orientMe2(angle); break;
	case GLUT_KEY_DOWN: angle -= 0.05f; orientMe2(angle); break;
	}
}
void moveCar(int key, int x, int y) {
	switch (key) {
		case GLUT_KEY_LEFT: // 왼쪽으로 전진하면서 돔
			temp = fxincr;
			fxincr = fxincr*cos(theta) + fzincr*sin(theta);
			fzincr = -temp*sin(theta) + fzincr*cos(theta);
			fx += fxincr;
			fz += fzincr;
			break;
	
		case GLUT_KEY_RIGHT: // 오른쪽으로 전진하면서 돔
			temp = fxincr; 
			fxincr = fxincr*cos(-theta) + fzincr*sin(-theta);
			fzincr = -temp*sin(-theta) + fzincr*cos(-theta);
			fx += fxincr;
			fz += fzincr;
			break;
	
		case GLUT_KEY_UP: // 전진
			fx += fxincr;
			fz += fzincr; 
			break;
	
		case GLUT_KEY_DOWN: // 후진
			fx -= fxincr;
			fz -= fzincr;
			break;
		}
	glutPostRedisplay();
}


void ProcessMenu(int value) { // 디스플레이 재 호출
	
	glutPostRedisplay();
}

void ProcessMenu1(int value) { // 메뉴콜백 함수
	switch (value) {
		case 1:	 // 만약 "차 움직이기" 를 메뉴에서 누르면 실행.
			if (moveCarVar == 0) { // var의 값이 0이었다면,
			glutSpecialFunc(moveCar); // moveCar 함수를 실행함으로서 차 움직임.
			moveCarVar = 1;
			}
			   else { // 그게 아니면 방향키로 카메라 기능 수행
				   glutSpecialFunc(cameraKey);
				   moveCarVar = 0;
				   glutPostRedisplay();
			   }
			   break;
	}
}
void menu()
{
	int control;
	int control1;

	control = glutCreateMenu(ProcessMenu);
	glutAddMenuEntry("--조작법--", 11);
	glutAddMenuEntry("1)  UP KEY : 카메라 위로 올림. ", 11);
	glutAddMenuEntry("2)  DOWN KEY : 카메라 아래로 숙임. ", 11);
	glutAddMenuEntry("3)  LEFT KEY : 카메라 왼쪽으로 돌림. ", 11);
	glutAddMenuEntry("4)  RIGHT KEY : 카메라 왼쪽으로 돌림. ", 11);
	glutAddMenuEntry("5)  d : +x 방향으로 이동 ", 11);
	glutAddMenuEntry("6)  a : -x 방향으로 이동", 11);
	glutAddMenuEntry("7)  s : 뒤로 후진 ", 11);
	glutAddMenuEntry("8)  w : 앞으로 전진", 11);
	glutAddMenuEntry("9)  t : 위에서 바라보기", 11);
	glutAddMenuEntry("10) q : 종료", 11);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	control1 = glutCreateMenu(ProcessMenu1);
	
	glutAddMenuEntry("차 움직이기", 1);
	glutAttachMenu(GLUT_LEFT_BUTTON);
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(1000, 500);
	glutCreateWindow("car parking");

	initScene();

	glutKeyboardFunc(processNormalKeys);
	glutSpecialFunc(cameraKey);
	
	menu();
	
	glutDisplayFunc(renderScene);
	glutIdleFunc(renderScene);
	glutReshapeFunc(changeSize);
	
	glutMainLoop();

	return(0);
}