package;

import lime.graphics.opengl.GLShader;
import lime.graphics.RenderContext;
import lime.graphics.opengl.GLProgram;
import lime.graphics.opengl.GLUniformLocation;
import lime.graphics.opengl.GLShader;
import lime.graphics.WebGLRenderContext;
import lime.system.System;
import lime.ui.Window;

using StringTools;

/*
* Incredibly simple shader class
*/

class Shader {

    public var glVertexAttribute(default, null):Int;
    public var fragmentSource(default, null):String = "";
    public var vertexSource(default, null):String = "";

    private var window:Window;
    private var glProgram:GLProgram;
    private var gl:WebGLRenderContext;
    private var resolutionLocation:GLUniformLocation;
    private var timeLocation:GLUniformLocation;

    #if !desktop
    private static var webFragment = "precision mediump float;\n";
    #else
    private static var webFragment = "";
    #end

    public function new(window:Window, context:RenderContext, vertex:String, fragment:String) {
        this.window = window;

        gl = context.webgl;

        fragmentSource = fragment;
        vertexSource = vertex;
    }

    public function bind():Void {
        var scaledWidth = Std.int(window.width * window.scale);
        var scaledHeight = Std.int(window.height * window.scale);

        gl.uniform2f(resolutionLocation, scaledWidth, scaledHeight);
        gl.uniform1f(timeLocation, System.getTimer() * 0.001);
        gl.enableVertexAttribArray(glVertexAttribute);
        gl.useProgram(glProgram);
    }

    public function includeFragmentShader(source:String):Void {
        fragmentSource = source + "\n\n" + fragmentSource;
        fragmentSource.trim();
    }

    public function includeVertexShader(source:String):Void {
        vertexSource = source + "\n\n" + vertexSource;
        vertexSource.trim();
    }

    public function compile():Void {
        var vertexShader = createShader(gl, gl.VERTEX_SHADER, vertexSource);
        var fragmentShader = createShader(gl, gl.FRAGMENT_SHADER, webFragment + fragmentSource);

        glProgram = gl.createProgram();
        gl.attachShader(glProgram, vertexShader);
        gl.attachShader(glProgram, fragmentShader);
        gl.linkProgram(glProgram);

        resolutionLocation = gl.getUniformLocation(glProgram, "iResolution");
        timeLocation = gl.getUniformLocation(glProgram, "iTime");

        glVertexAttribute = gl.getAttribLocation(glProgram, "a_position");
    }

    private function createShader(gl:WebGLRenderContext, type:Int, source:String):GLShader {
        var shader = gl.createShader(type);
        gl.shaderSource(shader, source);
        gl.compileShader(shader);

        if (!gl.getShaderParameter(shader, gl.COMPILE_STATUS)) {
            throw 'An error occurred compiling the shaders: ' + gl.getShaderInfoLog(shader);
        }

        return shader;
    }
}