#include <glut.h>	
#include <math.h>
#include <GLU.H>
#include <gl.h>
#include <iostream>
#include <stdio.h>

int a[16] = { 220,97,144,152,55,171,108,86,168,99,0,207,238,235,233,167 }; // ���� ���� �迭 a,b,c
int b[16] = { 53,194,110,152,153,184,137,3,55,138,0,43,240,255,203,8 };
int c[16] = { 5,243,133,253,33,228,141,18,46,95,75,1,253,204,169,130 };
static float angle = 0.0, ratioF;
static float x = 0.0f, y = 1.75f, z = 5.0f;
static float lx = 0.10f, ly = 0.10f, lz = -1.0f;
static GLint carDisplayList;
float theta = 0.01, fxincr = 0.1, fzincr = 0, temp, theta1, fx = -30, fz = 1;
int xxxx = 0, yyyy = 0, kk = 0, moveCarVar = 0;


void changeSize(int w, int h) {
	// ȭ���� ���̰ų� ���϶� ����â�� ������ ���� �ʱ����� ���� �Լ�.
	
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
	glEnable(GL_BLEND); //������ ����
	glBlendFunc(GL_ONE, GL_ZERO);
	
	// �ڵ����� �׸��� ���� �� ����. �� ���ĺ��� ���赵�� ��ǥ�� �̸��̴�.
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
	

	// �ڵ��� õ�� ä���
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

	//�ڵ��� �޸� ä���
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
	
	// ���� �������κ� ä���
	glBegin(GL_POLYGON);
		glVertex3f(0.0, 0.22, 0.7);//gg
		glVertex3f(1.14, 0.22, 0.7);//l
		glVertex3f(1.24, -.2, 0.7);//h
		glVertex3f(0.0, -0.2, 0.7);//oo
	glEnd();
	
	//���� �޹��� �κ� ���� ä���
	glBegin(GL_POLYGON);
		glVertex3f(-1.12, -.48, -0.7);//a'
		glVertex3f(-0.86, -.48, -0.7);//b'
		glVertex3f(-.74, -0.2, -0.7);//c'
		glVertex3f(-0.64, 0.22, -0.7);//cc'
		glVertex3f(-1.08, 0.22, -0.7);//dd'
		glVertex3f(-1.2, 0.22, -0.7);//q'
		glVertex3f(-1.2, -.28, -0.7);//r'
	glEnd();
	
	// �������κ� ��� ä���
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
	
	// �ڵ��� �غκ�
	glBegin(GL_POLYGON);
		glVertex3f(-.42, -.2, 0.7);//d
		glVertex3f(.94, -0.2, 0.7);//g
		glVertex3f(.81, -0.48, 0.7);//f
		glVertex3f(-0.3, -.48, 0.7);//e
	glEnd();
	
	// �ڵ��� �غκ�
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
	
	// õ��� ������ �´����� ä���
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
	
	
	// ������ ���ڼ� ����
	glBegin(GL_POLYGON);
		glVertex3f(-0.5, 0.22, 0.7);//hh
		glVertex3f(0.0, 0.22, 0.7);//gg
		glVertex3f(0.0, -0.2, 0.7);//oo
		glVertex3f(-0.5, -0.2, 0.7);//pp
	glEnd();
	
	// ���� ���ڼ� ����
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
	
	
	// �Ĺ濡�� ���� �տ� ����ִ� �� ä���
	glBegin(GL_POLYGON);
		glVertex3f(1.52, .14, 0.7);//k
		glVertex3f(1.52, .14, -0.7);//k'
		glVertex3f(1.52, -.44, -0.7);//j'
		glVertex3f(1.52, -.44, 0.7);//j
	glEnd();
	
	// Ÿ�̾�׸���
	glTranslatef(-.58, -.52, 0.7);// ù��° Ÿ�̾� translate
	glColor3f(0.1, 0.1, 0.1);// Ÿ�̾� ��
	glutSolidTorus(0.12f, .14f, 10, 25);
	glTranslatef(1.68, 0.0, 0.0);// �ι�° Ÿ�̾� translate
	glutSolidTorus(0.12f, .14f, 10, 25);

	glTranslatef(0.0, 0.0, -1.4);// ����° Ÿ�̾� translate
	glutSolidTorus(0.12f, .14f, 10, 25);
	glTranslatef(-1.68, 0.0, 0.0);// �׹�° Ÿ�̾� translate
	glutSolidTorus(0.12f, .14f, 10, 25);
	glTranslatef(.58, .52, 0.7);// ���� Ÿ�̾� translate
	glRotatef(90.0, 0.0, 1.0, 0.0);
	glTranslatef(0.0, 0.0, -1.40);

	glutSolidTorus(0.2f, .2f, 10, 25); // �� �ڿ� �޸� Ÿ�̾�. ��Ŀ�.

	glTranslatef(0.0, 0.0, 1.40);
	glRotatef(270.0, 0.0, 1.0, 0.0);

	
	//glColor3f(1.0, 1.0, 1.0);

	// �ڵ��� â�� �ڵ�
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);// ������ ������
	
	// ��������
	glBegin(GL_POLYGON);
	glColor4f(0.0, 0.0, 0.0, 0.7);   //�� : ������ ������
		glVertex3f(0.562, .5, .6);//AAA
		glVertex3f(.562, .5, -.6);//AAA'
		glVertex3f(.76, .22, -.6);//MMM'
		glVertex3f(.76, .22, .6);//MMM
	glEnd();
	
	// ������
	glBegin(GL_POLYGON);
		glVertex3f(-1.068, 0.5, 0.6);//pp
		glVertex3f(-1.068, 0.5, -0.6);//pp'
		glVertex3f(-1.2, 0.22, -0.6);//qq'
		glVertex3f(-1.2, 0.22, 0.6);//qq
	glEnd();
	
	// ������ ���ڼ� ����
	glBegin(GL_POLYGON);
	glVertex3f(-0.98, 0.5, 0.7);//aa
	glVertex3f(-0.64, 0.5, 0.7);//bb
	glVertex3f(-0.64, 0.22, 0.7);//cc
	glVertex3f(-1.08, 0.22, 0.7);//dd
	glEnd();
	
	// ���� ���ڼ� ����
	glBegin(GL_POLYGON);
		glVertex3f(-0.98, 0.5, -0.7);//aa
		glVertex3f(-0.64, 0.5, -0.7);//bb
		glVertex3f(-0.64, 0.22, -0.7);//cc
		glVertex3f(-1.08, 0.22, -0.7);//dd
	glEnd();
	
	
	// ������ �߰� ����
	glBegin(GL_POLYGON);
	glVertex3f(-0.5, 0.5, 0.7);
	glVertex3f(0.0, 0.5, 0.7);
	glVertex3f(0.0, 0.22, 0.7);
	glVertex3f(-0.5, 0.22, 0.7);
	glEnd();
	
	// ���� �߰� ����
	glBegin(GL_POLYGON);
		glVertex3f(-0.5, 0.5, -0.7);
		glVertex3f(0.0, 0.5, -0.7);
		glVertex3f(0.0, 0.22, -0.7);
		glVertex3f(-0.5, 0.22, -0.7);
	glEnd();
	
	//������ ���¼� ����
	glBegin(GL_POLYGON);
		glVertex3f(0.12, 0.5, 0.7);//ii
		glVertex3f(0.44, 0.5, 0.7);//jj
		glVertex3f(0.62, 0.22, 0.7);//kk
		glVertex3f(0.12, 0.22, 0.7);//ll
	glEnd();
	

	//���� ���¼� ����

	glBegin(GL_POLYGON);
		glVertex3f(0.12, 0.5, -0.7);//ii'
		glVertex3f(0.44, 0.5, -0.7);//jj'
		glVertex3f(0.62, 0.22, -0.7);//kk'
		glVertex3f(0.12, 0.22, -0.7);//ll'
	glEnd();


	
	glColor3f(0.0, 0.0, 1.0);
}

void drawLine() { // ������ �׸��� �Լ�
	glLineWidth(5);
	
	// ������ �� �� ���μ�
	glBegin(GL_LINE_LOOP);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(12.5, 0.0, 5.5);
	glVertex3f(12.5, 0.0, -9.5);
	glEnd();
	// ������ �� �� ���μ�
	glBegin(GL_LINE_LOOP);
	glVertex3f(17.5, 0.0, 5.5);
	glVertex3f(17.5, 0.0, -9.5);
	glEnd();
	
	// �Ķ��� �� ���� ���μ� �׸�
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

	//��Ʈ�� �� ������ ���μ�
	glBegin(GL_LINE_LOOP);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(12.5, 0.0, -9.5);
	glVertex3f(17.5, 0.0, -9.5);
	glEnd();
}


GLuint DisplayList() { // ����Ʈ�� ����Ͽ� �ӵ����. ���ͳݿ��� ã��
	GLuint carDL; //�Լ��̸��� ���ڸ� ���������� ����.

	// list ����
	carDL = glGenLists(1);

	// ����Ʈ ����. ����.
	glNewList(carDL, GL_COMPILE);

	// �ڵ��� �׸��� �Լ� ȣ��.
	drawCar();
	
	// list ��
	glEndList();

	return(carDL);
}


void initScene()
{
	glEnable(GL_DEPTH_TEST); // ���� ���� ����
	carDisplayList = DisplayList(); // 470������ �Լ� ȣ��
	//carDisplayList : 13������ �������� 
}


void renderScene(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.7, 0.85, 1.0, 1.0); // �ϴû�

	// ���ٴ� �׸���

	glColor3f(0.25f, 0.25f, 0.25f); 
	glBegin(GL_QUADS); // �簢��
		glVertex3f(-50.0f, 0.0f, -50.0f);
		glVertex3f(-50.0f, 0.0f, 50.0f);
		glVertex3f(50.0f, 0.0f, 50.0f);
		glVertex3f(50.0f, 0.0f, -50.0f);
	glEnd();
	drawLine();
	// �����忡 �ִ� ������ �׸���
	for (int i = -2; i < 2; i++) {
		glPushMatrix();
		glTranslatef(-15, 0, (i) * 4.0); // Translatef�� ȸ�����Ѽ� �׷��ش�.
		glColor3ub(c[i], b[i], b[i]); // ���������� ����� �迭������ ���� �ִ´�.
		glCallList(carDisplayList);	// ����Ʈ ȣ��.
		glPopMatrix();
	}
	for (int i = -2; i < 2; i++) {
			glPushMatrix();
			glTranslatef(0, 0, (i) * 4.0); // Translatef�� ȸ�����Ѽ� �׷��ش�.
			glColor3ub(a[i], a[i], c[i]); // ���������� ����� �迭������ ���� �ִ´�.
			glCallList(carDisplayList);	// ����Ʈ ȣ��.
			glPopMatrix();
		}
	for (int i = -2; i < 0; i++) {
		glPushMatrix();
		glTranslatef(15, 0, (i) * 4.0); // Translatef�� ȸ�����Ѽ� �׷��ش�.
		glColor3ub(a[i], b[i], c[i]); // ���������� ����� �迭������ ���� �ִ´�.
		glCallList(carDisplayList);	// ����Ʈ ȣ��.
		glPopMatrix();
	}
		glPushMatrix();
		glTranslatef(15, 0, 4.0); // Translatef�� ȸ�����Ѽ� �׷��ش�.
		glColor3ub(2, 32, 122); // ���������� ����� �迭������ ���� �ִ´�.
		glCallList(carDisplayList);	// ����Ʈ ȣ��.
		glPopMatrix();
	
	if (fxincr != 0) 
		theta1 = (atan(fzincr / fxincr) * 180) / 3.141;
	else if (fzincr>0)
		theta1 = -90.0;
	else 
		theta1 = 90.0;

	if (fxincr>0 && fzincr<0) { // �ڵ����� ȸ���� �Ҽ� �ֵ��� ����.
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
	//glLoadIdentity(); ����
	
	glPushMatrix(); // �����̴� ��. �����ؾߵǴ� ���� �׸���.
	glTranslatef(fx, 0, fz);
	glRotatef(theta1, 0, 1, 0);
	glColor3f(1.0, 0.0, 0.0); 
	glCallList(carDisplayList);
	glPopMatrix();

	glutSwapBuffers();
}

void orientMe(float ang) { // ī�޶� ����, ������ ���ư��� �Լ�
	lx = sin(ang);
	lz = -cos(ang);
	glLoadIdentity();
	gluLookAt(x, y, z,
		x + lx, y + ly, z + lz,
		0.0f, 1.0f, 0.0f);
}
void orientMe2(float ang) { // ī�޶� �� �Ʒ��� ���ư��� �Լ�
	ly = sin(ang);
	lz = -cos(ang);
	glLoadIdentity();
	gluLookAt(x, y, z,
		x + lx , y + ly, z + lz,
		0.0f, 1.0f, 0.0f);
}
void moveMeFlat(int i) { // ī�޶� x, z ���� ���� �̵���Ű�� �Լ�
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

void processNormalKeys(unsigned char key, int x, int y) { // ȭ�� �̵��Լ�, ��� �Լ�
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


void cameraKey(int key, int x, int y) { // ȭ�� �̵��Լ� 2

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
		case GLUT_KEY_LEFT: // �������� �����ϸ鼭 ��
			temp = fxincr;
			fxincr = fxincr*cos(theta) + fzincr*sin(theta);
			fzincr = -temp*sin(theta) + fzincr*cos(theta);
			fx += fxincr;
			fz += fzincr;
			break;
	
		case GLUT_KEY_RIGHT: // ���������� �����ϸ鼭 ��
			temp = fxincr; 
			fxincr = fxincr*cos(-theta) + fzincr*sin(-theta);
			fzincr = -temp*sin(-theta) + fzincr*cos(-theta);
			fx += fxincr;
			fz += fzincr;
			break;
	
		case GLUT_KEY_UP: // ����
			fx += fxincr;
			fz += fzincr; 
			break;
	
		case GLUT_KEY_DOWN: // ����
			fx -= fxincr;
			fz -= fzincr;
			break;
		}
	glutPostRedisplay();
}


void ProcessMenu(int value) { // ���÷��� �� ȣ��
	
	glutPostRedisplay();
}

void ProcessMenu1(int value) { // �޴��ݹ� �Լ�
	switch (value) {
		case 1:	 // ���� "�� �����̱�" �� �޴����� ������ ����.
			if (moveCarVar == 0) { // var�� ���� 0�̾��ٸ�,
			glutSpecialFunc(moveCar); // moveCar �Լ��� ���������μ� �� ������.
			moveCarVar = 1;
			}
			   else { // �װ� �ƴϸ� ����Ű�� ī�޶� ��� ����
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
	glutAddMenuEntry("--���۹�--", 11);
	glutAddMenuEntry("1)  UP KEY : ī�޶� ���� �ø�. ", 11);
	glutAddMenuEntry("2)  DOWN KEY : ī�޶� �Ʒ��� ����. ", 11);
	glutAddMenuEntry("3)  LEFT KEY : ī�޶� �������� ����. ", 11);
	glutAddMenuEntry("4)  RIGHT KEY : ī�޶� �������� ����. ", 11);
	glutAddMenuEntry("5)  d : +x �������� �̵� ", 11);
	glutAddMenuEntry("6)  a : -x �������� �̵�", 11);
	glutAddMenuEntry("7)  s : �ڷ� ���� ", 11);
	glutAddMenuEntry("8)  w : ������ ����", 11);
	glutAddMenuEntry("9)  t : ������ �ٶ󺸱�", 11);
	glutAddMenuEntry("10) q : ����", 11);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	control1 = glutCreateMenu(ProcessMenu1);
	
	glutAddMenuEntry("�� �����̱�", 1);
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