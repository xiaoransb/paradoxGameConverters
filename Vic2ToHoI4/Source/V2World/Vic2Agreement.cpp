/*Copyright (c) 2017 The Paradox Game Converters Project

Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be included
in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.*/



#include "Vic2Agreement.h"
#include "Log.h"



V2Agreement::V2Agreement(shared_ptr<Object> obj):
	type(obj->getKey()),
	country1(""),
	country2(""),
	start_date()
{
	auto objFirst = obj->safeGetObject("first");
	if (objFirst != nullptr)
	{
		country1 = objFirst->getLeaf();
	}
	else
	{
		LOG(LogLevel::Warning) << "Diplomatic agreement (" << type << ") has no first party";
	}

	auto objSecond = obj->safeGetObject("second");
	if (objSecond != nullptr)
	{
		country2 = objSecond->getLeaf();
	}
	else
	{
		LOG(LogLevel::Warning) << "Diplomatic agreement (" << type << ") has no second party";
	}

	start_date = date(obj->safeGetString("start_date"));
}