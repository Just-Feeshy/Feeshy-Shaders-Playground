package;

import lime.graphics.Image;
import lime.graphics.opengl.GLTexture;
import lime.utils.AssetLibrary;
import lime.graphics.WebGLRenderContext;
import lime.math.Vector2;
import lime.graphics.opengl.GL;

class Texture {
    public var texture(default, null):GLTexture;
    public var image(default, null):Image;

    private var gl:WebGLRenderContext;
    private var width:Int;
    private var height:Int;

    public function new(gl:WebGLRenderContext, image:Image) {
        this.gl = gl;

        #if desktop
        gl.enable(gl.TEXTURE_2D);
        #end

        this.width = image.width;
        this.height = image.height;

        this.texture = gl.createTexture();
        gl.bindTexture(gl.TEXTURE_2D, this.texture);

        gl.texParameteri(GL.TEXTURE_2D, GL.TEXTURE_WRAP_S, GL.CLAMP_TO_EDGE);
        gl.texParameteri(GL.TEXTURE_2D, GL.TEXTURE_WRAP_T, GL.CLAMP_TO_EDGE);
        gl.texParameteri(GL.TEXTURE_2D, GL.TEXTURE_MIN_FILTER, GL.LINEAR);
        gl.texParameteri(GL.TEXTURE_2D, GL.TEXTURE_MAG_FILTER, GL.LINEAR);

        #if js
        gl.texImage2D(gl.TEXTURE_2D, 0, gl.RGBA, gl.RGBA, gl.UNSIGNED_BYTE, image.src);
        #else
        gl.texImage2D(gl.TEXTURE_2D, 0, gl.RGBA, image.buffer.width, image.buffer.height, 0, gl.RGBA, gl.UNSIGNED_BYTE, image.data);
        #end

        this.image = image;
    }

    public function bind(unit:Int):Void {
        gl.activeTexture(GL.TEXTURE0 + unit);
        gl.bindTexture(GL.TEXTURE_2D, texture);
    }
}