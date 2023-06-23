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
	private var shader:Shader;
	private var canvas:Canvas;
	private var texture:Texture;
	private var screenshot:Screenshot;
	private var viewport:Viewport;

	private var start:Bool = false;

	public function new() {
		super();

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

		shader = new Shader(window, window.context, "", "");
		canvas = new Canvas(window.context.webgl);
		screenshot = new Screenshot(viewport, window.context.webgl);

		window.onKeyDown.add(__onKeyDown.bind(window));
	}

	private function __onKeyDown(window:Window, keyCode:KeyCode, modifier:KeyModifier):Void {
		if(this.window == null || this.window != window) {
			return;
		}

		#if desktop
		if(keyCode == KeyCode.ESCAPE) {
			window.close();
		}
		#end

		if(keyCode == KeyCode.F) {
			screenshot.capture();
			screenshot.save();
		}
	}

	public override function onPreloadComplete():Void {
		shader.includeVertexShader(Assets.getText("shaders/vertex.glsl"));

		#if debug
		shader.includeFragmentShader(Assets.getText("shaders/debug/fragment.glsl"));
		#else
		shader.includeFragmentShader(Assets.getText("shaders/fragment.glsl"));
		#end

		shader.includeFragmentShader("uniform vec2 iResolution;\nuniform float iTime;\nuniform sampler2D iTexture;");
		shader.compile();

		texture = new Texture(window.context.webgl, Assets.getImage("assets/Feeshy.png"));

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

		shader.bind();
		canvas.bind(shader);
		texture.bind(0);
		shader.bindTexture(texture);
		shader.bindUniforms();

		#if desktop
		gl.bindBuffer(gl.ARRAY_BUFFER, null);
        gl.useProgram(null);
		#end


		// Checking for WebGL error after render

		#if webgl
        var error = gl.getError();

        if (error != gl.NO_ERROR) {
            Log.error('WebGL error: ' + error);
        }
		#end
	}
}