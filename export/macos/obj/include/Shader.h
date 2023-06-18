#ifndef INCLUDED_Shader
#define INCLUDED_Shader

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(Shader)
HX_DECLARE_CLASS4(lime,_internal,backend,native,NativeOpenGLRenderContext)
HX_DECLARE_CLASS2(lime,graphics,RenderContext)
HX_DECLARE_CLASS3(lime,graphics,opengl,GLObject)
HX_DECLARE_CLASS2(lime,ui,Window)



class HXCPP_CLASS_ATTRIBUTES Shader_obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef Shader_obj OBJ_;
		Shader_obj();

	public:
		enum { _hx_ClassId = 0x194cfa69 };

		void __construct( ::lime::ui::Window window, ::lime::graphics::RenderContext context,::String vertex,::String fragment);
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="Shader")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"Shader"); }
		static ::hx::ObjectPtr< Shader_obj > __new( ::lime::ui::Window window, ::lime::graphics::RenderContext context,::String vertex,::String fragment);
		static ::hx::ObjectPtr< Shader_obj > __alloc(::hx::Ctx *_hx_ctx, ::lime::ui::Window window, ::lime::graphics::RenderContext context,::String vertex,::String fragment);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~Shader_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		static bool __GetStatic(const ::String &inString, Dynamic &outValue, ::hx::PropertyAccess inCallProp);
		::hx::Val __SetField(const ::String &inString,const ::hx::Val &inValue, ::hx::PropertyAccess inCallProp);
		static bool __SetStatic(const ::String &inString, Dynamic &ioValue, ::hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("Shader",45,33,b5,51); }

		static void __boot();
		static ::String webFragment;
		int glVertexAttribute;
		::String fragmentSource;
		::String vertexSource;
		 ::lime::ui::Window window;
		 ::lime::graphics::opengl::GLObject glProgram;
		 ::lime::_internal::backend::native::NativeOpenGLRenderContext gl;
		int resolutionLocation;
		int timeLocation;
		void bind();
		::Dynamic bind_dyn();

		void includeFragmentShader(::String source);
		::Dynamic includeFragmentShader_dyn();

		void includeVertexShader(::String source);
		::Dynamic includeVertexShader_dyn();

		void compile();
		::Dynamic compile_dyn();

		 ::lime::graphics::opengl::GLObject createShader( ::lime::_internal::backend::native::NativeOpenGLRenderContext gl,int type,::String source);
		::Dynamic createShader_dyn();

};


#endif /* INCLUDED_Shader */ 
