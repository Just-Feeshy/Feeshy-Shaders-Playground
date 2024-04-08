package;

import lime.graphics.opengl.GLProgram;
import lime.graphics.WebGLRenderContext;
import lime.graphics.opengl.GLBuffer;
import lime.utils.Float32Array;
import lime.utils.Int16Array;

class Canvas implements IObject {
    public var data(default, null):Float32Array;
    public var indices(default, null):Int16Array;

    private var vertexBuffer:GLBuffer;
    private var texCoordBuffer:GLBuffer;
    private var indexBuffer:GLBuffer;
    private var gl:WebGLRenderContext;
    private var texture:Texture;

    public function new(gl:WebGLRenderContext, texture:Texture) {
        this.gl = gl;
	this.texture = texture;

        var vertices = [
            -1.0,  1.0,  // top left
            1.0,  1.0,  // top right
            1.0, -1.0,  // bottom right
            -1.0, -1.0   // bottom left
        ];

        var texCoords = [
            0.0, 0.0,  // top left
            1.0, 0.0,  // top right
            1.0, 1.0,  // bottom right
            0.0, 1.0   // bottom left
        ];

        var indices = [0, 1, 2, 0, 2, 3];

        data = new Float32Array(vertices);
        vertexBuffer = gl.createBuffer();

        gl.bindBuffer(gl.ARRAY_BUFFER, vertexBuffer);
        gl.bufferData(gl.ARRAY_BUFFER, data, gl.STATIC_DRAW);

        data = new Float32Array(texCoords);
        texCoordBuffer = gl.createBuffer();

        gl.bindBuffer(gl.ARRAY_BUFFER, texCoordBuffer);
        gl.bufferData(gl.ARRAY_BUFFER, data, gl.STATIC_DRAW);

        this.indices = new Int16Array(indices);
        indexBuffer = gl.createBuffer();

        gl.bindBuffer(gl.ELEMENT_ARRAY_BUFFER, indexBuffer);
        gl.bufferData(gl.ELEMENT_ARRAY_BUFFER, this.indices, gl.STATIC_DRAW);

	gl.activeTexture(gl.TEXTURE0);
    }

    public function bind(shader:Shader):Void {
        gl.bindBuffer(gl.ARRAY_BUFFER, vertexBuffer);
        gl.enableVertexAttribArray(shader.glVertexAttribute);
        gl.vertexAttribPointer(shader.glVertexAttribute, 2, gl.FLOAT, false, 2 * Float32Array.BYTES_PER_ELEMENT, 0);

        gl.bindBuffer(gl.ARRAY_BUFFER, texCoordBuffer);
        gl.enableVertexAttribArray(shader.glTextureAttribute);
        gl.vertexAttribPointer(shader.glTextureAttribute, 2, gl.FLOAT, false, 2 * Float32Array.BYTES_PER_ELEMENT, 0);

        gl.bindBuffer(gl.ELEMENT_ARRAY_BUFFER, indexBuffer);
        gl.drawElements(gl.TRIANGLES, indices.length, gl.UNSIGNED_SHORT, 0);
    }

    public function onPanel(index:Int):Void {
	gl.bindTexture(gl.TEXTURE_2D, texture.texture);
    }

    public function onUnPanel(index:Int):Void {
	gl.bindTexture(gl.TEXTURE_2D, null);
    }
}
