#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>


void fullscreen() ///function definition for fullscreen source: https://www.dreamincode.net/forums/topic/59497-run-a-c-program-in-full-screen/
{  keybd_event(VK_MENU,
				0x38,
				0,
				0);
	keybd_event(VK_RETURN,
				0x1c,
				0,
				0);
	keybd_event(VK_RETURN,
				0x1c,
				KEYEVENTF_KEYUP,
				0);
	keybd_event(VK_MENU,
				0x38,
				KEYEVENTF_KEYUP,
				0);
}


void color(int t,int f) /// http://www.cplusplus.com/forum/beginner/54360/
{
HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(H,f*16+t);
}


void table()
{
    printf("\n"
           "\n"
           "\t\t\t\t\t  	    ");color(15,3);printf(" 0     1     2     3     4     5     6     7     8  \n");color(3,15);
     	   printf("\t\t\t\t\t  	  ");color(15,3);printf("0 ");colorchang(0,0,A[0][0]);printf("---");colorchang(0,1,A[0][1]);printf("---");colorchang(0,2,A[0][2]);printf("---");colorchang(0,3,A[0][3]);printf("---");colorchang(0,4,A[0][4]);printf("---");colorchang(0,5,A[0][5]);printf("---");colorchang(0,6,A[0][6]);printf("---");colorchang(0,7,A[0][7]);printf("---");colorchang(0,8,A[0][8]);printf(" \n");color(3,15);
     	   printf("\t\t\t\t\t  	  ");color(15,3);printf("   ");printf("|");printf("     |     |     |     |     |     |     |     |  \n");color(3,15);
     	   printf("\t\t\t\t\t  	  ");color(15,3);printf("   ");printf("|");printf("     |     |     |     |     |     |     |     |  \n");color(3,15);
     	   printf("\t\t\t\t\t  	  ");color(15,3);printf("   ");printf("|");printf("     |     |     |     |     |     |     |     |  \n");color(3,15);
           printf("\t\t\t\t\t  	  ");color(15,3);printf("1 ");colorchang(1,0,A[1][0]);printf("---");colorchang(1,1,A[1][1]);printf("---");colorchang(1,2,A[1][2]);printf("---");colorchang(1,3,A[1][3]);printf("---");colorchang(1,4,A[1][4]);printf("---");colorchang(1,5,A[1][5]);printf("---");colorchang(1,6,A[1][6]);printf("---");colorchang(1,7,A[1][7]);printf("---");colorchang(1,8,A[1][8]);printf(" \n");color(3,15);
           printf("\t\t\t\t\t  	  ");color(15,3);printf("   ");printf("|");printf("     |     |     |     |     |     |     |     |  \n");color(3,15);
           printf("\t\t\t\t\t  	  ");color(15,3);printf("   ");printf("|");printf("     |     |     |     |     |     |     |     |  \n");color(3,15);
     	   printf("\t\t\t\t\t  	  ");color(15,3);printf("   ");printf("|");printf("     |     |     |     |     |     |     |     |  \n");color(3,15);
     	   printf("\t\t\t\t\t  	  ");color(15,3);printf("2 ");colorchang(2,0,A[2][0]);printf("---");colorchang(2,1,A[2][1]);printf("---");colorchang(2,2,A[2][2]);printf("---");colorchang(2,3,A[2][3]);printf("---");colorchang(2,4,A[2][4]);printf("---");colorchang(2,5,A[2][5]);printf("---");colorchang(2,6,A[2][6]);printf("---");colorchang(2,7,A[2][7]);printf("---");colorchang(2,8,A[2][8]);printf(" \n");color(3,15);
      	   printf("\t\t\t\t\t  	  ");color(15,3);printf("   ");printf("|");printf("     |     |     |     |     |     |     |     |  \n");color(3,15);
     	   printf("\t\t\t\t\t  	  ");color(15,3);printf("   ");printf("|");printf("     |     |     |     |     |     |     |     |  \n");color(3,15);
    	   printf("\t\t\t\t\t  	  ");color(15,3);printf("   ");printf("|");printf("     |     |     |     |     |     |     |     |  \n");color(3,15);
      	   printf("\t\t\t\t\t  	  ");color(15,3);printf("3 ");colorchang(3,0,A[3][0]);printf("---");colorchang(3,1,A[3][1]);printf("---");colorchang(3,2,A[3][2]);printf("---");colorchang(3,3,A[3][3]);printf("---");colorchang(3,4,A[3][4]);printf("---");colorchang(3,5,A[3][5]);printf("---");colorchang(3,6,A[3][6]);printf("---");colorchang(3,7,A[3][7]);printf("---");;colorchang(3,8,A[3][8]);printf(" \n");color(3,15);
	       printf("\t\t\t\t\t  	  ");color(15,3);printf("   ");printf("|");printf("     |     |     |     |     |     |     |     |  \n");color(3,15);
	       printf("\t\t\t\t\t  	  ");color(15,3);printf("   ");printf("|");printf("     |     |     |     |     |     |     |     |  \n");color(3,15);
	       printf("\t\t\t\t\t  	  ");color(15,3);printf("   ");printf("|");printf("     |     |     |     |     |     |     |     |  \n");color(3,15);
	       printf("\t\t\t\t\t  	  ");color(15,3);printf("4 ");colorchang(4,0,A[4][0]);printf("---");colorchang(4,1,A[4][1]);printf("---");colorchang(4,2,A[4][2]);printf("---");colorchang(4,3,A[4][3]);printf("---");colorchang(4,4,A[4][4]);printf("---");colorchang(4,5,A[4][5]);printf("---");colorchang(4,6,A[4][6]);printf("---");colorchang(4,7,A[4][7]);printf("---");colorchang(4,8,A[4][8]);printf(" \n");color(3,15);
	       printf("\t\t\t\t\t  	  ");color(15,3);printf("   ");printf("|");printf("     |     |     |     |     |     |     |     |  \n");color(3,15);
	       printf("\t\t\t\t\t   	  ");color(15,3);printf("   ");printf("|");printf("     |     |     |     |     |     |     |     |  \n");color(3,15);
	       printf("\t\t\t\t\t  	  ");color(15,3);printf("   ");printf("|");printf("     |     |     |     |     |     |     |     |  \n");color(3,15);
	       printf("\t\t\t\t\t  	  ");color(15,3);printf("5 ");colorchang(5,0,A[5][0]);printf("---");colorchang(5,1,A[5][1]);printf("---");colorchang(5,2,A[5][2]);printf("---");colorchang(5,3,A[5][3]);printf("---");colorchang(5,4,A[5][4]);printf("---");colorchang(5,5,A[5][5]);printf("---");colorchang(5,6,A[5][6]);printf("---");colorchang(5,7,A[5][7]);printf("---");colorchang(5,8,A[5][8]);printf(" \n");color(3,15);
	       printf("\t\t\t\t\t  	  ");color(15,3);printf("   ");printf("|");printf("     |     |     |     |     |     |     |     |  \n");color(3,15);
	       printf("\t\t\t\t\t  	  ");color(15,3);printf("   ");printf("|");printf("     |     |     |     |     |     |     |     |  \n");color(3,15);
	       printf("\t\t\t\t\t  	  ");color(15,3);printf("   ");printf("|");printf("     |     |     |     |     |     |     |     |  \n");color(3,15);
	       printf("\t\t\t\t\t  	  ");color(15,3);printf("6 ");colorchang(6,0,A[6][0]);printf("---");colorchang(6,1,A[6][1]);printf("---");colorchang(6,2,A[6][2]);printf("---");colorchang(6,3,A[6][3]);printf("---");colorchang(6,4,A[6][4]);printf("---");colorchang(6,5,A[6][5]);printf("---");colorchang(6,6,A[6][6]);printf("---");colorchang(6,7,A[6][7]);printf("---");colorchang(6,8,A[6][8]);printf(" \n");color(3,15);
	       printf("\t\t\t\t\t  	  ");color(15,3);printf("   ");printf("|");printf("     |     |     |     |     |     |     |     |  \n");color(3,15);
	       printf("\t\t\t\t\t  	  ");color(15,3);printf("   ");printf("|");printf("     |     |     |     |     |     |     |     |  \n");color(3,15);
	       printf("\t\t\t\t\t  	  ");color(15,3);printf("   ");printf("|");printf("     |     |     |     |     |     |     |     |  \n");color(3,15);
	       printf("\t\t\t\t\t  	  ");color(15,3);printf("7 ");colorchang(7,0,A[7][0]);printf("---");colorchang(7,1,A[7][1]);printf("---");colorchang(7,2,A[7][2]);printf("---");colorchang(7,3,A[7][3]);printf("---");colorchang(7,4,A[7][4]);printf("---");colorchang(7,5,A[7][5]);printf("---");colorchang(7,6,A[7][6]);printf("---");colorchang(7,7,A[7][7]);printf("---");colorchang(7,8,A[7][8]);printf(" \n");color(3,15);
	       printf("\t\t\t\t\t  	  ");color(15,3);printf("   ");printf("|");printf("     |     |     |     |     |     |     |     |  \n");color(3,15);
           printf("\t\t\t\t\t  	  ");color(15,3);printf("   ");printf("|");printf("     |     |     |     |     |     |     |     |  \n");color(3,15);
	       printf("\t\t\t\t\t  	  ");color(15,3);printf("   ");printf("|");printf("     |     |     |     |     |     |     |     |  \n");color(3,15);
	       printf("\t\t\t\t\t  	  ");color(15,3);printf("8 ");colorchang(8,0,A[8][0]);printf("---");colorchang(8,1,A[8][1]);printf("---");colorchang(8,2,A[8][2]);printf("---");colorchang(8,3,A[8][3]);printf("---");colorchang(8,4,A[8][4]);printf("---");colorchang(8,5,A[8][5]);printf("---");colorchang(8,6,A[8][6]);printf("---");colorchang(8,7,A[8][7]);printf("---");colorchang(8,8,A[8][8]);printf(" \n");color(3,15);

    capture();
    selectionJVM();
}

