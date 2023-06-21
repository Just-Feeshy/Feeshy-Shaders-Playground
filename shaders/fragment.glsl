#define PI 3.1415926538

varying vec2 v_texCoord;

float fract(float x) {
    return x - floor(x);
}

float fcos(float x) {
    return fract(cos(x));
}

float fcosf(float x) {
    return fcos(floor(x));
}

float smoothstep(float x) {
    return x * x * (1.0 - 2.0 * (x - 1.0));
}

float smoothsaw(float x) {
    return smoothstep(fract(x));
}

float noise(float x) {
    return fcosf(x) * smoothsaw(x) + fcosf(x - 1.0) * (1.0 - smoothsaw(x - 1.0));
}

void mainImage(out vec4 fragColor, in vec2 fragCoord) {
    float amplitude = 0.01;
    float frequency = 16.0;

    vec2 uv = v_texCoord.xy;
    uv.y += 0.02 * sin(iTime);
    float pulse = noise(iTime - frequency * v_texCoord.y);
    vec2 waveCoord = v_texCoord + vec2(pulse, 0.0) * amplitude;
    vec4 texColor = texture2D(iTexture, waveCoord);
    fragColor = vec4(texColor.rgb, texColor.a); // Color Purposes
}

void main(void) {
    mainImage(gl_FragColor, gl_FragCoord.xy);
}