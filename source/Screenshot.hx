package;

import lime.ui.FileDialog;
import lime.graphics.opengl.GL;
import lime.graphics.WebGLRenderContext;
import lime.graphics.Image;
import lime.utils.BytePointer;
import lime.utils.Log;

import haxe.io.Bytes;
import haxe.io.BytesInput;
import haxe.io.BytesOutput;

import format.png.Tools;
import format.png.Writer;

class Screenshot {
    private var viewport:Viewport;
    private var gl:WebGLRenderContext;
    private var data:Bytes;

    public function new(viewport:Viewport, gl:WebGLRenderContext) {
        this.viewport = viewport;
        this.gl = gl;
    }

    public function capture():Void {
        try {
            data = Bytes.alloc(viewport.width * viewport.height * 3); //RGB
        }catch(e:Dynamic) {
            Log.error("Error allocating memory for screenshot!");
            return;
        }

        gl.pixelStorei(GL.PACK_ALIGNMENT, 1);
        gl.readPixels(viewport.x, viewport.y, viewport.width, viewport.height, GL.RGB, GL.UNSIGNED_BYTE, new BytePointer(data));

        flipY();
    }

    public function save():Void {
        var pngData = Tools.buildRGB(viewport.width, viewport.height, data);
        var bytesOutput = new BytesOutput();
        var writer = new Writer(bytesOutput);

        writer.write(pngData);
        new FileDialog().save(bytesOutput.getBytes(), "png", "screenshot" + ".png", null);
    }

    private function flipY():Void {
        var rowLength = viewport.width * 3;
        var temp:Bytes = Bytes.alloc(rowLength);

        for(y in 0...Std.int(viewport.height * 0.5)) {
            var top:Int = y * rowLength;
            var bottom:Int = (viewport.height - y - 1) * rowLength;

            // Copy the top row to the temporary buffer
            temp.blit(0, data, top, rowLength);

            // Copy the bottom row to the top row
            data.blit(top, data, bottom, rowLength);

            // Copy the temporary buffer (originally top row) to the bottom row
            data.blit(bottom, temp, 0, rowLength);
        }
    }
}