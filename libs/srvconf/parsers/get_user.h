/*
 *    This program is free software; you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation; either version 2 of the License, or
 *    (at your option) any later version.
 *
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with this program; if not, write to the Free Software
 *    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

/*
 *    Author : Boris Mikhailenko <stg34@stargazer.dp.ua>
 *    Author : Maxim Mamontov <faust@stargazer.dp.ua>
 */

#pragma once

#include "base.h"
#include "property.h"

#include "stg/servconf_types.h"

#include <string>

namespace STG
{
namespace GetUser
{

class Parser: public STG::Parser
{
public:
    using Info = GetUser::Info;

    Parser(Callback f, void* data, const std::string& encoding);

    ~Parser() override;
    int  ParseStart(const char* el, const char** attr) override;
    void ParseEnd(const char* el) override;
    void Failure(const std::string& reason) override { callback(false, reason, info, data); }

private:
    PropertyParsers propertyParsers;
    Callback callback;
    void* data;
    std::string encoding;
    Info info;
    int depth;
    bool parsingAnswer;
    std::string error;

    void ParseUser(const char* el, const char** attr);
    void ParseUserParams(const char* el, const char** attr);
    void ParseAuthBy(const char* el, const char** attr);
    void ParseServices(const char* el, const char** attr);
};

} // namespace GetUser
} // namespace STG
