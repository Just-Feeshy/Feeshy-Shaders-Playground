#define PI 3.1415926538

varying vec2 v_texCoord;

void mainImage(out vec4 fragColor, in vec2 fragCoord) {
    vec2 uv = v_texCoord.xy;
    fragColor = texture2D(iTexture, uv + vec2(0.0, 0.02 * sin(iTime)));
}

void main(void) {
    mainImage(gl_FragColor, gl_FragCoord.xy);
}