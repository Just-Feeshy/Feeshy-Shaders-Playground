#include <hxcpp.h>

#ifndef INCLUDED_Canvas
#include <Canvas.h>
#endif
#ifndef INCLUDED_Shader
#include <Shader.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_haxe_Exception
#include <haxe/Exception.h>
#endif
#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_lime__internal_backend_native_NativeOpenGLRenderContext
#include <lime/_internal/backend/native/NativeOpenGLRenderContext.h>
#endif
#ifndef INCLUDED_lime_graphics__WebGLRenderContext_WebGLRenderContext_Impl_
#include <lime/graphics/_WebGLRenderContext/WebGLRenderContext_Impl_.h>
#endif
#ifndef INCLUDED_lime_graphics_opengl_GLObject
#include <lime/graphics/opengl/GLObject.h>
#endif
#ifndef INCLUDED_lime_utils_ArrayBufferView
#include <lime/utils/ArrayBufferView.h>
#endif
#ifndef INCLUDED_lime_utils_TAError
#include <lime/utils/TAError.h>
#endif
#ifndef INCLUDED_lime_utils__DataPointer_DataPointer_Impl_
#include <lime/utils/_DataPointer/DataPointer_Impl_.h>
#endif

HX_DEFINE_STACK_FRAME(_hx_pos_753b2d2ef9b16561_17_new,"Canvas","new",0x1df645ea,"Canvas.new","Canvas.hx",17,0x13a664c6)
static const Float _hx_array_data_ecd6c8f8_1[] = {
	-1.0,1.0,1.0,1.0,1.0,-1.0,-1.0,-1.0,
};
static const int _hx_array_data_ecd6c8f8_2[] = {
	(int)0,(int)1,(int)2,(int)0,(int)2,(int)3,
};
HX_LOCAL_STACK_FRAME(_hx_pos_753b2d2ef9b16561_41_bind,"Canvas","bind",0x119b58f3,"Canvas.bind","Canvas.hx",41,0x13a664c6)

void Canvas_obj::__construct( ::lime::_internal::backend::native::NativeOpenGLRenderContext gl){
            	HX_GC_STACKFRAME(&_hx_pos_753b2d2ef9b16561_17_new)
HXLINE(  18)		this->gl = gl;
HXLINE(  20)		::Array< Float > vertices = ::Array_obj< Float >::fromData( _hx_array_data_ecd6c8f8_1,8);
HXLINE(  26)		::Array< int > indices = ::Array_obj< int >::fromData( _hx_array_data_ecd6c8f8_2,6);
HXLINE(  28)		 ::Dynamic elements = null();
HXDLIN(  28)		 ::haxe::io::Bytes buffer = null();
HXDLIN(  28)		 ::lime::utils::ArrayBufferView view = null();
HXDLIN(  28)		 ::Dynamic len = null();
HXDLIN(  28)		 ::lime::utils::ArrayBufferView this1;
HXDLIN(  28)		if (::hx::IsNotNull( elements )) {
HXLINE(  28)			this1 =  ::lime::utils::ArrayBufferView_obj::__alloc( HX_CTX ,elements,8);
            		}
            		else {
HXLINE(  28)			if (::hx::IsNotNull( vertices )) {
HXLINE(  28)				 ::lime::utils::ArrayBufferView _this =  ::lime::utils::ArrayBufferView_obj::__alloc( HX_CTX ,0,8);
HXDLIN(  28)				_this->byteOffset = 0;
HXDLIN(  28)				_this->length = vertices->length;
HXDLIN(  28)				_this->byteLength = (_this->length * _this->bytesPerElement);
HXDLIN(  28)				 ::haxe::io::Bytes this2 = ::haxe::io::Bytes_obj::alloc(_this->byteLength);
HXDLIN(  28)				_this->buffer = this2;
HXDLIN(  28)				_this->copyFromArray(vertices,null());
HXDLIN(  28)				this1 = _this;
            			}
            			else {
HXLINE(  28)				if (::hx::IsNotNull( view )) {
HXLINE(  28)					 ::lime::utils::ArrayBufferView _this =  ::lime::utils::ArrayBufferView_obj::__alloc( HX_CTX ,0,8);
HXDLIN(  28)					 ::haxe::io::Bytes srcData = view->buffer;
HXDLIN(  28)					int srcLength = view->length;
HXDLIN(  28)					int srcByteOffset = view->byteOffset;
HXDLIN(  28)					int srcElementSize = view->bytesPerElement;
HXDLIN(  28)					int elementSize = _this->bytesPerElement;
HXDLIN(  28)					if ((view->type == _this->type)) {
HXLINE(  28)						int srcLength = srcData->length;
HXDLIN(  28)						int cloneLength = (srcLength - srcByteOffset);
HXDLIN(  28)						 ::haxe::io::Bytes this1 = ::haxe::io::Bytes_obj::alloc(cloneLength);
HXDLIN(  28)						_this->buffer = this1;
HXDLIN(  28)						_this->buffer->blit(0,srcData,srcByteOffset,cloneLength);
            					}
            					else {
HXLINE(  28)						HX_STACK_DO_THROW(::haxe::Exception_obj::thrown(HX_("unimplemented",09,2f,74,b4)));
            					}
HXDLIN(  28)					_this->byteLength = (_this->bytesPerElement * srcLength);
HXDLIN(  28)					_this->byteOffset = 0;
HXDLIN(  28)					_this->length = srcLength;
HXDLIN(  28)					this1 = _this;
            				}
            				else {
HXLINE(  28)					if (::hx::IsNotNull( buffer )) {
HXLINE(  28)						 ::lime::utils::ArrayBufferView _this =  ::lime::utils::ArrayBufferView_obj::__alloc( HX_CTX ,0,8);
HXDLIN(  28)						int in_byteOffset = 0;
HXDLIN(  28)						if ((in_byteOffset < 0)) {
HXLINE(  28)							HX_STACK_DO_THROW(::haxe::Exception_obj::thrown(::lime::utils::TAError_obj::RangeError_dyn()));
            						}
HXDLIN(  28)						if ((::hx::Mod(in_byteOffset,_this->bytesPerElement) != 0)) {
HXLINE(  28)							HX_STACK_DO_THROW(::haxe::Exception_obj::thrown(::lime::utils::TAError_obj::RangeError_dyn()));
            						}
HXDLIN(  28)						int bufferByteLength = buffer->length;
HXDLIN(  28)						int elementSize = _this->bytesPerElement;
HXDLIN(  28)						int newByteLength = bufferByteLength;
HXDLIN(  28)						if (::hx::IsNull( len )) {
HXLINE(  28)							newByteLength = (bufferByteLength - in_byteOffset);
HXDLIN(  28)							if ((::hx::Mod(bufferByteLength,_this->bytesPerElement) != 0)) {
HXLINE(  28)								HX_STACK_DO_THROW(::haxe::Exception_obj::thrown(::lime::utils::TAError_obj::RangeError_dyn()));
            							}
HXDLIN(  28)							if ((newByteLength < 0)) {
HXLINE(  28)								HX_STACK_DO_THROW(::haxe::Exception_obj::thrown(::lime::utils::TAError_obj::RangeError_dyn()));
            							}
            						}
            						else {
HXLINE(  28)							newByteLength = (( (int)(len) ) * _this->bytesPerElement);
HXDLIN(  28)							int newRange = (in_byteOffset + newByteLength);
HXDLIN(  28)							if ((newRange > bufferByteLength)) {
HXLINE(  28)								HX_STACK_DO_THROW(::haxe::Exception_obj::thrown(::lime::utils::TAError_obj::RangeError_dyn()));
            							}
            						}
HXDLIN(  28)						_this->buffer = buffer;
HXDLIN(  28)						_this->byteOffset = in_byteOffset;
HXDLIN(  28)						_this->byteLength = newByteLength;
HXDLIN(  28)						_this->length = ::Std_obj::_hx_int((( (Float)(newByteLength) ) / ( (Float)(_this->bytesPerElement) )));
HXDLIN(  28)						this1 = _this;
            					}
            					else {
HXLINE(  28)						HX_STACK_DO_THROW(::haxe::Exception_obj::thrown(HX_("Invalid constructor arguments for Float32Array",8e,c1,f4,d4)));
            					}
            				}
            			}
            		}
HXDLIN(  28)		this->data = this1;
HXLINE(  29)		this->vertexBuffer = gl->createBuffer();
HXLINE(  31)		gl->bindBuffer(gl->ARRAY_BUFFER,this->vertexBuffer);
HXLINE(  32)		::lime::graphics::_WebGLRenderContext::WebGLRenderContext_Impl__obj::bufferData(gl,gl->ARRAY_BUFFER,this->data,gl->STATIC_DRAW);
HXLINE(  34)		 ::Dynamic elements1 = null();
HXDLIN(  34)		 ::haxe::io::Bytes buffer1 = null();
HXDLIN(  34)		 ::lime::utils::ArrayBufferView view1 = null();
HXDLIN(  34)		 ::Dynamic len1 = null();
HXDLIN(  34)		 ::lime::utils::ArrayBufferView this2;
HXDLIN(  34)		if (::hx::IsNotNull( elements1 )) {
HXLINE(  34)			this2 =  ::lime::utils::ArrayBufferView_obj::__alloc( HX_CTX ,elements1,2);
            		}
            		else {
HXLINE(  34)			if (::hx::IsNotNull( indices )) {
HXLINE(  34)				 ::lime::utils::ArrayBufferView _this =  ::lime::utils::ArrayBufferView_obj::__alloc( HX_CTX ,0,2);
HXDLIN(  34)				_this->byteOffset = 0;
HXDLIN(  34)				_this->length = indices->length;
HXDLIN(  34)				_this->byteLength = (_this->length * _this->bytesPerElement);
HXDLIN(  34)				 ::haxe::io::Bytes this1 = ::haxe::io::Bytes_obj::alloc(_this->byteLength);
HXDLIN(  34)				_this->buffer = this1;
HXDLIN(  34)				_this->copyFromArray(indices,null());
HXDLIN(  34)				this2 = _this;
            			}
            			else {
HXLINE(  34)				if (::hx::IsNotNull( view1 )) {
HXLINE(  34)					 ::lime::utils::ArrayBufferView _this =  ::lime::utils::ArrayBufferView_obj::__alloc( HX_CTX ,0,2);
HXDLIN(  34)					 ::haxe::io::Bytes srcData = view1->buffer;
HXDLIN(  34)					int srcLength = view1->length;
HXDLIN(  34)					int srcByteOffset = view1->byteOffset;
HXDLIN(  34)					int srcElementSize = view1->bytesPerElement;
HXDLIN(  34)					int elementSize = _this->bytesPerElement;
HXDLIN(  34)					if ((view1->type == _this->type)) {
HXLINE(  34)						int srcLength = srcData->length;
HXDLIN(  34)						int cloneLength = (srcLength - srcByteOffset);
HXDLIN(  34)						 ::haxe::io::Bytes this1 = ::haxe::io::Bytes_obj::alloc(cloneLength);
HXDLIN(  34)						_this->buffer = this1;
HXDLIN(  34)						_this->buffer->blit(0,srcData,srcByteOffset,cloneLength);
            					}
            					else {
HXLINE(  34)						HX_STACK_DO_THROW(::haxe::Exception_obj::thrown(HX_("unimplemented",09,2f,74,b4)));
            					}
HXDLIN(  34)					_this->byteLength = (_this->bytesPerElement * srcLength);
HXDLIN(  34)					_this->byteOffset = 0;
HXDLIN(  34)					_this->length = srcLength;
HXDLIN(  34)					this2 = _this;
            				}
            				else {
HXLINE(  34)					if (::hx::IsNotNull( buffer1 )) {
HXLINE(  34)						 ::lime::utils::ArrayBufferView _this =  ::lime::utils::ArrayBufferView_obj::__alloc( HX_CTX ,0,2);
HXDLIN(  34)						int in_byteOffset = 0;
HXDLIN(  34)						if ((in_byteOffset < 0)) {
HXLINE(  34)							HX_STACK_DO_THROW(::haxe::Exception_obj::thrown(::lime::utils::TAError_obj::RangeError_dyn()));
            						}
HXDLIN(  34)						if ((::hx::Mod(in_byteOffset,_this->bytesPerElement) != 0)) {
HXLINE(  34)							HX_STACK_DO_THROW(::haxe::Exception_obj::thrown(::lime::utils::TAError_obj::RangeError_dyn()));
            						}
HXDLIN(  34)						int bufferByteLength = buffer1->length;
HXDLIN(  34)						int elementSize = _this->bytesPerElement;
HXDLIN(  34)						int newByteLength = bufferByteLength;
HXDLIN(  34)						if (::hx::IsNull( len1 )) {
HXLINE(  34)							newByteLength = (bufferByteLength - in_byteOffset);
HXDLIN(  34)							if ((::hx::Mod(bufferByteLength,_this->bytesPerElement) != 0)) {
HXLINE(  34)								HX_STACK_DO_THROW(::haxe::Exception_obj::thrown(::lime::utils::TAError_obj::RangeError_dyn()));
            							}
HXDLIN(  34)							if ((newByteLength < 0)) {
HXLINE(  34)								HX_STACK_DO_THROW(::haxe::Exception_obj::thrown(::lime::utils::TAError_obj::RangeError_dyn()));
            							}
            						}
            						else {
HXLINE(  34)							newByteLength = (( (int)(len1) ) * _this->bytesPerElement);
HXDLIN(  34)							int newRange = (in_byteOffset + newByteLength);
HXDLIN(  34)							if ((newRange > bufferByteLength)) {
HXLINE(  34)								HX_STACK_DO_THROW(::haxe::Exception_obj::thrown(::lime::utils::TAError_obj::RangeError_dyn()));
            							}
            						}
HXDLIN(  34)						_this->buffer = buffer1;
HXDLIN(  34)						_this->byteOffset = in_byteOffset;
HXDLIN(  34)						_this->byteLength = newByteLength;
HXDLIN(  34)						_this->length = ::Std_obj::_hx_int((( (Float)(newByteLength) ) / ( (Float)(_this->bytesPerElement) )));
HXDLIN(  34)						this2 = _this;
            					}
            					else {
HXLINE(  34)						HX_STACK_DO_THROW(::haxe::Exception_obj::thrown(HX_("Invalid constructor arguments for Int16Array",95,b2,95,a7)));
            					}
            				}
            			}
            		}
HXDLIN(  34)		this->indices = this2;
HXLINE(  35)		this->indexBuffer = gl->createBuffer();
HXLINE(  37)		gl->bindBuffer(gl->ELEMENT_ARRAY_BUFFER,this->indexBuffer);
HXLINE(  38)		::lime::graphics::_WebGLRenderContext::WebGLRenderContext_Impl__obj::bufferData(gl,gl->ELEMENT_ARRAY_BUFFER,this->indices,gl->STATIC_DRAW);
            	}

Dynamic Canvas_obj::__CreateEmpty() { return new Canvas_obj; }

void *Canvas_obj::_hx_vtable = 0;

Dynamic Canvas_obj::__Create(::hx::DynamicArray inArgs)
{
	::hx::ObjectPtr< Canvas_obj > _hx_result = new Canvas_obj();
	_hx_result->__construct(inArgs[0]);
	return _hx_result;
}

bool Canvas_obj::_hx_isInstanceOf(int inClassId) {
	return inClassId==(int)0x00000001 || inClassId==(int)0x4e218bb8;
}

void Canvas_obj::bind( ::Shader shader){
            	HX_STACKFRAME(&_hx_pos_753b2d2ef9b16561_41_bind)
HXLINE(  42)		this->gl->bindBuffer(this->gl->ARRAY_BUFFER,this->vertexBuffer);
HXLINE(  43)		this->gl->bindBuffer(this->gl->ELEMENT_ARRAY_BUFFER,this->indexBuffer);
HXLINE(  45)		this->gl->enableVertexAttribArray(shader->glVertexAttribute);
HXLINE(  46)		{
HXLINE(  46)			 ::lime::_internal::backend::native::NativeOpenGLRenderContext this1 = this->gl;
HXDLIN(  46)			int indx = shader->glVertexAttribute;
HXDLIN(  46)			int type = this->gl->FLOAT;
HXDLIN(  46)			this1->vertexAttribPointer(indx,2,type,false,8,::lime::utils::_DataPointer::DataPointer_Impl__obj::fromInt(0));
            		}
HXLINE(  48)		{
HXLINE(  48)			 ::lime::_internal::backend::native::NativeOpenGLRenderContext this2 = this->gl;
HXDLIN(  48)			int mode = this->gl->TRIANGLES;
HXDLIN(  48)			int count = this->indices->length;
HXDLIN(  48)			int type1 = this->gl->UNSIGNED_SHORT;
HXDLIN(  48)			this2->drawElements(mode,count,type1,::lime::utils::_DataPointer::DataPointer_Impl__obj::fromInt(0));
            		}
            	}


HX_DEFINE_DYNAMIC_FUNC1(Canvas_obj,bind,(void))


::hx::ObjectPtr< Canvas_obj > Canvas_obj::__new( ::lime::_internal::backend::native::NativeOpenGLRenderContext gl) {
	::hx::ObjectPtr< Canvas_obj > __this = new Canvas_obj();
	__this->__construct(gl);
	return __this;
}

::hx::ObjectPtr< Canvas_obj > Canvas_obj::__alloc(::hx::Ctx *_hx_ctx, ::lime::_internal::backend::native::NativeOpenGLRenderContext gl) {
	Canvas_obj *__this = (Canvas_obj*)(::hx::Ctx::alloc(_hx_ctx, sizeof(Canvas_obj), true, "Canvas"));
	*(void **)__this = Canvas_obj::_hx_vtable;
	__this->__construct(gl);
	return __this;
}

Canvas_obj::Canvas_obj()
{
}

void Canvas_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Canvas);
	HX_MARK_MEMBER_NAME(data,"data");
	HX_MARK_MEMBER_NAME(indices,"indices");
	HX_MARK_MEMBER_NAME(vertexBuffer,"vertexBuffer");
	HX_MARK_MEMBER_NAME(indexBuffer,"indexBuffer");
	HX_MARK_MEMBER_NAME(gl,"gl");
	HX_MARK_END_CLASS();
}

void Canvas_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(data,"data");
	HX_VISIT_MEMBER_NAME(indices,"indices");
	HX_VISIT_MEMBER_NAME(vertexBuffer,"vertexBuffer");
	HX_VISIT_MEMBER_NAME(indexBuffer,"indexBuffer");
	HX_VISIT_MEMBER_NAME(gl,"gl");
}

::hx::Val Canvas_obj::__Field(const ::String &inName,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"gl") ) { return ::hx::Val( gl ); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"data") ) { return ::hx::Val( data ); }
		if (HX_FIELD_EQ(inName,"bind") ) { return ::hx::Val( bind_dyn() ); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"indices") ) { return ::hx::Val( indices ); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"indexBuffer") ) { return ::hx::Val( indexBuffer ); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"vertexBuffer") ) { return ::hx::Val( vertexBuffer ); }
	}
	return super::__Field(inName,inCallProp);
}

::hx::Val Canvas_obj::__SetField(const ::String &inName,const ::hx::Val &inValue,::hx::PropertyAccess inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"gl") ) { gl=inValue.Cast<  ::lime::_internal::backend::native::NativeOpenGLRenderContext >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"data") ) { data=inValue.Cast<  ::lime::utils::ArrayBufferView >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"indices") ) { indices=inValue.Cast<  ::lime::utils::ArrayBufferView >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"indexBuffer") ) { indexBuffer=inValue.Cast<  ::lime::graphics::opengl::GLObject >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"vertexBuffer") ) { vertexBuffer=inValue.Cast<  ::lime::graphics::opengl::GLObject >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Canvas_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_("data",2a,56,63,42));
	outFields->push(HX_("indices",27,47,54,e3));
	outFields->push(HX_("vertexBuffer",84,af,a9,70));
	outFields->push(HX_("indexBuffer",b2,65,a6,f5));
	outFields->push(HX_("gl",25,5a,00,00));
	super::__GetFields(outFields);
};

#ifdef HXCPP_SCRIPTABLE
static ::hx::StorageInfo Canvas_obj_sMemberStorageInfo[] = {
	{::hx::fsObject /*  ::lime::utils::ArrayBufferView */ ,(int)offsetof(Canvas_obj,data),HX_("data",2a,56,63,42)},
	{::hx::fsObject /*  ::lime::utils::ArrayBufferView */ ,(int)offsetof(Canvas_obj,indices),HX_("indices",27,47,54,e3)},
	{::hx::fsObject /*  ::lime::graphics::opengl::GLObject */ ,(int)offsetof(Canvas_obj,vertexBuffer),HX_("vertexBuffer",84,af,a9,70)},
	{::hx::fsObject /*  ::lime::graphics::opengl::GLObject */ ,(int)offsetof(Canvas_obj,indexBuffer),HX_("indexBuffer",b2,65,a6,f5)},
	{::hx::fsObject /*  ::lime::_internal::backend::native::NativeOpenGLRenderContext */ ,(int)offsetof(Canvas_obj,gl),HX_("gl",25,5a,00,00)},
	{ ::hx::fsUnknown, 0, null()}
};
static ::hx::StaticInfo *Canvas_obj_sStaticStorageInfo = 0;
#endif

static ::String Canvas_obj_sMemberFields[] = {
	HX_("data",2a,56,63,42),
	HX_("indices",27,47,54,e3),
	HX_("vertexBuffer",84,af,a9,70),
	HX_("indexBuffer",b2,65,a6,f5),
	HX_("gl",25,5a,00,00),
	HX_("bind",bd,f5,16,41),
	::String(null()) };

::hx::Class Canvas_obj::__mClass;

void Canvas_obj::__register()
{
	Canvas_obj _hx_dummy;
	Canvas_obj::_hx_vtable = *(void **)&_hx_dummy;
	::hx::Static(__mClass) = new ::hx::Class_obj();
	__mClass->mName = HX_("Canvas",f8,c8,d6,ec);
	__mClass->mSuper = &super::__SGetClass();
	__mClass->mConstructEmpty = &__CreateEmpty;
	__mClass->mConstructArgs = &__Create;
	__mClass->mGetStaticField = &::hx::Class_obj::GetNoStaticField;
	__mClass->mSetStaticField = &::hx::Class_obj::SetNoStaticField;
	__mClass->mStatics = ::hx::Class_obj::dupFunctions(0 /* sStaticFields */);
	__mClass->mMembers = ::hx::Class_obj::dupFunctions(Canvas_obj_sMemberFields);
	__mClass->mCanCast = ::hx::TCanCast< Canvas_obj >;
#ifdef HXCPP_SCRIPTABLE
	__mClass->mMemberStorageInfo = Canvas_obj_sMemberStorageInfo;
#endif
#ifdef HXCPP_SCRIPTABLE
	__mClass->mStaticStorageInfo = Canvas_obj_sStaticStorageInfo;
#endif
	::hx::_hx_RegisterClass(__mClass->mName, __mClass);
}

