mat2 rotateMatrix(float angle) {
    return mat2(cos(angle), -sin(angle), sin(angle), cos(angle));
}

float lineUp(float d, float thickness) {
    d -= 0.5;
    d = abs(d);
    d = step(0.01 * thickness, d);

    return d;
}

vec4 head(vec2 uv, vec2 offset, float angle, float size) {
    mat2 rotate2D = rotateMatrix(angle);

    // Conics Shapes
    vec2 coord = (uv * rotate2D) - offset;
    vec2 ellipse = coord / (vec2(0.45, 0.95) * size);
    float parabola = 3.0 * ((uv.y) * (uv.y)) - 6.0 * 0.45 * uv.y + 3.0 * (offset.y * offset.y) + 0.45;
    
    float d = lineUp(length(ellipse), 1.0);
    float d1 = parabola - uv.x;
    d1 = lineUp(d1, size);

    // Compute ellipse color
    vec3 colorEllipse = d < 1.0 ? vec3(1.0) : vec3(0.0, 0.0, 0.0);
    colorEllipse = coord.x < 0.0 ? colorEllipse : vec3(0.0, 0.0, 0.0);

    // Compute parabola color
    vec3 colorParabola = d1 < 1.0 ? vec3(1.0) : vec3(0.0, 0.0, 0.0);
    vec3 color = colorEllipse + colorParabola;
    return vec4(color, 1.0);
}

void mainImage(out vec4 fragColor, in vec2 fragCoord) {
    vec2 uv = (fragCoord.xy * 2.0 - iResolution.xy) / min(iResolution.x, iResolution.y);
    fragColor = head(uv, vec2(0.0, 0.0), -1.71, 0.5);
}

void main(void) {
    mainImage(gl_FragColor, gl_FragCoord.xy);
}