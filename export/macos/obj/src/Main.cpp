#include <hxcpp.h>

#ifndef INCLUDED_Canvas
#include <Canvas.h>
#endif
#ifndef INCLUDED_Main
#include <Main.h>
#endif
#ifndef INCLUDED_Shader
#include <Shader.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_lime__internal_backend_native_NativeOpenGLRenderContext
#include <lime/_internal/backend/native/NativeOpenGLRenderContext.h>
#endif
#ifndef INCLUDED_lime_app_Application
#include <lime/app/Application.h>
#endif
#ifndef INCLUDED_lime_app_IModule
#include <lime/app/IModule.h>
#endif
#ifndef INCLUDED_lime_app_Module
#include <lime/app/Module.h>
#endif
#ifndef INCLUDED_lime_app__Event_lime_ui_Window_Void
#include <lime/app/_Event_lime_ui_Window_Void.h>
#endif
#ifndef INCLUDED_lime_graphics_RenderContext
#include <lime/graphics/RenderContext.h>
#endif
#ifndef INCLUDED_lime_graphics_opengl_GLObject
#include <lime/graphics/opengl/GLObject.h>
#endif
#ifndef INCLUDED_lime_ui_Window
#include <lime/ui/Window.h>
#endif
#ifndef INCLUDED_lime_utils_Assets
#include <lime/utils/Assets.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_e47a9afac0942eb9_9_new,"Main","new",0x6616a5cb,"Main.new","Main.hx",9,0x087e5c05)
HX_LOCAL_STACK_FRAME(_hx_pos_e47a9afac0942eb9_21___onCreateWindow,"Main","__onCreateWindow",0x10dea2a0,"Main.__onCreateWindow","Main.hx",21,0x087e5c05)
HX_LOCAL_STACK_FRAME(_hx_pos_e47a9afac0942eb9_26_onPreloadComplete,"Main","onPreloadComplete",0x32b691ee,"Main.onPreloadComplete","Main.hx",26,0x087e5c05)
HX_LOCAL_STACK_FRAME(_hx_pos_e47a9afac0942eb9_35_render,"Main","render",0x35d38acb,"Main.render","Main.hx",35,0x087e5c05)

void Main_obj::__construct(){
            	HX_STACKFRAME(&_hx_pos_e47a9afac0942eb9_9_new)
HXLINE(  13)		this->start = false;
HXLINE(  16)		super::__construct();
HXLINE(  18)		this->onCreateWindow->add(this->_hx___onCreateWindow_dyn(),null(),null());
            	}

Dynamic Main_obj::__CreateEmpty() { return new Main_obj; }

void *Main_obj::_hx_vtable = 0;

Dynamic Main_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< Main_obj > _hx_result = new Main_obj();
	_hx_result->__construct();
	return _hx_result;
}

bool Main_obj::_hx_isInstanceOf(int inClassId) {
	if (inClassId<=(int)0x431bf104) {
		if (inClassId<=(int)0x07825a7d) {
			return inClassId==(int)0x00000001 || inClassId==(int)0x07825a7d;
		} else {
			return inClassId==(int)0x431bf104;
		}
	} else {
		return inClassId==(int)0x7f8386d8;
	}
}

void Main_obj::_hx___onCreateWindow( ::lime::ui::Window window){
            	HX_GC_STACKFRAME(&_hx_pos_e47a9afac0942eb9_21___onCreateWindow)
HXLINE(  22)		this->shader =  ::Shader_obj::__alloc( HX_CTX ,window,window->context,HX_("",00,00,00,00),HX_("",00,00,00,00));
HXLINE(  23)		this->canvas =  ::Canvas_obj::__alloc( HX_CTX ,window->context->webgl);
            	}


HX_DEFINE_DYNAMIC_FUNC1(Main_obj,_hx___onCreateWindow,(void))

void Main_obj::onPreloadComplete(){
            	HX_STACKFRAME(&_hx_pos_e47a9afac0942eb9_26_onPreloadComplete)
HXLINE(  27)		 ::Shader _hx_tmp = this->shader;
HXDLIN(  27)		_hx_tmp->includeVertexShader(::lime::utils::Assets_obj::getText(HX_("shaders/vertex.glsl",27,ca,a2,4c)));
HXLINE(  28)		 ::Shader _hx_tmp1 = this->shader;
HXDLIN(  28)		_hx_tmp1->includeFragmentShader(::lime::utils::Assets_obj::getText(HX_("shaders/fragment.glsl",fb,73,b2,b0)));
HXLINE(  30)		this->shader->includeFragmentShader(HX_("uniform vec2 iResolution;\nuniform float iTime;",a3,2e,7c,77));
HXLINE(  31)		this->shader->compile();
HXLINE(  32)		this->start = true;
            	}


void Main_obj::render( ::lime::graphics::RenderContext context){
            	HX_STACKFRAME(&_hx_pos_e47a9afac0942eb9_35_render)
HXLINE(  36)		if (!(this->start)) {
HXLINE(  37)			return;
            		}
HXLINE(  40)		 ::lime::_internal::backend::native::NativeOpenGLRenderContext gl = context->webgl;
HXLINE(  42)		int scaledWidth = ::Std_obj::_hx_int((( (Float)(this->_hx___window->_hx___width) ) * this->_hx___window->_hx___scale));
HXLINE(  43)		int scaledHeight = ::Std_obj::_hx_int((( (Float)(this->_hx___window->_hx___height) ) * this->_hx___window->_hx___scale));
HXLINE(  45)		gl->viewport(0,0,scaledWidth,scaledHeight);
HXLINE(  47)		gl->clearColor(( (Float)(0) ),( (Float)(0) ),( (Float)(0) ),( (Float)(1) ));
HXLINE(  48)		gl->clear(gl->COLOR_BUFFER_BIT);
HXLINE(  50)		this->shader->bind();
HXLINE(  51)		this->canvas->bind(this->shader);
HXLINE(  55)		{
HXLINE(  55)			 ::lime::graphics::opengl::GLObject buffer = null();
HXDLIN(  55)			gl->bindBuffer(gl->ARRAY_BUFFER,buffer);
            		}
HXLINE(  56)		{
HXLINE(  56)			 ::lime::graphics::opengl::GLObject program = null();
HXDLIN(  56)			gl->useProgram(program);
            		}
            	}



::hx::ObjectPtr< Main_obj > Main_obj::__new() {
	::hx::ObjectPtr< Main_obj > __this = new Main_obj();
	__this->__construct();
	return __this;
}

::hx::ObjectPtr< Main_obj > Main_obj::__alloc(::hx::Ctx *_hx_ctx) {
	Main_obj *__this = (Main_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(Main_obj), true, "Main"));
	*(void **)__this = Main_obj::_hx_vtable;
	__this->__construct();
	return __this;
}

Main_obj::Main_obj()
{
}

void Main_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Main);
	HX_MARK_MEMBER_NAME(shader,"shader");
	HX_MARK_MEMBER_NAME(canvas,"canvas");
	HX_MARK_MEMBER_NAME(start,"start");
	 ::lime::app::Application_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Main_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(shader,"shader");
	HX_VISIT_MEMBER_NAME(canvas,"canvas");
	HX_VISIT_MEMBER_NAME(start,"start");
	 ::lime::app::Application_obj::__Visit(HX_VISIT_ARG);
}

::hx::Val Main_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"start") ) { return ::hx::Val( start ); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"shader") ) { return ::hx::Val( shader ); }
		if (HX_FIELD_EQ(inName,"canvas") ) { return ::hx::Val( canvas ); }
		if (HX_FIELD_EQ(inName,"render") ) { return ::hx::Val( render_dyn() ); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"__onCreateWindow") ) { return ::hx::Val( _hx___onCreateWindow_dyn() ); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"onPreloadComplete") ) { return ::hx::Val( onPreloadComplete_dyn() ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val Main_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"start") ) { start=inValue.Cast< bool >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"shader") ) { shader=inValue.Cast<  ::Shader >(); return inValue; }
		if (HX_FIELD_EQ(inName,"canvas") ) { canvas=inValue.Cast<  ::Canvas >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Main_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("shader",25,bf,20,1d));
	outFields->push(HX_("canvas",d8,54,42,b8));
	outFields->push(HX_("start",62,74,0b,84));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo Main_obj_sMemberStorageInfo[] = {
	{::hx::fsObject /*  ::Shader */ ,(int)offsetof(Main_obj,shader),HX_("shader",25,bf,20,1d)},
	{::hx::fsObject /*  ::Canvas */ ,(int)offsetof(Main_obj,canvas),HX_("canvas",d8,54,42,b8)},
	{::hx::fsBool,(int)offsetof(Main_obj,start),HX_("start",62,74,0b,84)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *Main_obj_sStaticStorageInfo = 0;
#endif

static ::String Main_obj_sMemberFields[] = {
	HX_("shader",25,bf,20,1d),
	HX_("canvas",d8,54,42,b8),
	HX_("start",62,74,0b,84),
	HX_("__onCreateWindow",eb,be,10,d3),
	HX_("onPreloadComplete",43,37,5d,5c),
	HX_("render",56,6b,29,05),
	::String(null()) };

::hx::Class Main_obj::__mClass;

void Main_obj::__register()
{
	Main_obj _hx_dummy;
	Main_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("Main",59,64,2f,33);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(Main_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< Main_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = Main_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = Main_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

