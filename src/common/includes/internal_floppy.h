/*
//
// Copyright (C) 2006, 2007, 2008, 2009 Jean-Fran�ois DEL NERO
//
// This file is part of HxCFloppyEmulator.
//
// HxCFloppyEmulator may be used and distributed without restriction provided
// that this copyright statement is not removed from the file and that any
// derivative work contains the original copyright notice and the associated
// disclaimer.
//
// HxCFloppyEmulator is free software; you can redistribute it
// and/or modify  it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// HxCFloppyEmulator is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
//   See the GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with HxCFloppyEmulator; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
//
*/
#define IBMPC_DD_FLOPPYMODE				0x00
#define IBMPC_HD_FLOPPYMODE				0x01
#define ATARIST_DD_FLOPPYMODE			0x02
#define ATARIST_HD_FLOPPYMODE			0x03
#define AMIGA_DD_FLOPPYMODE				0x04
#define AMIGA_HD_FLOPPYMODE				0x05
#define CPC_DD_FLOPPYMODE				0x06
#define GENERIC_SHUGGART_DD_FLOPPYMODE	0x07
#define IBMPC_ED_FLOPPYMODE				0x08
#define MSX2_DD_FLOPPYMODE				0x09
#define C64_DD_FLOPPYMODE				0x0A
#define CALLINGMETHOD

#define VARIABLEBITRATE					-1

typedef struct SIDE_
{
	unsigned int	number_of_sector;	/*/ nombre de secteurs sur la piste (informatif/optionnel) -> -1 si inconnu.*/
	unsigned char * databuffer;			/*/ buffer data*/
	long			bitrate;			/* si == a VARIABLEBITRATE utiliser timingbuffer*/
	unsigned long * timingbuffer;		/* buffer bitrate de la piste.*/
	unsigned char * flakybitsbuffer;    /* si = 0 pas de flakey/weak bits.*/
	unsigned char * indexbuffer;		/*buffer signal index 1->activ� 0->d�sactiv�*/
	unsigned long	tracklen;			/* longueur de  databuffer/timingbuffer/flakybitsbuffer/indexbuffer (nombre d'elements)*/
}SIDE;

typedef struct CYLINDER_
{
	unsigned int	floppyRPM;			/*/ rotation par minute (informatif/optionnel)*/
	unsigned int	number_of_side;
	SIDE	**		sides;
}CYLINDER;

typedef struct FLOPPY_
{
	unsigned int	floppyBitRate;
	
	unsigned int	floppyNumberOfSide;
	unsigned int	floppyNumberOfTrack;
	unsigned int	floppySectorPerTrack;
	
	unsigned int	floppyiftype;
	
	CYLINDER	**	tracks;
}FLOPPY;


