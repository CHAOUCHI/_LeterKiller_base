// stdafx.h�: fichier Include pour les fichiers Include syst�me standard,
// ou les fichiers Include sp�cifiques aux projets qui sont utilis�s fr�quemment,
// et sont rarement modifi�s
//

#pragma once

#include "targetver.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <tchar.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <wchar.h>

// TODO: faites r�f�rence ici aux en-t�tes suppl�mentaires n�cessaires au programme

#include "LetterKiller.h"



//Macros utilitaires //////////////////////////////////////////////////////////////
#define mBitsSet(flags,mask)		(flags|=(mask))
#define mBitsClr(flags,mask)		(flags&=~(mask))
#define mBitsMsk(flags,mask)		(flags&(mask))
#define mBitsTgl(flags,mask)		(flags^=(mask))
#define mIsBitsSet(flags,mask)		((flags&(mask))==(mask))
#define mIsBitsClr(flags,mask)		((~flags&(mask))==(mask))

//#define XY_BAD_INPUT_CODE 0x0000
