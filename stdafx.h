// stdafx.h : fichier Include pour les fichiers Include système standard,
// ou les fichiers Include spécifiques aux projets qui sont utilisés fréquemment,
// et sont rarement modifiés
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

// TODO: faites référence ici aux en-têtes supplémentaires nécessaires au programme

#include "LetterKiller.h"



//Macros utilitaires //////////////////////////////////////////////////////////////
#define mBitsSet(flags,mask)		(flags|=(mask))
#define mBitsClr(flags,mask)		(flags&=~(mask))
#define mBitsMsk(flags,mask)		(flags&(mask))
#define mBitsTgl(flags,mask)		(flags^=(mask))
#define mIsBitsSet(flags,mask)		((flags&(mask))==(mask))
#define mIsBitsClr(flags,mask)		((~flags&(mask))==(mask))

//#define XY_BAD_INPUT_CODE 0x0000
