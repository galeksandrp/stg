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
 *    Author : Maxim Mamontov <faust@stargazer.dp.ua>
 */

#ifndef __STG_SGCONF_ACTIONS_H__
#define __STG_SGCONF_ACTIONS_H__

#include "action.h"
#include "options.h"
#include "parser_state.h"

#include "stg/common.h"
#include "stg/resetable.h"

#include <string>

namespace SGCONF
{

typedef void (* FUNC0)();

class FUNC0_ACTION : public ACTION
{
    public:
        FUNC0_ACTION(FUNC0 func) : m_func(func) {}

        virtual std::string ParamDescription() const { return ""; }
        virtual std::string DefaultDescription() const { return ""; }
        virtual OPTION_BLOCK & Suboptions() { return m_suboptions; }
        virtual PARSER_STATE Parse(int argc, char ** argv);

    private:
        FUNC0 m_func;
        OPTION_BLOCK m_suboptions;
};

inline
FUNC0_ACTION * MakeFunc0Action(FUNC0 func)
{
return new FUNC0_ACTION(func);
}

template <typename T>
class PARAM_ACTION: public ACTION
{
    public:
        PARAM_ACTION(RESETABLE<T> & param,
                     const T & defaultValue,
                     const std::string & paramDescription)
            : m_param(param),
              m_defaltValue(defaultValue),
              m_description(paramDescription),
              m_hasDefault(true)
        {}
        PARAM_ACTION(RESETABLE<T> & param,
                     const std::string & paramDescription)
            : m_param(param),
              m_description(paramDescription),
              m_hasDefault(false)
        {}

        virtual std::string ParamDescription() const { return m_description; }
        virtual std::string DefaultDescription() const;
        virtual OPTION_BLOCK & Suboptions() { return m_suboptions; }
        virtual PARSER_STATE Parse(int argc, char ** argv);

    private:
        RESETABLE<T> & m_param;
        T m_defaltValue;
        std::string m_description;
        bool m_hasDefault;
        OPTION_BLOCK m_suboptions;
};

template <typename T>
inline
std::string PARAM_ACTION<T>::DefaultDescription() const
{
return m_hasDefault ? " (default: '" + x2str(m_defaltValue) + "')"
                    : "";
}

template <>
inline
std::string PARAM_ACTION<std::string>::DefaultDescription() const
{
return m_hasDefault ? " (default: '" + m_defaltValue + "')"
                    : "";
}

template <typename T>
inline
PARSER_STATE PARAM_ACTION<T>::Parse(int argc, char ** argv)
{
T value;
if (str2x(*argv, value))
    throw ERROR(std::string("Bad argument: '") + *argv + "'");
m_param = value;
return PARSER_STATE(false, --argc, ++argv);
}

template <>
inline
PARSER_STATE PARAM_ACTION<std::string>::Parse(int argc, char ** argv)
{
m_param = *argv;
return PARSER_STATE(false, --argc, ++argv);
}

template <typename T>
inline
PARAM_ACTION<T> * MakeParamAction(RESETABLE<T> & param,
                                  const T & defaultValue,
                                  const std::string & paramDescription)
{
return new PARAM_ACTION<T>(param, defaultValue, paramDescription);
}

template <typename T>
inline
PARAM_ACTION<T> * MakeParamAction(RESETABLE<T> & param,
                                  const std::string & paramDescription)
{
return new PARAM_ACTION<T>(param, paramDescription);
}

} // namespace SGCONF

#endif
