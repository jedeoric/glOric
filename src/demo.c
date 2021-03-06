#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <tgi.h>

#include "glOric.h"
#include "config.h"

#include "alphabet.c"
#include "traj.c"
#include "fill8.c"

extern unsigned char une_fonction();
extern void glProject (char *tabpoint2D, char *tabpoint3D, unsigned char nbPoints, unsigned char opts);
extern int CamPosX, CamPosY, CamPosZ;
extern char CamRotZ, CamRotX;


unsigned char nbPts=0;
char points3d[NB_MAX_POINTS*SIZEOF_3DPOINT];
char points2d [NB_MAX_POINTS*SIZEOF_2DPOINT];

char segments[NB_MAX_SEGMENTS*SIZEOF_SEGMENT];
unsigned char nbSegments=0;

void addCube(char X, char Y, char Z){
	unsigned char ii, jj;
	for (jj=0; jj < NB_POINTS_CUBE; jj++){
		points3d[(nbPts+jj)* SIZEOF_3DPOINT + 0] = ptsCube[jj*SIZEOF_3DPOINT + 0] + X;  				// X coord
		points3d[(nbPts+jj)* SIZEOF_3DPOINT + 1] = ptsCube[jj*SIZEOF_3DPOINT + 1] + Y;                // Y coord
		points3d[(nbPts+jj)* SIZEOF_3DPOINT + 2] = ptsCube[jj*SIZEOF_3DPOINT + 2] + Z;                // Z coord
	}
	for (jj=0; jj < NB_SEGMENTS_CUBE; jj++){
		segments[(nbSegments+jj)* SIZEOF_SEGMENT + 0] = segCube[jj*SIZEOF_SEGMENT + 0]+nbPts; // Index Point 1
		segments[(nbSegments+jj)* SIZEOF_SEGMENT + 1] = segCube[jj*SIZEOF_SEGMENT + 1]+nbPts; // Index Point 2
		segments[(nbSegments+jj)* SIZEOF_SEGMENT + 2] = segCube[jj*SIZEOF_SEGMENT + 2]; // Character
	}
	nbPts += NB_POINTS_CUBE;
	nbSegments += NB_SEGMENTS_CUBE;
}


void hrDrawSegments(){

	unsigned char ii = 0;
	unsigned char idxPt1, idxPt2;
	int OtherPixelX, OtherPixelY, CurrentPixelX, CurrentPixelY;
	for (ii = 0; ii< nbSegments; ii++){

		idxPt1 =            segments[ii*SIZEOF_SEGMENT + 0];
		idxPt2 =            segments[ii*SIZEOF_SEGMENT + 1];

        //OtherPixelX= (int)points2d[idxPt1*SIZEOF_2DPOINT + 0];
		OtherPixelX=((int *)points2d)[idxPt1*2];
        //OtherPixelY= (int)points2d[idxPt1*SIZEOF_2DPOINT + 2];
		OtherPixelY=((int *)points2d)[idxPt1*2+1];

        //CurrentPixelX=(int)points2d[idxPt2*SIZEOF_2DPOINT + 0];
		CurrentPixelX=((int *)points2d)[idxPt2*2];
        //CurrentPixelY=(int)points2d[idxPt2*SIZEOF_2DPOINT + 2];
		CurrentPixelY=((int *)points2d)[idxPt2*2+1];
		printf("%d %d %d %d \n",
		OtherPixelX, OtherPixelY, CurrentPixelX, CurrentPixelY);
		cgetc();
		tgi_line(OtherPixelX,OtherPixelY,CurrentPixelX,CurrentPixelY);
	}
}

void hiresIntro (){
    int i;


	CamPosX = -24;
	CamPosY = 0;
	CamPosZ = 3;

 	CamRotZ = 64 ;
	CamRotX = 2;

    for (i=0;i<2;) {
		CamPosX = traj[i++];
		CamPosY = traj[i++];
		CamRotZ = traj[i++];
		i = i % (NB_POINTS_TRAJ*SIZE_POINTS_TRAJ);
        glProject (points2d, points3d, nbPts,0);
        //memset ( 0xa000, 64, 8000); // clear screen
		hrDrawSegments();
		//hrDrawFaces();
    }

	//leaveSC();

}

int main ()
{

	//unsigned char val;
	signed char i;
	fill8(7,3,3,1,1,5);
	printf ("----------\n");
	fill8(1,5,6,5,5,1);
	printf ("----------\n");
	fill8(-1,3,2,-1,5,5);
	/*
	tgi_install (tgi_static_stddrv);

	tgi_init ();
	tgi_clear ();
	*/

	/*initBuffers();*/

	/*
	blit_picture(1,1,william_pic[0]/6,william_pic[1], william_pic);
*/
	//tgi_outtextxy (50,50,"hello");
	/*tgi_setpixel(200,100);
	tgi_line(-10,-10,100,100);
*/
	//tgi_line(128,96,128,128);
	/*CamPosX = -24;
	CamPosY = 0;
	CamPosZ = 3;

 	CamRotZ = 64 ;
	CamRotX = 2;
	*/
	/*nbPts =0 ;
	nbSegments =0 ;
	addCube(-4, -4, 2);*/

	/*glProject (points2d, points3d, nbPts, 0);
	for (i=0; i< 12; i+=4) {
		printf ("%d %d %d %d =>",
			points3d[i+0],
			points3d[i+1],
			points3d[i+2],
			points3d[i+3]
		);
		printf ("%d %d %d %d\n",
			points2d[i+0],
			points2d[i+1],
			points2d[i+2],
			points2d[i+3]
		);
	}*/

	//	addCube(4, 4, 10);
	//tgi_line(135,7, 128, 124);
	//hiresIntro();

/*
	//val = une_fonction();
	printf("Value before	glProject: %d %d %d %d \n", points2d[1]<<8+points2d[0], points2d[3]<<8+points2d[2], points2d[5]<<8+points2d[4], points2d[7]<<8+points2d[6]);


	glProject (points2d, points3d, nbPts, 0);
	aVal=*((int *)points2d);
	//hrDrawSegments();
	printf("Value returned by glProject: %d %d %d %d %d \n", aVal, points2d[0], points2d[1], points2d[2], points2d[3]);
	printf("Value returned by glProject: %d %d %d %d \n", points2d[1]<<8+points2d[0], points2d[3]<<8+points2d[2], points2d[5]<<8+points2d[4], points2d[7]<<8+points2d[6]);
	*/
	/*tgi_line(points2d[1]<<8+points2d[0], points2d[3]<<8+points2d[2], points2d[5]<<8+points2d[4], points2d[7]<<8+points2d[6]);*
	*/
	cgetc();

	//tgi_done();

	return 0;
}
