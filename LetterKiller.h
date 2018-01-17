// LetterKiller.h : contient les prototypes de fonctions et les constantes du jeu.
//

#define NB_ROW		10
#define NB_COL		10
#define CHAR_VOID	'.'


#define LKGC_VALID_INPUT_CODE		0x00000000
#define LKGC_GAME_ABORT_BIT			0x00000001

#define LKGC_YLROW_NEGATIVE_BIT		0x00000002
#define LKGC_YLROW_OVERMAX_BIT		0x00000004
#define LKGC_XLCOL_NEGATIVE_BIT		0x00000008
#define LKGC_XLCOL_OVERMAX_BIT		0x00000010

#define LKGC_YDROW_NEGATIVE_BIT		0x00000020
#define LKGC_YDROW_OVERMAX_BIT		0x00000040
#define LKGC_XDCOL_NEGATIVE_BIT		0x00000080
#define LKGC_XDCOL_OVERMAX_BIT		0x00000100
#define LKGC_WRONG_INPUT_CODE		0x00000200

typedef struct tt_vector {
	int x;
	int y;
}t_vector;


void LKInit(void);
void LKDisplay(void);
int LKGetCoordinates(int *pXLCol,int *pYLRow,int *pXDCol,int *pYDRow);
bool LKValidateMove(int yLrow, int xLcol, int yDrow, int xDcol);
