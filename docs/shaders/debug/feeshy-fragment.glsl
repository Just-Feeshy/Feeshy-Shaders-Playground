varying vec2 v_texCoord;

void main() {
    vec2 uv = v_texCoord.xy;
    gl_FragColor = texture2D(iTexture, uv);
}