// main.c : définit le point d'entrée pour l'application console.
//
#include "stdafx.h"


int main(int argc, char*argv[])
{
	//[SECTION A] : DECLARATION DES VARIABLES LOCALES A LA FONCTION main() APRES CE COMMENTAIRE /////////
	int *pXL, *pYL,*pXD,*pYD,rValue;
	pXL = pYL = pXD = pYD = rValue = NULL;
	printf("=========== ENTER LetterKiller =======================\n\n");
	//[SECTION B] : INSERER LE CODE DE LA FONCTION PRINCIPALE APRES CE COMMENTAIRE //////////////////////
	LKInit();
	LKDisplay();
	rValue=LKGetCoordinates(&pXL,&pYL,&pXD,&pYD);
	////DEBUT Gestion code d'erreur/////////////
	switch (rValue)
	{
	case LKGC_GAME_ABORT_BIT:
		printf("Merci d'avoir joué au revoir! ;)");
		return EXIT_SUCCESS;
	case LKGC_YLROW_NEGATIVE_BIT:
		printf("ERREUR:Coordonnée y de la lettre a deplacé negative");
		break;
	case LKGC_YLROW_OVERMAX_BIT:
		printf("ERREUR:Coordonnée y de la lettre a deplacé est supérieur au nombre de lignes de la grille");
		break;
	case LKGC_XLCOL_NEGATIVE_BIT:
		printf("ERREUR:Coordonnée x de la lettre a deplacé negative");
		break;
	case LKGC_XLCOL_OVERMAX_BIT:
		printf("ERREUR:Coordonnée x de la lettre a deplacé est supérieur au nombre de collones de la grille");
		break;
	case LKGC_YDROW_NEGATIVE_BIT:
		printf("ERREUR:Coordonnée y de destination est negative");
		break;
	case LKGC_YDROW_OVERMAX_BIT:
		printf("ERREUR:Coordonnée y de destination est supérieur au nombre de lignes de la grille");
		break;
	case LKGC_XDCOL_NEGATIVE_BIT:
		printf("ERREUR:Coordonnée y de destination est negative");
		break;
	case LKGC_XDCOL_OVERMAX_BIT:
		printf("ERREUR:Coordonnée y de destination est supérieur au nombre de collones de la grille");
		break;
	case LKGC_VALID_INPUT_CODE:
		break;
	default:
		printf("ERREUR:Imprévue");
		break;
	}
	////FIN Gestion code erreur////////////
	printf("\nyLRow: %d", pYL);
	printf("\nxLCol: %d", pXL);
	printf("\nyDRow: %d", pYD);
	printf("\nxDCol: %d",pXD);

	LKValidateMove(pYL,pXL,pYD,pXD);
	//[SECTION C] : N'INSERER AUCUNE LIGNE DE CODE AU DELA DE CE COMMENTAIRE ////////////////////////////
	printf("\n=========== EXIT  LetterKiller =======================\n");
	system("PAUSE");
    return EXIT_SUCCESS;
}

//[SECTION D] : FIN DU FICHIER main.c : AUCUNE INSCRIPTION AU DELA DE CE COMMENTAIRE ////////////////////
