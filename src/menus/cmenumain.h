/**
 *  @section LICENSE
 *
 *  openPirates
 *  Copyright (C) 2010 Scott Smith
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef CMENUMAIN_H
#define CMENUMAIN_H

#include "global.h"
#include "managers/cmanagerwindow.h"

/**
 * @section DESCRIPTION
 * The menu for the in-game main menu window dialogs
 */

class CMenumain
{
    public:
        /** Constructor. */
        CMenumain( CResources& resources, CManagerWindow& winmanager );
        /** Destructor. */
		virtual ~CMenumain();

        int8_t Run( void );

    private:
        CResources&         mResources;
        CGraphic&           mScreen;
        CRole&              mPlayer;
        CManager<CString>&  mStrings;
        CManager<CGraphic>& mGraphics;
        CManagerWindow&     mManagerwindow;

		int8_t EndGame( void );
		int8_t SaveCareer( void );
		int8_t LoadCareer( void );
};

#endif // CMENUMAIN_H
