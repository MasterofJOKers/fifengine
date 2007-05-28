/***************************************************************************
 *   Copyright (C) 2005-2007 by the FIFE Team                              *
 *   fife-public@lists.sourceforge.net                                     *
 *   This file is part of FIFE.                                            *
 *                                                                         *
 *   FIFE is free software; you can redistribute it and/or modify          *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA              *
 ***************************************************************************/

#ifndef FIFE_SCRIPT_LUA_GUI_LUA_GUI_ACTIONLISTENER
#define FIFE_SCRIPT_LUA_GUI_LUA_GUI_ACTIONLISTENER

// Standard C++ library includes
#include <string>

// 3rd party library includes
#include "script/lua.hpp"
#include <guichan.hpp>

// FIFE includes
// These includes are split up in two parts, separated by one empty line
// First block: files included from the FIFE root src directory
// Second block: files included from the same folder
#include "util/singleton.h"
#include "eventchannel/widget/ec_iwidgetlistener.h"
#include "eventchannel/source/ec_eventsourcetypes.h"
#include "eventchannel/source/ec_ieventsource.h"


namespace FIFE {

	class ActionListener_Lua : 
		public gcn::ActionListener,
		public DynamicSingleton<ActionListener_Lua>,
		public IEventSource
	{
		public:
			ActionListener_Lua(IWidgetListener& wl);
			~ActionListener_Lua();
			void action(const gcn::ActionEvent & event);
			void setup(lua_State *L, const std::string &global, const std::string &table);
			EventSourceType getEventSourceType();
		private:
			void luaAction(const std::string &action);
			std::string m_global;
			std::string m_table;
			lua_State *m_L;
			bool isReady;
			IWidgetListener& m_widgetlistener;
	};
}

#endif
/* vim: set noexpandtab: set shiftwidth=2: set tabstop=2: */
