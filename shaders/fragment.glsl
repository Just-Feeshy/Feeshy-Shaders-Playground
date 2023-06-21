#define PI 3.1415926538

varying vec2 v_texCoord;

float fcos(float x) {
    return fract(cos(x));
}

float fcosf(float x) {
    return fcos(floor(x));
}

float fsin(float x) {
    return fract(sin(x));
}

float fsinf(float x) {
    return fsin(floor(x));
}

float smoothstep(float x) {
    return x * x * (1.0 - 2.0 * (x - 1.0));
}

float smoothsaw(float x) {
    return smoothstep(fract(x));
}

float noiseX(float x) {
    return fcosf(x) * smoothsaw(x) + fcosf(x - 1.0) * (1.0 - smoothsaw(x - 1.0));
}

float noiseY(float x) {
    return fsinf(x) * smoothsaw(x) + fsinf(x - 1.0) * (1.0 - smoothsaw(x - 1.0));
}

void mainImage(out vec4 fragColor, in vec2 fragCoord) {
    float amplitude = 0.01;
    float frequency = 16.0;

    vec2 uv = v_texCoord.xy;
    uv.y += 0.01 * sin(iTime);
    float pulse = noiseX(iTime - frequency * uv.y);
    float ripple = noiseY(iTime - frequency * uv.y);

    float d = length(vec2(pulse, uv.x + ripple * 0.6));
    d = abs(d);
    d = 1.0 / d;

    vec2 waveCoord = uv + vec2(pulse, 0.0) * amplitude;
    vec4 texColor = texture2D(iTexture, waveCoord);
    texColor *= vec4(0.5686, 0.1647, 1.0, 1.0) * 1.75;
    texColor *= vec4(d, d * 1.25, d * 1.25, 1.0);
    
    fragColor = vec4(texColor.rgb, texColor.a); // Color Purposes
}

void main(void) {
    mainImage(gl_FragColor, gl_FragCoord.xy);
}