#ifndef INCLUDED_Canvas
#define INCLUDED_Canvas

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(Canvas)
HX_DECLARE_CLASS0(Shader)
HX_DECLARE_CLASS4(lime,_internal,backend,native,NativeOpenGLRenderContext)
HX_DECLARE_CLASS3(lime,graphics,opengl,GLObject)
HX_DECLARE_CLASS2(lime,utils,ArrayBufferView)



class HXCPP_CLASS_ATTRIBUTES Canvas_obj : public ::hx::Object
{
	public:
		typedef ::hx::Object super;
		typedef Canvas_obj OBJ_;
		Canvas_obj();

	public:
		enum { _hx_ClassId = 0x4e218bb8 };

		void __construct( ::lime::_internal::backend::native::NativeOpenGLRenderContext gl);
		inline void *operator new(size_t inSize, bool inContainer=true,const char *inName="Canvas")
			{ return ::hx::Object::operator new(inSize,inContainer,inName); }
		inline void *operator new(size_t inSize, int extra)
			{ return ::hx::Object::operator new(inSize+extra,true,"Canvas"); }
		static ::hx::ObjectPtr< Canvas_obj > __new( ::lime::_internal::backend::native::NativeOpenGLRenderContext gl);
		static ::hx::ObjectPtr< Canvas_obj > __alloc(::hx::Ctx *_hx_ctx, ::lime::_internal::backend::native::NativeOpenGLRenderContext gl);
		static void * _hx_vtable;
		static Dynamic __CreateEmpty();
		static Dynamic __Create(::hx::DynamicArray inArgs);
		//~Canvas_obj();

		HX_DO_RTTI_ALL;
		::hx::Val __Field(const ::String &inString, ::hx::PropertyAccess inCallProp);
		::hx::Val __SetField(const ::String &inString,const ::hx::Val &inValue, ::hx::PropertyAccess inCallProp);
		void __GetFields(Array< ::String> &outFields);
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		bool _hx_isInstanceOf(int inClassId);
		::String __ToString() const { return HX_("Canvas",f8,c8,d6,ec); }

		 ::lime::utils::ArrayBufferView data;
		 ::lime::utils::ArrayBufferView indices;
		 ::lime::graphics::opengl::GLObject vertexBuffer;
		 ::lime::graphics::opengl::GLObject indexBuffer;
		 ::lime::_internal::backend::native::NativeOpenGLRenderContext gl;
		void bind( ::Shader shader);
		::Dynamic bind_dyn();

};


#endif /* INCLUDED_Canvas */ 
