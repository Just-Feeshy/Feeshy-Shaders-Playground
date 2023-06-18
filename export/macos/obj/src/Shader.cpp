#include <hxcpp.h>

#ifndef INCLUDED_Shader
#include <Shader.h>
#endif
#ifndef INCLUDED_StringTools
#include <StringTools.h>
#endif
#ifndef INCLUDED_haxe_Exception
#include <haxe/Exception.h>
#endif
#ifndef INCLUDED_lime__internal_backend_native_NativeOpenGLRenderContext
#include <lime/_internal/backend/native/NativeOpenGLRenderContext.h>
#endif
#ifndef INCLUDED_lime_graphics_RenderContext
#include <lime/graphics/RenderContext.h>
#endif
#ifndef INCLUDED_lime_graphics_opengl_GLObject
#include <lime/graphics/opengl/GLObject.h>
#endif
#ifndef INCLUDED_lime_system_System
#include <lime/system/System.h>
#endif
#ifndef INCLUDED_lime_ui_Window
#include <lime/ui/Window.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_8838e3a9be506a5f_18_new,"Shader","new",0x192c5ab7,"Shader.new","Shader.hx",18,0xd10ba899)
HX_LOCAL_STACK_FRAME(_hx_pos_8838e3a9be506a5f_45_bind,"Shader","bind",0xe5b77786,"Shader.bind","Shader.hx",45,0xd10ba899)
HX_LOCAL_STACK_FRAME(_hx_pos_8838e3a9be506a5f_52_includeFragmentShader,"Shader","includeFragmentShader",0x5baf4374,"Shader.includeFragmentShader","Shader.hx",52,0xd10ba899)
HX_LOCAL_STACK_FRAME(_hx_pos_8838e3a9be506a5f_57_includeVertexShader,"Shader","includeVertexShader",0x0bc08048,"Shader.includeVertexShader","Shader.hx",57,0xd10ba899)
HX_LOCAL_STACK_FRAME(_hx_pos_8838e3a9be506a5f_62_compile,"Shader","compile",0x4c31274a,"Shader.compile","Shader.hx",62,0xd10ba899)
HX_LOCAL_STACK_FRAME(_hx_pos_8838e3a9be506a5f_77_createShader,"Shader","createShader",0xc98af20a,"Shader.createShader","Shader.hx",77,0xd10ba899)
HX_LOCAL_STACK_FRAME(_hx_pos_8838e3a9be506a5f_33_boot,"Shader","boot",0xe5bc05fb,"Shader.boot","Shader.hx",33,0xd10ba899)

void Shader_obj::__construct( ::lime::ui::Window window, ::lime::graphics::RenderContext context,::String vertex,::String fragment){
            	HX_STACKFRAME(&_hx_pos_8838e3a9be506a5f_18_new)
HXLINE(  22)		this->vertexSource = HX_("",00,00,00,00);
HXLINE(  21)		this->fragmentSource = HX_("",00,00,00,00);
HXLINE(  37)		this->window = window;
HXLINE(  39)		this->gl = context->webgl;
HXLINE(  41)		this->fragmentSource = fragment;
HXLINE(  42)		this->vertexSource = vertex;
            	}

Dynamic Shader_obj::__CreateEmpty() { return new Shader_obj; }

void *Shader_obj::_hx_vtable = 0;

Dynamic Shader_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< Shader_obj > _hx_result = new Shader_obj();
	_hx_result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return _hx_result;
}

bool Shader_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x194cfa69;
}

void Shader_obj::bind(){
            	HX_STACKFRAME(&_hx_pos_8838e3a9be506a5f_45_bind)
HXLINE(  46)		this->gl->uniform2f(this->resolutionLocation,( (Float)(this->window->_hx___width) ),( (Float)(this->window->_hx___height) ));
HXLINE(  47)		{
HXLINE(  47)			 ::lime::_internal::backend::native::NativeOpenGLRenderContext this1 = this->gl;
HXDLIN(  47)			int location = this->timeLocation;
HXDLIN(  47)			this1->uniform1f(location,(( (Float)(::lime::_hx_system::System_obj::getTimer()) ) * ((Float)0.001)));
            		}
HXLINE(  48)		this->gl->enableVertexAttribArray(this->glVertexAttribute);
HXLINE(  49)		this->gl->useProgram(this->glProgram);
            	}


HX_DEFINE_DYNAMIC_FUNC0(Shader_obj,bind,(void))

void Shader_obj::includeFragmentShader(::String source){
            	HX_STACKFRAME(&_hx_pos_8838e3a9be506a5f_52_includeFragmentShader)
HXLINE(  53)		this->fragmentSource = ((source + HX_("\n\n",c0,08,00,00)) + this->fragmentSource);
HXLINE(  54)		::StringTools_obj::trim(this->fragmentSource);
            	}


HX_DEFINE_DYNAMIC_FUNC1(Shader_obj,includeFragmentShader,(void))

void Shader_obj::includeVertexShader(::String source){
            	HX_STACKFRAME(&_hx_pos_8838e3a9be506a5f_57_includeVertexShader)
HXLINE(  58)		this->vertexSource = ((source + HX_("\n\n",c0,08,00,00)) + this->vertexSource);
HXLINE(  59)		::StringTools_obj::trim(this->vertexSource);
            	}


HX_DEFINE_DYNAMIC_FUNC1(Shader_obj,includeVertexShader,(void))

void Shader_obj::compile(){
            	HX_STACKFRAME(&_hx_pos_8838e3a9be506a5f_62_compile)
HXLINE(  63)		 ::lime::graphics::opengl::GLObject vertexShader = this->createShader(this->gl,this->gl->VERTEX_SHADER,this->vertexSource);
HXLINE(  64)		 ::lime::graphics::opengl::GLObject fragmentShader = this->createShader(this->gl,this->gl->FRAGMENT_SHADER,this->fragmentSource);
HXLINE(  66)		this->glProgram = this->gl->createProgram();
HXLINE(  67)		this->gl->attachShader(this->glProgram,vertexShader);
HXLINE(  68)		this->gl->attachShader(this->glProgram,fragmentShader);
HXLINE(  69)		this->gl->linkProgram(this->glProgram);
HXLINE(  71)		this->resolutionLocation = this->gl->getUniformLocation(this->glProgram,HX_("iResolution",f5,36,34,3f));
HXLINE(  72)		this->timeLocation = this->gl->getUniformLocation(this->glProgram,HX_("iTime",16,e1,e8,ac));
HXLINE(  74)		this->glVertexAttribute = this->gl->getAttribLocation(this->glProgram,HX_("a_position",87,03,c8,ee));
            	}


HX_DEFINE_DYNAMIC_FUNC0(Shader_obj,compile,(void))

 ::lime::graphics::opengl::GLObject Shader_obj::createShader( ::lime::_internal::backend::native::NativeOpenGLRenderContext gl,int type,::String source){
            	HX_STACKFRAME(&_hx_pos_8838e3a9be506a5f_77_createShader)
HXLINE(  78)		 ::lime::graphics::opengl::GLObject shader = gl->createShader(type);
HXLINE(  79)		gl->shaderSource(shader,source);
HXLINE(  80)		gl->compileShader(shader);
HXLINE(  82)		if (!(( (bool)(gl->getShaderParameter(shader,gl->COMPILE_STATUS)) ))) {
HXLINE(  83)			HX_STACK_DO_THROW(::haxe::Exception_obj::thrown((HX_("An error occurred compiling the shaders: ",85,e1,ab,51) + gl->getShaderInfoLog(shader))));
            		}
HXLINE(  86)		return shader;
            	}


HX_DEFINE_DYNAMIC_FUNC3(Shader_obj,createShader,return )

::String Shader_obj::webFragment;


::hx::ObjectPtr< Shader_obj > Shader_obj::__new( ::lime::ui::Window window, ::lime::graphics::RenderContext context,::String vertex,::String fragment) {
	::hx::ObjectPtr< Shader_obj > __this = new Shader_obj();
	__this->__construct(window,context,vertex,fragment);
	return __this;
}

::hx::ObjectPtr< Shader_obj > Shader_obj::__alloc(::hx::Ctx *_hx_ctx, ::lime::ui::Window window, ::lime::graphics::RenderContext context,::String vertex,::String fragment) {
	Shader_obj *__this = (Shader_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(Shader_obj), true, "Shader"));
	*(void **)__this = Shader_obj::_hx_vtable;
	__this->__construct(window,context,vertex,fragment);
	return __this;
}

Shader_obj::Shader_obj()
{
}

void Shader_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Shader);
	HX_MARK_MEMBER_NAME(glVertexAttribute,"glVertexAttribute");
	HX_MARK_MEMBER_NAME(fragmentSource,"fragmentSource");
	HX_MARK_MEMBER_NAME(vertexSource,"vertexSource");
	HX_MARK_MEMBER_NAME(window,"window");
	HX_MARK_MEMBER_NAME(glProgram,"glProgram");
	HX_MARK_MEMBER_NAME(gl,"gl");
	HX_MARK_MEMBER_NAME(resolutionLocation,"resolutionLocation");
	HX_MARK_MEMBER_NAME(timeLocation,"timeLocation");
	HX_MARK_END_CLASS();
}

void Shader_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(glVertexAttribute,"glVertexAttribute");
	HX_VISIT_MEMBER_NAME(fragmentSource,"fragmentSource");
	HX_VISIT_MEMBER_NAME(vertexSource,"vertexSource");
	HX_VISIT_MEMBER_NAME(window,"window");
	HX_VISIT_MEMBER_NAME(glProgram,"glProgram");
	HX_VISIT_MEMBER_NAME(gl,"gl");
	HX_VISIT_MEMBER_NAME(resolutionLocation,"resolutionLocation");
	HX_VISIT_MEMBER_NAME(timeLocation,"timeLocation");
}

::hx::Val Shader_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"gl") ) { return ::hx::Val( gl ); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"bind") ) { return ::hx::Val( bind_dyn() ); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"window") ) { return ::hx::Val( window ); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"compile") ) { return ::hx::Val( compile_dyn() ); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"glProgram") ) { return ::hx::Val( glProgram ); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"vertexSource") ) { return ::hx::Val( vertexSource ); }
		if (HX_FIELD_EQ(inName,"timeLocation") ) { return ::hx::Val( timeLocation ); }
		if (HX_FIELD_EQ(inName,"createShader") ) { return ::hx::Val( createShader_dyn() ); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"fragmentSource") ) { return ::hx::Val( fragmentSource ); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"glVertexAttribute") ) { return ::hx::Val( glVertexAttribute ); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"resolutionLocation") ) { return ::hx::Val( resolutionLocation ); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"includeVertexShader") ) { return ::hx::Val( includeVertexShader_dyn() ); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"includeFragmentShader") ) { return ::hx::Val( includeFragmentShader_dyn() ); }
	}
	return super::__Field(inName,inCallProp);
}

bool Shader_obj::__GetStatic(const ::String &inName, Dynamic &outValue, ::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 11:
		if (HX_FIELD_EQ(inName,"webFragment") ) { outValue = ( webFragment ); return true; }
	}
	return false;
}

::hx::Val Shader_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"gl") ) { gl=inValue.Cast<  ::lime::_internal::backend::native::NativeOpenGLRenderContext >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"window") ) { window=inValue.Cast<  ::lime::ui::Window >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"glProgram") ) { glProgram=inValue.Cast<  ::lime::graphics::opengl::GLObject >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"vertexSource") ) { vertexSource=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"timeLocation") ) { timeLocation=inValue.Cast< int >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"fragmentSource") ) { fragmentSource=inValue.Cast< ::String >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"glVertexAttribute") ) { glVertexAttribute=inValue.Cast< int >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"resolutionLocation") ) { resolutionLocation=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

bool Shader_obj::__SetStatic(const ::String &inName,Dynamic &ioValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 11:
		if (HX_FIELD_EQ(inName,"webFragment") ) { webFragment=ioValue.Cast< ::String >(); return true; }
	}
	return false;
}

void Shader_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("glVertexAttribute",73,c7,35,05));
	outFields->push(HX_("fragmentSource",cb,40,ed,4e));
	outFields->push(HX_("vertexSource",5f,a3,46,d2));
	outFields->push(HX_("window",f0,93,8c,52));
	outFields->push(HX_("glProgram",df,d6,b3,c1));
	outFields->push(HX_("gl",25,5a,00,00));
	outFields->push(HX_("resolutionLocation",81,6b,7c,59));
	outFields->push(HX_("timeLocation",62,4b,e3,7d));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo Shader_obj_sMemberStorageInfo[] = {
	{::hx::fsInt,(int)offsetof(Shader_obj,glVertexAttribute),HX_("glVertexAttribute",73,c7,35,05)},
	{::hx::fsString,(int)offsetof(Shader_obj,fragmentSource),HX_("fragmentSource",cb,40,ed,4e)},
	{::hx::fsString,(int)offsetof(Shader_obj,vertexSource),HX_("vertexSource",5f,a3,46,d2)},
	{::hx::fsObject /*  ::lime::ui::Window */ ,(int)offsetof(Shader_obj,window),HX_("window",f0,93,8c,52)},
	{::hx::fsObject /*  ::lime::graphics::opengl::GLObject */ ,(int)offsetof(Shader_obj,glProgram),HX_("glProgram",df,d6,b3,c1)},
	{::hx::fsObject /*  ::lime::_internal::backend::native::NativeOpenGLRenderContext */ ,(int)offsetof(Shader_obj,gl),HX_("gl",25,5a,00,00)},
	{::hx::fsInt,(int)offsetof(Shader_obj,resolutionLocation),HX_("resolutionLocation",81,6b,7c,59)},
	{::hx::fsInt,(int)offsetof(Shader_obj,timeLocation),HX_("timeLocation",62,4b,e3,7d)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo Shader_obj_sStaticStorageInfo[] = {
	{::hx::fsString,(void *) &Shader_obj::webFragment,HX_("webFragment",84,74,c6,0c)},
	{ ::hx::fsUnknown, 0, null()}
};
#endif

static ::String Shader_obj_sMemberFields[] = {
	HX_("glVertexAttribute",73,c7,35,05),
	HX_("fragmentSource",cb,40,ed,4e),
	HX_("vertexSource",5f,a3,46,d2),
	HX_("window",f0,93,8c,52),
	HX_("glProgram",df,d6,b3,c1),
	HX_("gl",25,5a,00,00),
	HX_("resolutionLocation",81,6b,7c,59),
	HX_("timeLocation",62,4b,e3,7d),
	HX_("bind",bd,f5,16,41),
	HX_("includeFragmentShader",5d,57,7a,68),
	HX_("includeVertexShader",f1,97,d7,d2),
	HX_("compile",73,25,6f,83),
	HX_("createShader",41,ff,75,3f),
	::String(null()) };

static void Shader_obj_sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Shader_obj::webFragment,"webFragment");
};

#ifdef HXCPP_VISIT_ALLOCS
static void Shader_obj_sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Shader_obj::webFragment,"webFragment");
};

#endif

::hx::Class Shader_obj::__mClass;

static ::String Shader_obj_sStaticFields[] = {
	HX_("webFragment",84,74,c6,0c),
	::String(null())
};

void Shader_obj::__register()
{
	Shader_obj _hx_dummy;
	Shader_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("Shader",45,33,b5,51);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &Shader_obj::__GetStatic;
	__mClass->mSetStaticField = &Shader_obj::__SetStatic;
	__mClass->mMarkFunc = Shader_obj_sMarkStatics;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(Shader_obj_sStaticFields);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(Shader_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< Shader_obj >;
#ifdef HXCPP_VISIT_ALLOCS
	__mClass->mVisitFunc = Shader_obj_sVisitStatics;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = Shader_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = Shader_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

void Shader_obj::__boot()
{
{
            	HX_STACKFRAME(&_hx_pos_8838e3a9be506a5f_33_boot)
HXDLIN(  33)		webFragment = HX_("",00,00,00,00);
            	}
}

