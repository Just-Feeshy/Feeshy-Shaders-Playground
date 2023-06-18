package;

import haxe.io.Bytes;
import lime.utils.AssetBundle;
import lime.utils.AssetLibrary;
import lime.utils.AssetManifest;
import lime.utils.Assets;

#if sys
import sys.FileSystem;
#end

#if disable_preloader_assets
@:dox(hide) class ManifestResources {
	public static var preloadLibraries:Array<Dynamic>;
	public static var preloadLibraryNames:Array<String>;
	public static var rootPath:String;

	public static function init (config:Dynamic):Void {
		preloadLibraries = new Array ();
		preloadLibraryNames = new Array ();
	}
}
#else
@:access(lime.utils.Assets)


@:keep @:dox(hide) class ManifestResources {


	public static var preloadLibraries:Array<AssetLibrary>;
	public static var preloadLibraryNames:Array<String>;
	public static var rootPath:String;


	public static function init (config:Dynamic):Void {

		preloadLibraries = new Array ();
		preloadLibraryNames = new Array ();

		rootPath = null;

		if (config != null && Reflect.hasField (config, "rootPath")) {

			rootPath = Reflect.field (config, "rootPath");

			if(!StringTools.endsWith (rootPath, "/")) {

				rootPath += "/";

			}

		}

		if (rootPath == null) {

			#if (ios || tvos || emscripten)
			rootPath = "assets/";
			#elseif android
			rootPath = "";
			#elseif console
			rootPath = lime.system.System.applicationDirectory;
			#else
			rootPath = "./";
			#end

		}

		#if (openfl && !flash && !display)
		
		#end

		var data, manifest, library, bundle;

		#if kha

		null
		library = AssetLibrary.fromManifest (manifest);
		Assets.registerLibrary ("null", library);

		if (library != null) preloadLibraries.push (library);
		else preloadLibraryNames.push ("null");

		#else

		data = '{"name":null,"assets":"aoy4:pathy28:shaders%2Flayout%2Fmain.glsly4:sizei99y4:typey4:TEXTy2:idR1y7:preloadtgoR0y23:shaders%2Ffragment.glslR2i65R3R4R5R7R6tgoR0y21:shaders%2Fvertex.glslR2i85R3R4R5R8R6tgoR0y18:assets%2Fhello.txtR2i7R3R4R5R9R6tgh","rootPath":null,"version":2,"libraryArgs":[],"libraryType":null}';
		manifest = AssetManifest.parse (data, rootPath);
		library = AssetLibrary.fromManifest (manifest);
		Assets.registerLibrary ("default", library);
		

		library = Assets.getLibrary ("default");
		if (library != null) preloadLibraries.push (library);
		else preloadLibraryNames.push ("default");
		

		#end

	}


}


#if kha

null

#else

#if !display
#if flash

@:keep @:bind @:noCompletion #if display private #end class __ASSET__shaders_layout_main_glsl extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__shaders_fragment_glsl extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__shaders_vertex_glsl extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__assets_hello_txt extends null { }
@:keep @:bind @:noCompletion #if display private #end class __ASSET__manifest_default_json extends null { }


#elseif (desktop || cpp)

@:keep @:file("shaders/layout/main.glsl") @:noCompletion #if display private #end class __ASSET__shaders_layout_main_glsl extends haxe.io.Bytes {}
@:keep @:file("shaders/fragment.glsl") @:noCompletion #if display private #end class __ASSET__shaders_fragment_glsl extends haxe.io.Bytes {}
@:keep @:file("shaders/vertex.glsl") @:noCompletion #if display private #end class __ASSET__shaders_vertex_glsl extends haxe.io.Bytes {}
@:keep @:file("assets/hello.txt") @:noCompletion #if display private #end class __ASSET__assets_hello_txt extends haxe.io.Bytes {}
@:keep @:file("") @:noCompletion #if display private #end class __ASSET__manifest_default_json extends haxe.io.Bytes {}



#else



#end

#if (openfl && !flash)

#if html5

#else

#end

#end
#end

#end

#end