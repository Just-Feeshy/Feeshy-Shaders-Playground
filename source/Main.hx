package;

import lime.app.Application;
import lime.graphics.RenderContext;
import lime.ui.Window;
import lime.ui.KeyCode;
import lime.ui.KeyModifier;
import lime.utils.Float32Array;
import lime.utils.Assets;
import lime.utils.Log;

class Main extends Application {
	private var shaders:Array<Shader>;
	private var objects:Array<IObject>;

	private var shader:Shader;
	private var screenshot:Screenshot;
	private var viewport:Viewport;

	private var start:Bool = false;
	private var index:Int = 0;

	public function new() {
		super();

		this.shaders = new Array<Shader>();
		this.objects = new Array<IObject>();

		this.onCreateWindow.add(__onCreateWindow);
	}

	private function __onCreateWindow(window:Window):Void {
		var scaledWidth = Std.int(window.width * window.scale);
		var scaledHeight = Std.int(window.height * window.scale);

		viewport = {
			x: 0,
			y: 0,
			width: scaledWidth,
			height: scaledHeight
		};

		shaders[0] = new Shader(window, window.context, "", "");
		shaders[1] = new Shader(window, window.context, "", "");
		screenshot = new Screenshot(viewport, window.context.webgl);

		window.onKeyDown.add(__onKeyDown.bind(window));
	}

	private function __onKeyDown(window:Window, keyCode:KeyCode, modifier:KeyModifier):Void {
		if(this.window == null || this.window != window) {
			return;
		}

		switch(keyCode) {
			case KeyCode.L:
				index = (index + 1) % shaders.length;

			case KeyCode.H:
				index = (index - 1) % shaders.length;

			#if desktop
			case KeyCode.ESCAPE:
				window.close();

			case KeyCode.F:
				screenshot.capture();
				screenshot.save();
			#end
			default:
		}
	}

	private function changeObject():Void {
		for(object in objects) {
			if(object == objects[index]) {
				object.onPanel(index);
				continue;
			}

			object.onUnPanel(index);
		}
	}

	public override function onPreloadComplete():Void {
		for(shader in shaders) {
			shader.includeVertexShader(Assets.getText("shaders/vertex.glsl"));
		}

		#if debug
		shaders[0].includeFragmentShader(Assets.getText("shaders/debug/feeshy-fragment.glsl"));
		#else
		shaders[0].includeFragmentShader(Assets.getText("shaders/feeshy-fragment.glsl"));
		#end

		shaders[1].includeFragmentShader(Assets.getText("shaders/trap-fragment.glsl"));

		for(shader in shaders) {
			shader.includeFragmentShader("uniform vec2 iResolution;\nuniform float iTime;\nuniform sampler2D iTexture;");
			shader.compile();
		}

		var texture = new Texture(window.context.webgl, Assets.getImage("assets/Feeshy.png"));
		objects[0] = new Canvas(window.context.webgl, texture);
		objects[1] = new Hills(window.context.webgl, window);

		start = true;
	}

	public override function render(context:RenderContext):Void {
		if(!start) {
			return;
		}

		var gl = context.webgl;

		gl.viewport(viewport.x, viewport.y, viewport.width, viewport.height);
		gl.blendFunc(gl.SRC_ALPHA, gl.ONE_MINUS_SRC_ALPHA);
		gl.enable(gl.BLEND);

		gl.clearColor(0, 0, 0, 1);
        	gl.clear(gl.COLOR_BUFFER_BIT);

		#if desktop
		gl.bindBuffer(gl.ARRAY_BUFFER, null);
       		gl.useProgram(null);
		#end

		shaders[index].bind();
		objects[index].bind(shaders[index]);
		shaders[index].bindUniforms();

		// Checking for WebGL error after render

		#if webgl
		var error = gl.getError();

		if (error != gl.NO_ERROR) {
		    Log.error('WebGL error: ' + error);
		}
		#end
	}
}
