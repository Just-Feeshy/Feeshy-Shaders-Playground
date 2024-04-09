package;

import lime.ui.Window;
import lime.utils.Float32Array;
import lime.utils.Int16Array;
import lime.graphics.WebGLRenderContext;
import lime.graphics.opengl.GLBuffer;

class Hills implements IObject {
	public var vertices(default, null):Float32Array;
	public var indices(default, null):Int16Array;
	public var colors(default, null):Float32Array;

	private var vertexBuffer:GLBuffer;
	private var indexBuffer:GLBuffer;
	private var colorBuffer:GLBuffer;
	private var gl:WebGLRenderContext;
	private var window:Window;

	private var width:Float = 1;
	private var x:Float = -1;

	public var n:Int = 2048;

	public function new(gl:WebGLRenderContext, window:Window) {
		this.gl = gl;
		this.window = window;

		__makeTriangle();

		vertexBuffer = gl.createBuffer();
		gl.bindBuffer(gl.ARRAY_BUFFER, vertexBuffer);
		gl.bufferData(gl.ARRAY_BUFFER, vertices, gl.STATIC_DRAW);

		indexBuffer = gl.createBuffer();
		gl.bindBuffer(gl.ELEMENT_ARRAY_BUFFER, indexBuffer);
		gl.bufferData(gl.ELEMENT_ARRAY_BUFFER, indices, gl.STATIC_DRAW);

		colorBuffer = gl.createBuffer();
		gl.bindBuffer(gl.ARRAY_BUFFER, colorBuffer);
		gl.bufferData(gl.ARRAY_BUFFER, colors, gl.STATIC_DRAW);
	}

	public function bind(shader:Shader):Void {
		gl.bindBuffer(gl.ARRAY_BUFFER, vertexBuffer);
		gl.enableVertexAttribArray(shader.glVertexAttribute);
		gl.vertexAttribPointer(shader.glVertexAttribute, 3, gl.FLOAT, false, 3 * Float32Array.BYTES_PER_ELEMENT, 0);

		gl.bindBuffer(gl.ARRAY_BUFFER, colorBuffer);
		gl.enableVertexAttribArray(shader.glColorAttribute);
		gl.vertexAttribPointer(shader.glColorAttribute, 3, gl.FLOAT, false, 3 * Float32Array.BYTES_PER_ELEMENT, 0);

		gl.bindBuffer(gl.ELEMENT_ARRAY_BUFFER, indexBuffer);
		gl.drawElements(gl.TRIANGLES, indices.length, gl.UNSIGNED_SHORT, 0);
	}

	public function onPanel(index:Int):Void {
		gl.bindTexture(gl.TEXTURE_2D, null);
	}

	public function onUnPanel(index:Int):Void {
	}

	@:noCompletion private function __top_layer(x:Float):Float {
		return (Math.sin(x * Math.PI) + 1) / 2;
	}

	@:noCompletion private function __makeTriangle() {
		var x_d:Float = (width - x) / n;

		var vertices = [
			x, __top_layer(x), 0.0,
			x, -1.0, 0.0,
		];

		var indices = [];


		var pick_colors = [
			1.0, 0.0, 0.0,
			1.0, 0.0, 0.0,
			1.0, 0.0, 0.0,

			0.0, 1.0, 0.0,
			0.0, 1.0, 0.0,
			0.0, 1.0, 0.0,

			0.0, 0.0, 1.0,
			0.0, 0.0, 1.0,
			0.0, 0.0, 1.0,

			1.0, 1.0, 0.0,
			1.0, 1.0, 0.0,
			1.0, 1.0, 0.0,

			0.0, 1.0, 1.0,
			0.0, 1.0, 1.0,
			0.0, 1.0, 1.0,

			1.0, 0.0, 1.0,
			1.0, 0.0, 1.0,
			1.0, 0.0, 1.0
		];

		var colors = [];


		for(k in 1...(n + 1)) {
			var h = k - 1;

			// Top
			vertices.push(x + k * x_d); // x
			vertices.push(__top_layer(x + k * x_d)); // y
			vertices.push(0.0); // z

			// Bottom
			vertices.push(x + k * x_d);
			vertices.push(-1.0);
			vertices.push(0.0);

			// Indices
			indices.push(0 + 2 * h);
			indices.push(1 + 2 * h);
			indices.push(2 + 2 * h);

			indices.push(2 + 2 * h);
			indices.push(3 + 2 * h);
			indices.push(1 + 2 * h);
		}


		var p:Int = 0;

		for(k in 0...(n * 9)) {
			colors.push(pick_colors[p]);
			p = (p + 1) % pick_colors.length;
		}

		this.vertices = new Float32Array(vertices);
		this.indices = new Int16Array(indices);
		this.colors = new Float32Array(colors);
	}
}
