// LetterKiller.c : contient les fonctions du jeu.
//
#include "stdafx.h"
int i, j, k;

const char tableInit[NB_ROW][NB_COL] =
{
	{ '.','A','A','.','.','E','B','C','.','A' },
	{ 'E','.','.','C','D','D','E','D','E','.' },
	{ '.','A','E','A','.','E','B','.','A','.' },
	{ 'D','A','.','C','A','C','.','B','B','A' },
	{ 'D','.','C','A','C','E','C','B','A','.' },
	{ '.','.','D','E','E','D','A','E','A','.' },
	{ 'E','.','.','B','.','B','.','B','.','D' },
	{ '.','E','.','D','D','.','D','B','E','D' },
	{ 'A','E','.','.','D','A','A','.','.','.' },
	{ 'C','.','B','B','A','D','A','.','C','A' }
};

char table[NB_ROW][NB_COL];

t_vector vectorAxis[4] = {
	{1,0},
	{1,1},
	{0,1},
	{-1,1}
};

void LKInit(void)
{
	//printf("A implementer : void LKInit(void)\n");
	for ( j = 0; j < NB_ROW; j++)
	{
		for (k= 0; k < NB_COL; k++)
		{
			table[j][k] = tableInit[j][k];
		}
	}
}

void LKDisplay(void)
{
	////////////////////////

	printf("     ");
	for (i = 0; i < NB_COL; i++)
	{
		if (i % 5 == 0) printf("%d  ", i / 10);			//Affichage indice dizaine Colonnes
		else printf("   ");
	}
	printf("\n");

	printf("     ");
	for (i = 0; i < NB_COL; i++)		//Affichage indice unité Colonnes
	{
		printf("%d  ", i % 10);
	}

	printf("\n   --");
	for (i = 0; i < NB_COL; i++)
	{
		printf("---");
	}
	printf("\n");

	for (int j = 0; j < NB_ROW; j++)		//Affichage de la grille grid[row][col]
	{
		if (j<10)						//repere compté lignes
		{
			printf(" %d | ", j);
		}
		else
		{
			printf("%d | ", j);			//repere compté lignes
		}

		for (int k = 0; k < NB_COL; k++)
		{

			printf("%c  ", table[j][k]);		//Affichage de la grille

		}
		printf("|\n");
	}
	printf("   --");
	for (i = 0; i < NB_COL; i++)
	{
		printf("---");
	}	
}

int LKGetCoordinates(int *pXLCol, int *pYLRow, int *pXDCol, int *pYDRow)
{
	char i;
	char buffer[16];
	char *pToken = NULL;
	for (i = 0; i < sizeof buffer; i++)
	{
		buffer[i] = 0;
	}

	fflush(stdin);
	printf("\nEntrez les coordonnees de la lettre et celle de sa destination (ex: yLettre xLettre ydestination xdestination) :");
	if (fgets(buffer, sizeof buffer, stdin))
	{
		if ((pToken = strtok(buffer, " \n")) != NULL)
		{
			if ((*pToken == 'q') || (*pToken == 'Q'))return LKGC_GAME_ABORT_BIT;					//quit Game
			*pYLRow = strtol(pToken, NULL, 10);				//y Lettre
			if (*pYLRow < 0)return LKGC_YLROW_NEGATIVE_BIT;
			if (*pYLRow >= NB_ROW)return LKGC_YLROW_OVERMAX_BIT;

		}
		if ((pToken = strtok(NULL, " \n")) != NULL)
		{
			if ( (*pToken == 'q') || (*pToken == 'Q') )return LKGC_GAME_ABORT_BIT; 					//quit Game
			*pXLCol =strtol(pToken, NULL, 10);				//x Lettre
			if (*pXLCol < 0)return LKGC_XLCOL_NEGATIVE_BIT;
			if (*pXLCol >= NB_COL)return LKGC_XLCOL_OVERMAX_BIT;
			
		}
		
		if ((pToken = strtok(NULL, " \n")) != NULL)
		{
			if ((*pToken == 'q') || (*pToken == 'Q'))return LKGC_GAME_ABORT_BIT;					//quit Game
			*pYDRow = strtol(pToken, NULL, 10);				//y Destination
			if (*pYDRow < 0)return LKGC_YDROW_NEGATIVE_BIT;
			if (*pYDRow >= NB_ROW)return LKGC_YDROW_OVERMAX_BIT;

		}
		if ((pToken = strtok(NULL, " \n")) != NULL)
		{
			if ( (*pToken == 'q') || (*pToken == 'Q') )return LKGC_GAME_ABORT_BIT;					//quit Game
			*pXDCol = strtol(pToken, NULL, 10);				//x Destination
			if (*pXDCol < 0)return LKGC_XDCOL_NEGATIVE_BIT;
			if (*pXDCol >= NB_COL)return LKGC_XDCOL_OVERMAX_BIT;

		}
		
	}
	return LKGC_VALID_INPUT_CODE;
}

bool LKValidateMove(int yLrow, int xLcol, int yDrow, int xDcol)
{
	if (table[yDrow][xDcol]==CHAR_VOID)
	{
		printf("\nLa cellule en table[%d][%d] est vide", yDrow, xDcol);
		return true;
		
	}
	else
	{
		printf("\nLa cellule en table[%d][%d] n'est pas vide", yDrow, xDcol);
		return false;
	}
}


