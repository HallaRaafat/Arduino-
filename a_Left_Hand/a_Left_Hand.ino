/*
 There are 4 Line follower sensor 
 LT          SL          M        SR 
 LT -> means I read left path 
 SL -> means i deviated right while moving on line so i need a little speed in left direction 
 SR -> I deviated left so i need to move right 
 M -> to make sure in always reads as i am moving on line 
 
 */

#define SL 2  
#define M 4
#define SR 7
#define enB 9
#define In4 8
#define In3 10
#define In2 12
#define In1 13
#define enA 11
#define Out 3
#define S2 5
#define S3 6
#define Tx 0
#define Rx 1
#define LT  A0


int frequency;
int R,G,B;
int T1,T2,T3,T4;

int Delay=0;
int mspeed=65;
int LSpeed=80;
int RotSpeed=80;
int n=5;
