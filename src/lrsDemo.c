


void faceIntro() {
    int i;
    get();
    enterSC();

	CamPosX = 0;
	CamPosY = 0;
	CamPosZ = 1;

 	CamRotZ = 0;
	CamRotX = 0;

    for (i=0;i<120;) {
		CamPosX = traj[i++]/4;
		CamPosY = traj[i++]/4;
		CamRotZ = traj[i++];
		i = i % (NB_POINTS_TRAJ*SIZE_POINTS_TRAJ);
        glProject (points2d, points3d, nbPts);
        initScreenBuffers();
        fillFaces();
        lrDrawSegments();
        buffer2screen();
    }

/*	CamPosX = -8;
	CamPosY = 8;
	CamPosZ = 1;

 	CamRotZ = -32 ;
	CamRotX = 0;
	for (i= 0; i< 16; i++) {
		forward();
        glProject (points2d, points3d, nbPts);
        initScreenBuffers();
        fillFaces();
        lrDrawSegments();
        buffer2screen();
	}
*/
	leaveSC();

}
void txtGameLoop2() {

	char key;
    unsigned char ii;    
	//key=get();
	glProject (points2d, points3d, nbPts);
    
    
    /*printf ("(x=%d y=%d z=%d) [%d %d]\n", CamPosX, CamPosY, CamPosZ, CamRotZ, CamRotX);
        for (ii=0; ii< nbPts; ii++){
            printf ("[%d %d %d] => [%d %d] %d \n"
            , points3d [ii*SIZEOF_3DPOINT+0], points3d[ii*SIZEOF_3DPOINT+1], points3d[ii*SIZEOF_3DPOINT+2]
            , points2d [ii*SIZEOF_2DPOINT+0], points2d [ii*SIZEOF_2DPOINT+1], points2d[ii*SIZEOF_2DPOINT+2]
            );
        }
        get();
    */
	initScreenBuffers();
	fillFaces();
    lrDrawSegments();
    while (1==1) {
		//clearScreen();
		//drawSegments();
		buffer2screen();
		dispInfo();
		key=get();
		switch (key)	// key
		{
		case 8:	// gauche => tourne gauche
			CamRotZ += 4;
			break;
		case 9:	// droite => tourne droite
			CamRotZ -= 4;
			break;
		case 10: // bas => recule
			backward();
			break;
		case 11: // haut => avance
			forward();
			break;
		case 80: // P
			CamPosZ += 1;
			break;
		case 59: // ;
			CamPosZ -= 1;
			break;
		case 81: // Q
			CamRotX += 2;
			break;
		case 65: // A
			CamRotX -= 2;
			break;
		case 90: // Z
			shiftLeft();
			break;
		case 88: // X
			shiftRight();
			break;
		}
		glProject (points2d, points3d, nbPts);
		initScreenBuffers();
		fillFaces();
        lrDrawSegments();
	}
}

void faceDemo(){
	nbPts =0 ;
	nbSegments =0 ;
    nbFaces =0 ;
	//addCube3(-12, -12, 0);
    //addCube3(0, 0, 0);
    //addPlan();
    addPlan(0, 2, 2, 64, '.');
    addPlan(2, 0, 2, 0, ':');
    addPlan(0, -2, 2, 64, ';');
    addPlan(-2, 0, 2, 0, '\'');
    //addPlan(4, 4, 2, 64, ':');
    //printf ("nbPoints = %d, nbSegments = %d, nbFaces = %d\n",nbPts, nbSegments, nbFaces);
	lores0();
	faceIntro();

    /*CamPosX = -8;
	CamPosY = 0;
	CamPosZ = 2;

 	CamRotZ = 0;
	CamRotX = 0;
    */

	txtGameLoop2();

}