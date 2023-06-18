#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_StringBuf
#include <StringBuf.h>
#endif
#ifndef INCLUDED_StringTools
#include <StringTools.h>
#endif

HX_LOCAL_STACK_FRAME(_hx_pos_0e615b5827179e15_50_urlEncode,"StringTools","urlEncode",0x06afdce1,"StringTools.urlEncode","/usr/local/lib/haxe/std/StringTools.hx",50,0x3f930611)
HX_LOCAL_STACK_FRAME(_hx_pos_0e615b5827179e15_118_urlDecode,"StringTools","urlDecode",0x71b947f9,"StringTools.urlDecode","/usr/local/lib/haxe/std/StringTools.hx",118,0x3f930611)
HX_LOCAL_STACK_FRAME(_hx_pos_0e615b5827179e15_238_startsWith,"StringTools","startsWith",0x5f4e6efb,"StringTools.startsWith","/usr/local/lib/haxe/std/StringTools.hx",238,0x3f930611)
HX_LOCAL_STACK_FRAME(_hx_pos_0e615b5827179e15_249_endsWith,"StringTools","endsWith",0x0eb5bfe2,"StringTools.endsWith","/usr/local/lib/haxe/std/StringTools.hx",249,0x3f930611)
HX_LOCAL_STACK_FRAME(_hx_pos_0e615b5827179e15_278_isSpace,"StringTools","isSpace",0xe0290778,"StringTools.isSpace","/usr/local/lib/haxe/std/StringTools.hx",278,0x3f930611)
HX_LOCAL_STACK_FRAME(_hx_pos_0e615b5827179e15_296_ltrim,"StringTools","ltrim",0x24d2234a,"StringTools.ltrim","/usr/local/lib/haxe/std/StringTools.hx",296,0x3f930611)
HX_LOCAL_STACK_FRAME(_hx_pos_0e615b5827179e15_321_rtrim,"StringTools","rtrim",0x99399e50,"StringTools.rtrim","/usr/local/lib/haxe/std/StringTools.hx",321,0x3f930611)
HX_LOCAL_STACK_FRAME(_hx_pos_0e615b5827179e15_349_trim,"StringTools","trim",0x2908d066,"StringTools.trim","/usr/local/lib/haxe/std/StringTools.hx",349,0x3f930611)
HX_LOCAL_STACK_FRAME(_hx_pos_0e615b5827179e15_365_lpad,"StringTools","lpad",0x23bd8feb,"StringTools.lpad","/usr/local/lib/haxe/std/StringTools.hx",365,0x3f930611)
HX_LOCAL_STACK_FRAME(_hx_pos_0e615b5827179e15_424_replace,"StringTools","replace",0x6d651f30,"StringTools.replace","/usr/local/lib/haxe/std/StringTools.hx",424,0x3f930611)

void StringTools_obj::__construct() { }

Dynamic StringTools_obj::__CreateEmpty() { return new StringTools_obj; }

void *StringTools_obj::_hx_vtable = 0;

Dynamic StringTools_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< StringTools_obj > _hx_result = new StringTools_obj();
	_hx_result->__construct();
	return _hx_result;
}

bool StringTools_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x084f186e;
}

::String StringTools_obj::urlEncode(::String s){
            	HX_STACKFRAME(&_hx_pos_0e615b5827179e15_50_urlEncode)
HXDLIN(  50)		return ( (::String)(s.__URLEncode()) );
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(StringTools_obj,urlEncode,return )

::String StringTools_obj::urlDecode(::String s){
            	HX_STACKFRAME(&_hx_pos_0e615b5827179e15_118_urlDecode)
HXDLIN( 118)		return ( (::String)(s.__URLDecode()) );
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(StringTools_obj,urlDecode,return )

bool StringTools_obj::startsWith(::String s,::String start){
            	HX_STACKFRAME(&_hx_pos_0e615b5827179e15_238_startsWith)
HXDLIN( 238)		if ((s.length >= start.length)) {
HXDLIN( 238)			return (s.lastIndexOf(start,0) == 0);
            		}
            		else {
HXDLIN( 238)			return false;
            		}
HXDLIN( 238)		return false;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(StringTools_obj,startsWith,return )

bool StringTools_obj::endsWith(::String s,::String end){
            	HX_STACKFRAME(&_hx_pos_0e615b5827179e15_249_endsWith)
HXLINE( 263)		int elen = end.length;
HXLINE( 264)		int slen = s.length;
HXLINE( 265)		if ((slen >= elen)) {
HXLINE( 265)			return (s.indexOf(end,(slen - elen)) == (slen - elen));
            		}
            		else {
HXLINE( 265)			return false;
            		}
HXDLIN( 265)		return false;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(StringTools_obj,endsWith,return )

bool StringTools_obj::isSpace(::String s,int pos){
            	HX_STACKFRAME(&_hx_pos_0e615b5827179e15_278_isSpace)
HXLINE( 283)		 ::Dynamic c = s.charCodeAt(pos);
HXLINE( 284)		bool _hx_tmp;
HXDLIN( 284)		if (::hx::IsGreater( c,8 )) {
HXLINE( 284)			_hx_tmp = ::hx::IsLess( c,14 );
            		}
            		else {
HXLINE( 284)			_hx_tmp = false;
            		}
HXDLIN( 284)		if (!(_hx_tmp)) {
HXLINE( 284)			return ::hx::IsEq( c,32 );
            		}
            		else {
HXLINE( 284)			return true;
            		}
HXDLIN( 284)		return false;
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(StringTools_obj,isSpace,return )

::String StringTools_obj::ltrim(::String s){
            	HX_STACKFRAME(&_hx_pos_0e615b5827179e15_296_ltrim)
HXLINE( 300)		int l = s.length;
HXLINE( 301)		int r = 0;
HXLINE( 302)		while(true){
HXLINE( 302)			bool _hx_tmp;
HXDLIN( 302)			if ((r < l)) {
HXLINE( 302)				_hx_tmp = ::StringTools_obj::isSpace(s,r);
            			}
            			else {
HXLINE( 302)				_hx_tmp = false;
            			}
HXDLIN( 302)			if (!(_hx_tmp)) {
HXLINE( 302)				goto _hx_goto_5;
            			}
HXLINE( 303)			r = (r + 1);
            		}
            		_hx_goto_5:;
HXLINE( 305)		if ((r > 0)) {
HXLINE( 306)			return s.substr(r,(l - r));
            		}
            		else {
HXLINE( 308)			return s;
            		}
HXLINE( 305)		return null();
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(StringTools_obj,ltrim,return )

::String StringTools_obj::rtrim(::String s){
            	HX_STACKFRAME(&_hx_pos_0e615b5827179e15_321_rtrim)
HXLINE( 325)		int l = s.length;
HXLINE( 326)		int r = 0;
HXLINE( 327)		while(true){
HXLINE( 327)			bool _hx_tmp;
HXDLIN( 327)			if ((r < l)) {
HXLINE( 327)				_hx_tmp = ::StringTools_obj::isSpace(s,((l - r) - 1));
            			}
            			else {
HXLINE( 327)				_hx_tmp = false;
            			}
HXDLIN( 327)			if (!(_hx_tmp)) {
HXLINE( 327)				goto _hx_goto_7;
            			}
HXLINE( 328)			r = (r + 1);
            		}
            		_hx_goto_7:;
HXLINE( 330)		if ((r > 0)) {
HXLINE( 331)			return s.substr(0,(l - r));
            		}
            		else {
HXLINE( 333)			return s;
            		}
HXLINE( 330)		return null();
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(StringTools_obj,rtrim,return )

::String StringTools_obj::trim(::String s){
            	HX_STACKFRAME(&_hx_pos_0e615b5827179e15_349_trim)
HXDLIN( 349)		return ::StringTools_obj::ltrim(::StringTools_obj::rtrim(s));
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(StringTools_obj,trim,return )

::String StringTools_obj::lpad(::String s,::String c,int l){
            	HX_GC_STACKFRAME(&_hx_pos_0e615b5827179e15_365_lpad)
HXLINE( 366)		if ((c.length <= 0)) {
HXLINE( 367)			return s;
            		}
HXLINE( 369)		 ::StringBuf buf =  ::StringBuf_obj::__alloc( HX_CTX );
HXLINE( 370)		l = (l - s.length);
HXLINE( 371)		while((buf->get_length() < l)){
HXLINE( 372)			if (::hx::IsNotNull( buf->charBuf )) {
HXLINE( 372)				buf->flush();
            			}
HXDLIN( 372)			if (::hx::IsNull( buf->b )) {
HXLINE( 372)				buf->b = ::Array_obj< ::String >::__new(1)->init(0,::Std_obj::string(c));
            			}
            			else {
HXLINE( 372)				::Array< ::String > buf1 = buf->b;
HXDLIN( 372)				buf1->push(::Std_obj::string(c));
            			}
            		}
HXLINE( 374)		{
HXLINE( 374)			if (::hx::IsNotNull( buf->charBuf )) {
HXLINE( 374)				buf->flush();
            			}
HXDLIN( 374)			if (::hx::IsNull( buf->b )) {
HXLINE( 374)				buf->b = ::Array_obj< ::String >::__new(1)->init(0,::Std_obj::string(s));
            			}
            			else {
HXLINE( 374)				::Array< ::String > buf1 = buf->b;
HXDLIN( 374)				buf1->push(::Std_obj::string(s));
            			}
            		}
HXLINE( 375)		return buf->toString();
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(StringTools_obj,lpad,return )

::String StringTools_obj::replace(::String s,::String sub,::String by){
            	HX_STACKFRAME(&_hx_pos_0e615b5827179e15_424_replace)
HXDLIN( 424)		return s.split(sub)->join(by);
            	}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(StringTools_obj,replace,return )


StringTools_obj::StringTools_obj()
{
}

bool StringTools_obj::__GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"trim") ) { outValue = trim_dyn(); return true; }
		if (HX_FIELD_EQ(inName,"lpad") ) { outValue = lpad_dyn(); return true; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"ltrim") ) { outValue = ltrim_dyn(); return true; }
		if (HX_FIELD_EQ(inName,"rtrim") ) { outValue = rtrim_dyn(); return true; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"isSpace") ) { outValue = isSpace_dyn(); return true; }
		if (HX_FIELD_EQ(inName,"replace") ) { outValue = replace_dyn(); return true; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"endsWith") ) { outValue = endsWith_dyn(); return true; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"urlEncode") ) { outValue = urlEncode_dyn(); return true; }
		if (HX_FIELD_EQ(inName,"urlDecode") ) { outValue = urlDecode_dyn(); return true; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"startsWith") ) { outValue = startsWith_dyn(); return true; }
	}
	return false;
}

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo *StringTools_obj_sMemberStorageInfo = 0;
static ::hx::StaticInfo *StringTools_obj_sStaticStorageInfo = 0;
#endif

::hx::Class StringTools_obj::__mClass;

static ::String StringTools_obj_sStaticFields[] = {
	HX_("urlEncode",e5,4e,52,9a),
	HX_("urlDecode",fd,b9,5b,05),
	HX_("startsWith",77,c0,cf,f9),
	HX_("endsWith",5e,7a,b6,db),
	HX_("isSpace",7c,30,ec,1d),
	HX_("ltrim",4e,43,4a,7c),
	HX_("rtrim",54,be,b1,f0),
	HX_("trim",e2,9c,03,4d),
	HX_("lpad",67,5c,b8,47),
	HX_("replace",34,48,28,ab),
	::String(null())
};

void StringTools_obj::__register()
{
	StringTools_obj _hx_dummy;
	StringTools_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("StringTools",6a,db,63,03);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &StringTools_obj::__GetStatic;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(StringTools_obj_sStaticFields);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(0 /* sMemberFields */);
	__mClass->mCanCast = ::hx::TCanCast< StringTools_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = StringTools_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = StringTools_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

