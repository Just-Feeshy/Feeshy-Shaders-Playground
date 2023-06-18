package;

import lime.app.Application;
import lime.graphics.RenderContext;
import lime.ui.Window;
import lime.utils.Float32Array;
import lime.utils.Assets;

class Main extends Application {
	private var shader:Shader;
	private var canvas:Canvas;

	private var start:Bool = false;

	public function new() {
		super();

		this.onCreateWindow.add(__onCreateWindow);
	}

	private function __onCreateWindow(window:Window):Void {
		shader = new Shader(window, window.context, "", "");
		canvas = new Canvas(window.context.webgl);
	}

	public override function onPreloadComplete():Void {
		shader.includeVertexShader(Assets.getText("shaders/vertex.glsl"));
		shader.includeFragmentShader(Assets.getText("shaders/fragment.glsl"));
		//shader.includeFragmentShader(Assets.getText("shaders/layout/main.glsl"));
		shader.includeFragmentShader("uniform vec2 iResolution;\nuniform float iTime;");
		shader.compile();
		start = true;
	}

	public override function render(context:RenderContext):Void {
		if(!start) {
			return;
		}

		var gl = context.webgl;

		var scaledWidth = Std.int(window.width * window.scale);
		var scaledHeight = Std.int(window.height * window.scale);

		gl.viewport(0, 0, scaledWidth, scaledHeight);

		gl.clearColor(0, 0, 0, 1);
        gl.clear(gl.COLOR_BUFFER_BIT);

		shader.bind();
		canvas.bind(shader);

		gl.bindBuffer(gl.ARRAY_BUFFER, null);
        gl.useProgram(null);
	}
}
