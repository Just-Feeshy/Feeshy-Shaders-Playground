package;

import lime.graphics.opengl.GLBuffer;
import lime.graphics.WebGLRenderContext;

interface IObject {
	private var gl:WebGLRenderContext;
	private var vertexBuffer:GLBuffer;
	private var indexBuffer:GLBuffer;

	public function bind(shader:Shader):Void;
}
