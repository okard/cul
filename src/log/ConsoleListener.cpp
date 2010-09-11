/*
    Tower Defense Game
    Copyright (C) 2010  okard

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

*/

#include "ConsoleListener.hpp"

using namespace cul;
using namespace log;

#include <iostream>

/**
* Constructor
*/
ConsoleListener::~ConsoleListener()
{
}

/**
* Log event to console
*/
void ConsoleListener::logEvent(const LogSource* src, const LogEvent* event)
{
    LogEvent* ev = const_cast<LogEvent*>(event);
    if(ev->GetType() >= LogType::Error)
        std::cerr << ev->GetStream().str() << std::endl;
    else
        std::cout << LogType::toString(ev->GetType()) << ": " << ev->GetStream().str() << std::endl;
}