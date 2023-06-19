mat2 rotateMatrix(float angle) {
    return mat2(cos(angle), -sin(angle), sin(angle), cos(angle));
}

vec4 head(vec2 uv, vec2 offset, float angle) {
    mat2 rotate2D = rotateMatrix(angle);

    vec2 ellipse = ((uv * rotate2D) - offset) / vec2(0.2, 0.1);
    float d = abs(length(ellipse));
    vec3 color = d < 1.0 ? vec3(1.0) : vec3(1.0, 0.0, 0.0);
    return vec4(color, 1.0);
}

void mainImage(out vec4 fragColor, in vec2 fragCoord) {
    vec2 uv = fragCoord.xy / iResolution.xy;
    fragColor = head(uv, vec2(0.0, 0.0), iTime);
}

void main(void) {
    mainImage(gl_FragColor, gl_FragCoord.xy);
}